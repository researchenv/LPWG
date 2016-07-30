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

#include "windowcontrol.h"
#include "../graphicswidget.h"
#include "../graphicitem.h"

WindowControl::WindowControl(const Control &control)
{
    this->control=control;

    CommandLineInput::ParametersType p;

    QString command;

    switch (control)
    {
    case WINDOW_UPDATE:
        //window_update
        command="window_update";
        break;
    case WINDOW_SET_COLOR:
        //window_set_color,color [color is uint ARGB]
        p.append(CommandLineInput::PARAMATER_TYPE_UINTEGER);
        command="window_set_color";
        break;
    case WINDOW_CLEAR:
        //window_clear
        command="window_clear";
        break;
    }

    commandLine = CommandLineInput(command,p);
}

WindowControl::~WindowControl()
{

}

void WindowControl::execCommand(GraphicsWidget *gw,
                         const Parameters &parameters)
{
    switch (control)
    {
    case WINDOW_UPDATE:
        gw->update();
        break;
    case WINDOW_SET_COLOR:
        gw->setStyleSheet("GraphicsWidget{background-color:"+
                          QString("#%1").arg(parameters.at(0).toUInt(),6, 16, QChar('0'))+
                          "}");
        break;
    case WINDOW_CLEAR:
        gw->removeAllItems();
        gw->update();
        break;
    }
}

const CommandLineInput &WindowControl::getCommandLine() const
{
    return commandLine;
}
