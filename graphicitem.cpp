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

#include "graphicitem.h"
#include "interfaces/abstractgraphicitem.h"
#include <QTransform>
#include <QBrush>
#include <QPen>
#include <QPainter>

GraphicItem::GraphicItem(AbstractGraphicItem *graphicItemInterface) :
    visible(true),
    brush(new QBrush()),
    pen(new QPen()),
    displacement(new QPoint())
{
    this->graphicItemInterface=graphicItemInterface;
    graphicItemInterface->displacement=displacement;
}

GraphicItem::~GraphicItem()
{
    delete brush;
    delete pen;
    delete displacement;
    delete graphicItemInterface;
}

void GraphicItem::paintEvent(QPainter &painter)
{
    graphicItemInterface->paintEvent(painter);
}

QBrush &GraphicItem::getBrush() const
{
    return *brush;
}

QPen &GraphicItem::getPen() const
{
    return *pen;
}

void GraphicItem::setVisible(const bool &visible)
{
    this->visible=visible;
}

const bool &GraphicItem::isVisible() const
{
    return visible;
}

QPoint &GraphicItem::getDisplacement() const
{
    return *displacement;
}

const QPoint &GraphicItem::getAxisPosition() const
{
    return axisPosition;
}

void GraphicItem::setAxisPosition(const QPoint &position)
{
    this->axisPosition = position;
}

const qreal &GraphicItem::getRotation() const
{
    return rotationDegree;
}

void GraphicItem::setRotation(const qreal &degree)
{
    rotationDegree=degree;
}

GraphicItem &GraphicItem::operator=(const GraphicItem &)
{
    return *this;
}
