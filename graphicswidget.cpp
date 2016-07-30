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

#include "graphicswidget.h"
#include "graphicitem.h"
#include <QPainter>
#include <QStyleOption>
#include <QTransform>

uint GraphicsWidget::itemID=0;

GraphicsWidget::GraphicsWidget(QWidget *parent) :
    QWidget(parent),
    items(new QList<GraphicItem*>()),
    itemIDs(new QList<uint>()),
    _drawAxis(false),
    transform(new QTransform())
{
    setStyleSheet("GraphicsWidget{background-color:white}");
}

GraphicsWidget::~GraphicsWidget()
{
    if(items){
        while(!items->isEmpty())
        {
            delete items->takeLast();
        }
    }

    delete transform;
    delete items;
    delete itemIDs;
}

void GraphicsWidget::addItem(GraphicItem *abstractShape)
{
    if(!items->contains(abstractShape))
    {
        items->append(abstractShape);
        itemIDs->append(itemID++);
    }
}

GraphicItem *GraphicsWidget::getItem(uint itemID) const
{
    if(itemIDs->contains(itemID))
    {
        uint index = itemIDs->indexOf(itemID);
        return items->at(index);
    }
    return 0;
}

void GraphicsWidget::removeItem(GraphicItem *item)
{
    if(items->contains(item))
    {
        uint index = items->indexOf(item);
        items->removeAt(index);
        itemIDs->removeAt(index);
    }
}

void GraphicsWidget::removeItem(uint itemID)
{
    if(itemIDs->contains(itemID))
    {
        uint index = itemIDs->takeAt(itemID);
        items->removeAt(index);
    }
}

void GraphicsWidget::removeAllItems()
{
    while(!items->isEmpty())
    {
        delete items->takeFirst();
    }
    itemID=0;
}

void GraphicsWidget::showAxis(const bool &show)
{
    _drawAxis=show;
}

QList<GraphicItem *> &GraphicsWidget::getItems() const
{
    return *items;
}

QTransform &GraphicsWidget::getTransform() const
{
    return *transform;
}


void GraphicsWidget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);

    painter.setTransform(*transform);

    //draw axis
    if(_drawAxis)
    {
        //2 times the rect side is enough to regard drawing axis rotated
        int w = 2*rect().width();
        int h = 2*rect().height();
        painter.drawLine(-w,0,w,0);
        painter.drawLine(0,-h,0,h);
    }

    foreach (GraphicItem *item, *items) {
        if(item->isVisible())
        {
            painter.save();
            painter.setBrush(item->getBrush());
            painter.setPen(item->getPen());
            painter.translate(item->getAxisPosition());
            painter.rotate(item->getRotation());
            item->paintEvent(painter);
            painter.restore();
        }
    }
}


GraphicsWidget &GraphicsWidget::operator =(const GraphicsWidget &)
{
    return *this;
}
