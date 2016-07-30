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

#include "itemtransformcontrol.h"
#include "../graphicswidget.h"
#include "../graphicitem.h"

ItemTransformControl::ItemTransformControl(const ItemTransformControl::Transform &transform)
{
    this->transform=transform;

    CommandLineInput::ParametersType p;

    QString command;

    switch (transform)
    {
    case TRANSFORM_TRANSLATE:
        p.append(CommandLineInput::PARAMATER_TYPE_UINTEGER);
        p.append(CommandLineInput::PARAMATER_TYPE_INTEGER);
        p.append(CommandLineInput::PARAMATER_TYPE_INTEGER);
        command = "item_translate";
        break;
    case TRANSFORM_ROTATE:
        p.append(CommandLineInput::PARAMATER_TYPE_UINTEGER);
        p.append(CommandLineInput::PARAMATER_TYPE_FLOAT);
        command = "item_rotate";
        break;
    }

    commandLine = CommandLineInput(command,p);
}

ItemTransformControl::~ItemTransformControl()
{

}

void ItemTransformControl::execCommand(GraphicsWidget *gw, const Parameters &parameters)
{
    uint itemID = parameters.at(0).toUInt();

    GraphicItem *item = gw->getItem(itemID);

    if(item!=0)
    {
        switch (transform) {
        case TRANSFORM_TRANSLATE:
            //item_translate,id,dx,dy
            item->getDisplacement()+=QPoint(parameters.at(1).toInt(),parameters.at(2).toInt());
            break;
        case TRANSFORM_ROTATE:
            //item_rotate,id,degree
            item->setRotation(parameters.at(1).toInt());
            break;
        }
    }
}

const CommandLineInput &ItemTransformControl::getCommandLine() const
{
    return commandLine;
}
