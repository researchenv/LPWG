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

#include "itemcreationcontrol.h"
#include "../items/ellipse.h"
#include "../items/rectangle.h"
#include "../items/line.h"
#include "../graphicitem.h"
#include "../graphicswidget.h"

ItemCreationControl::ItemCreationControl(const ItemControl &itemControl)
{
    this->itemControl=itemControl;

    CommandLineInput::ParametersType p;

    QString command;

    switch (itemControl)
    {
    case ITEM_CREATE_ELLIPSE:
        p.append(CommandLineInput::PARAMATER_TYPE_INTEGER);
        p.append(CommandLineInput::PARAMATER_TYPE_INTEGER);
        p.append(CommandLineInput::PARAMATER_TYPE_INTEGER);
        p.append(CommandLineInput::PARAMATER_TYPE_INTEGER);
        command = "item_create_ellipse";
        break;
    case ITEM_CREATE_RECTANGLE:
        p.append(CommandLineInput::PARAMATER_TYPE_INTEGER);
        p.append(CommandLineInput::PARAMATER_TYPE_INTEGER);
        p.append(CommandLineInput::PARAMATER_TYPE_INTEGER);
        p.append(CommandLineInput::PARAMATER_TYPE_INTEGER);
        command = "item_create_rectangle";
        break;
    case ITEM_CREATE_LINE:
        p.append(CommandLineInput::PARAMATER_TYPE_INTEGER);
        p.append(CommandLineInput::PARAMATER_TYPE_INTEGER);
        p.append(CommandLineInput::PARAMATER_TYPE_INTEGER);
        p.append(CommandLineInput::PARAMATER_TYPE_INTEGER);
        command = "item_create_line";
        break;
    case ITEM_REMOVE:
        p.append(CommandLineInput::PARAMATER_TYPE_INTEGER);
        command = "item_remove";
        break;
    }

    commandLine = CommandLineInput(command,p);
}

ItemCreationControl::~ItemCreationControl()
{
}


void ItemCreationControl::execCommand(GraphicsWidget *gw,
                               const Parameters &parameters)
{
    GraphicItem *item = 0;

    switch (itemControl)
    {
    case ITEM_CREATE_ELLIPSE:
        //item_create_ellipse,x,y,width,height
        item = new GraphicItem(new Ellipse(parameters.at(0).toInt(),
                                           parameters.at(1).toInt(),
                                           parameters.at(2).toInt(),
                                           parameters.at(3).toInt())
                               );
        gw->addItem(item);
        break;
    case ITEM_CREATE_RECTANGLE:
        //item_create_rectangle,x,y,width,height
        item = new GraphicItem(new Rectangle(parameters.at(0).toInt(),
                                             parameters.at(1).toInt(),
                                             parameters.at(2).toInt(),
                                             parameters.at(3).toInt())
                               );
        gw->addItem(item);
        break;
    case ITEM_CREATE_LINE:
        //item_create_line,x,y,width,height
        item = new GraphicItem(new Line(parameters.at(0).toInt(),
                                        parameters.at(1).toInt(),
                                        parameters.at(2).toInt(),
                                        parameters.at(3).toInt())
                               );
        gw->addItem(item);
        break;
    case ITEM_REMOVE:
    {
        //item_remove,id
        uint id = parameters.at(0).toInt(0);
        item = gw->getItem(id);
        gw->removeItem(item);
        gw->removeItem(id);
        delete item;
        break;
    }
    }

}

const CommandLineInput &ItemCreationControl::getCommandLine() const
{
    return commandLine;
}
