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

#include "itempropertiescontrol.h"
#include "../graphicswidget.h"
#include "../graphicitem.h"
#include <QColor>
#include <QPen>
#include <QBrush>

ItemPropertiesControl::ItemPropertiesControl(const Propertie &propertie)
{
    this->propertie=propertie;

    CommandLineInput::ParametersType p;

    QString command;

    switch (propertie)
    {
    case PROPERTY_COLOR:
        p.append(CommandLineInput::PARAMATER_TYPE_UINTEGER);
        p.append(CommandLineInput::PARAMATER_TYPE_UINTEGER);
        command="item_set_color";
        break;
    case PROPERTY_FILL:
        p.append(CommandLineInput::PARAMATER_TYPE_UINTEGER);
        p.append(CommandLineInput::PARAMATER_TYPE_UINTEGER);
        command="item_set_filled";
        break;
    case PROPERTY_BORDER:
        p.append(CommandLineInput::PARAMATER_TYPE_UINTEGER);
        p.append(CommandLineInput::PARAMATER_TYPE_UINTEGER);
        p.append(CommandLineInput::PARAMATER_TYPE_UINTEGER);
        command="item_set_border";
        break;
    case PROPERTY_VISIBILITY:
        p.append(CommandLineInput::PARAMATER_TYPE_UINTEGER);
        p.append(CommandLineInput::PARAMATER_TYPE_UINTEGER);
        command="item_set_visible";
        break;
    case PROPERTY_POSITION:
        p.append(CommandLineInput::PARAMATER_TYPE_UINTEGER);
        p.append(CommandLineInput::PARAMATER_TYPE_INTEGER);
        p.append(CommandLineInput::PARAMATER_TYPE_INTEGER);
        command = "item_set_position";
        break;

    }

    commandLine = CommandLineInput(command,p);
}

ItemPropertiesControl::~ItemPropertiesControl()
{

}

void ItemPropertiesControl::execCommand(GraphicsWidget *gw,
                                 const Parameters &parameters)
{
    uint itemID = parameters.at(0).toUInt();
    GraphicItem* item = gw->getItem(itemID);

    if(item!=0)
    {
        switch (propertie) {
        case PROPERTY_COLOR:
            //item_set_color,id,color [color is uint ARGB]
            item->getBrush().setColor(QColor(parameters.at(1).toUInt()));
            break;
        case PROPERTY_FILL:
            //item_set_filled,id,value [value: 0=false, 1=true]
            item->getBrush().setStyle(parameters.at(1).toUInt()==1?Qt::SolidPattern:Qt::NoBrush);
            break;
        case PROPERTY_BORDER:
            //item_set_border,id,color,width [color is uint ARGB]
            item->getPen().setColor(QColor(parameters.at(1).toUInt()));
            item->getPen().setWidth(parameters.at(2).toUInt());
            break;
        case PROPERTY_VISIBILITY:
            //item_set_visible,id,value [value: 0=false, 1=true]
            item->setVisible(parameters.at(1).toBool());
            break;
        case PROPERTY_POSITION:
            //item_set_position,id,dx,dy
            item->setAxisPosition(QPoint(parameters.at(1).toInt(),parameters.at(2).toInt()));
            break;

        }
    }
}


const CommandLineInput &ItemPropertiesControl::getCommandLine() const
{
    return commandLine;
}
