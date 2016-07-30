/* Copyright 2016 Erbe Pandini Rodrigues
 *
 * This file is part of LPWG
 *
 * LPWG program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * LPWG program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <QString>
#include <QThread>
#include "control.h"
#include "interfaces/streaminterface.h"
#include "stream/stdinstream.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    thread(0),
    streamInterface(0)
{
    ui->setupUi(this);

    control = new Control(ui->graphicsWidget);
    if(control!=0)
    {
        setInputStream();
    } else {
        std::cerr<<"Allocation memory error. Aborting!";
        ui->label->setText("Error: can't start control.");
    }
}

MainWindow::~MainWindow()
{
    delete streamInterface;
    delete control;
    delete ui;
}

void MainWindow::setInputStream()
{
    streamInterface = new StdinStream(0);

    if(streamInterface!=0)
    {
        connect(this,
                SIGNAL(startStream()),
                streamInterface,
                SLOT(startStream())
                );

        connect(streamInterface,
                SIGNAL(nextCommand(QString)),
                this,
                SLOT(executeCommand(QString))
                );

        connect(streamInterface,
                SIGNAL(connectionStatus(QString,bool)),
                this,
                SLOT(setSatusMessage(QString))
                );

        thread = new QThread(this);

        if(thread!=0)
        {
            /*
             * Running streamInterface in another thread
             * to avoid GUI freezing.
             */
            streamInterface->moveToThread(thread);
            thread->start();

            emit(startStream());
        }
        else
        {
            ui->label->setText("Error: can't start stream thread.");
        }

    }
    else
    {
        ui->label->setText("Error: can't open stream.");
    }
}

void MainWindow::stopInputStream()
{
    streamInterface->stopStream();
    if(thread!=0){
        thread->quit();
        int c=0;
        //The stream thread has 1 second to finish before this program quit.
        while (thread->isRunning() && c++<10){
            QThread::msleep(100);
        }
    }
}

void MainWindow::executeCommand(const QString &strCommand)
{
    if(!control->executeCommand(strCommand))
    {
        if(strCommand.compare("lpwg_end_transmission")==0)
        {
            stopInputStream();
        }
        else if(strCommand.compare("lpwg_close_window")==0)
        {
            close();
        }
        else
        {
            ui->label->setText("Error - Ignoring command: "+strCommand);
        }
    }
}

void MainWindow::setSatusMessage(const QString &command)
{
    ui->label->setText(command);
}

void MainWindow::closeEvent(QCloseEvent *)
{
    stopInputStream();
}
