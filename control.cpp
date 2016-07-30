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

#include "control.h"
#include "graphicswidget.h"
#include "command/command.h"
#include "command/commandlineinput.h"
#include "command/commandparser.h"
#include "controls/itemcreationcontrol.h"
#include "controls/itempropertiescontrol.h"
#include "controls/itemtransformcontrol.h"
#include "controls/windowcontrol.h"
#include "controls/axiscontrol.h"
#include "interfaces/controlinterface.h"

Control::Control(GraphicsWidget *graphicsWidget)
{
    this->graphicsWidget=graphicsWidget;
    controls = new QHash<QString,ControlInterface*>();
    command = new Command();
    commandParser = new CommandParser();
    loadControlls();
}

Control::~Control()
{
    QList<ControlInterface*> controls = this->controls->values();
    this->controls->clear();

    foreach (ControlInterface* control, controls)
    {
        delete control;
    }

    delete this->controls;
    delete command;
}

void Control::loadControlls()
{
    QList<ControlInterface*> cmd;

    setCreationControl(cmd);
    setPropertiesControl(cmd);
    setTransformControls(cmd);
    setAxisControl(cmd);
    setWindowControl(cmd);

    foreach(ControlInterface* ci, cmd)
    {
        controls->insert(ci->getCommandLine().getCommand(),ci);
        commandParser->addCommandLine(ci->getCommandLine());
    }
}

void Control::setCreationControl(QList<ControlInterface *> &cmd)
{
    cmd.append(new ItemCreationControl(ItemCreationControl::ITEM_REMOVE));
    cmd.append(new ItemCreationControl(ItemCreationControl::ITEM_CREATE_ELLIPSE));
    cmd.append(new ItemCreationControl(ItemCreationControl::ITEM_CREATE_RECTANGLE));
    cmd.append(new ItemCreationControl(ItemCreationControl::ITEM_CREATE_LINE));
}


void Control::setPropertiesControl(QList<ControlInterface *> &cmd)
{
    cmd.append(new ItemPropertiesControl(ItemPropertiesControl::PROPERTY_VISIBILITY));
    cmd.append(new ItemPropertiesControl(ItemPropertiesControl::PROPERTY_FILL));
    cmd.append(new ItemPropertiesControl(ItemPropertiesControl::PROPERTY_COLOR));
    cmd.append(new ItemPropertiesControl(ItemPropertiesControl::PROPERTY_BORDER));
    cmd.append(new ItemPropertiesControl(ItemPropertiesControl::PROPERTY_POSITION));
}

void Control::setTransformControls(QList<ControlInterface*> &cmd)
{
    cmd.append(new ItemTransformControl(ItemTransformControl::TRANSFORM_TRANSLATE));
    cmd.append(new ItemTransformControl(ItemTransformControl::TRANSFORM_ROTATE));
}

void Control::setAxisControl(QList<ControlInterface*> &cmd)
{
    cmd.append(new AxisControl(AxisControl::AXIS_RESET_TRANSFORM));
    cmd.append(new AxisControl(AxisControl::AXIS_SET_VILIBLE));
    cmd.append(new AxisControl(AxisControl::AXIS_ROTATE));
    cmd.append(new AxisControl(AxisControl::AXIS_TRANSLATE));
}

void Control::setWindowControl(QList<ControlInterface *> &cmd)
{
    cmd.append(new WindowControl(WindowControl::WINDOW_UPDATE));
    cmd.append(new WindowControl(WindowControl::WINDOW_CLEAR));
    cmd.append(new WindowControl(WindowControl::WINDOW_SET_COLOR));
}

bool Control::executeCommand(const QString &strCommand)
{
    if(commandParser->parse(strCommand,*command))
    {
        ControlInterface* ci = (*controls)[command->getCommand()];
        ci->execCommand(graphicsWidget, command->getParameters());
        return true;
    }
    return false;
}

Control &Control::operator =(const Control &){
    return *this;
}


