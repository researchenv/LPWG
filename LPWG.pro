# Copyright 2016 Erbe Pandini Rodrigues
#
# This file is a part of LPWG
#
# LPWG program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# LPWG program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#


#-------------------------------------------------
#
# Project created by QtCreator 2016-05-27T14:33:42
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lpwg
TEMPLATE = app

SOURCES += main.cpp\
    mainwindow.cpp \
    control.cpp \
    graphicitem.cpp \
    graphicswidget.cpp \
    command/command.cpp \
    command/commandlineinput.cpp \
    command/commandparser.cpp \
    controls/windowcontrol.cpp \
    controls/axiscontrol.cpp \
    controls/itemcreationcontrol.cpp \
    controls/itempropertiescontrol.cpp \
    controls/itemtransformcontrol.cpp \
    interfaces/controlinterface.cpp \
    items/ellipse.cpp \
    items/rectangle.cpp \
    items/line.cpp \
    stream/stdinstream.cpp \
    interfaces/abstractgraphicitem.cpp

HEADERS  += mainwindow.h \
    control.h \
    graphicitem.h \
    graphicswidget.h \
    command/command.h \
    command/commandparser.h \
    command/commandlineinput.h \
    controls/windowcontrol.h \
    controls/axiscontrol.h \
    controls/itemcreationcontrol.h \
    controls/itempropertiescontrol.h \
    controls/itemtransformcontrol.h \
    interfaces/controlinterface.h \
    interfaces/streaminterface.h \
    items/ellipse.h \
    items/rectangle.h \
    items/line.h \
    stream/stdinstream.h \
    interfaces/abstractgraphicitem.h

FORMS    += mainwindow.ui
