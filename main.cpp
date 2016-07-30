/* LPWG - Learn Programming With Graphics
 *
 * Copyright 2016 Erbe Pandini Rodrigues
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * This software was developed using Qt5.3 library, which is under LPGL license.

 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "mainwindow.h"
#include <QApplication>
#include <QString>
#include <iostream>

void showHelp();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(argc>1)
    {
        QString arg;
        arg = a.arguments().at(1);

        if(arg.compare("-h")==0)
        {
            showHelp();
            exit(0);
        }
    }

    MainWindow w;
    w.show();

    return a.exec();
}

void showHelp()
{
    std::cout<<std::endl
             <<"LPWG - Learn programming with graphics."<<std::endl
             <<std::endl
             <<"Run:"<<std::endl
             <<" [program] | lpwg (listen to a pipe)"<<std::endl
             <<" lpwg -h (show this help)"<<std::endl
             <<std::endl
             <<"Examples:"<<std::endl
             <<" test | lpwg (the std output from test will be the std input to lpwg)"<<std::endl
             <<std::endl;
}
