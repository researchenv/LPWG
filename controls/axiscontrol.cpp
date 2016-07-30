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

#include "axiscontrol.h"
#include "../graphicswidget.h"

AxisControl::AxisControl(const AxisControl::Axis &axis)
{
    this->axis=axis;

    CommandLineInput::ParametersType ax;
    QString command;

    switch (axis)
    {
    case AXIS_TRANSLATE:
        ax.append(CommandLineInput::PARAMATER_TYPE_INTEGER);
        ax.append(CommandLineInput::PARAMATER_TYPE_INTEGER);
        command="axis_translate";
        break;
    case AXIS_ROTATE:
        ax.append(CommandLineInput::PARAMATER_TYPE_FLOAT);
        command="axis_rotate";
        break;
    case AXIS_SET_VILIBLE:
        ax.append(CommandLineInput::PARAMATER_TYPE_INTEGER);
        command="axis_set_visible";
        break;
    case AXIS_RESET_TRANSFORM:
        command="axis_reset_transform";
        break;
    }

    commandLine = CommandLineInput(command,ax);
}

AxisControl::~AxisControl()
{

}

void AxisControl::execCommand(GraphicsWidget *gw, const Parameters &parameters)
{
    switch (axis) {
    case AXIS_TRANSLATE:
        //axis_translate,dx,dy
        gw->getTransform().translate(parameters.at(0).toInt(),parameters.at(1).toInt());
        break;
    case AXIS_ROTATE:
        //axis_rotate, angle  [angle is float in degrees]
        gw->getTransform().rotate(parameters.at(0).toFloat());
        break;
    case AXIS_SET_VILIBLE:
        //axis_set_visible,value [0=false, 1=true]
        gw->showAxis(parameters.at(0).toInt());
        break;
    case AXIS_RESET_TRANSFORM:
        //axis_reset_transform
        gw->getTransform().reset();
        break;
    }
}

const CommandLineInput &AxisControl::getCommandLine() const
{
    return commandLine;
}
