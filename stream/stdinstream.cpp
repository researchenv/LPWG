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

#include "stdinstream.h"
#include <QTextStream>
#include <QThread>
#include <QDebug>

StdinStream::StdinStream(QObject *parent) :
    StreamInterface(parent),
    isRunning(0)
{

}

StdinStream::~StdinStream()
{

}

void StdinStream::startStream()
{
    stream =  new QTextStream(stdin);
    isRunning = stream->device()->isOpen();
    if(isRunning)
    {
        emit(connectionStatus("listening to pipe.", isRunning));
        bool run=true;
        while(isRunning && run){
            //Pause this thread 10 microseconds to allow outside thread to stop it.
            QThread::usleep(10);
            QString s = stream->readLine();
            if(!s.isNull() && !s.isEmpty())
            {
                emit(nextCommand(s));
            }
            run = !stream->atEnd();
        }
    }
    else
    {
        emit(connectionStatus("Can't listen to pipe, connection error.", isRunning));
    }
    stream->device()->close();
    delete stream;
    emit(connectionStatus("Pipe transmission finished.", isRunning));

}


void StdinStream::stopStream()
{
    isRunning=false;
}

StdinStream &StdinStream::operator =(const StdinStream &){return *this;}
