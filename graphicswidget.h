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

#ifndef GRAPHICSWIDGET_H
#define GRAPHICSWIDGET_H

#include <QWidget>
#include <QList>

class GraphicItem;
class QTransform;

class GraphicsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GraphicsWidget(QWidget *parent = 0);

    virtual ~GraphicsWidget();

    void addItem(GraphicItem* abstractShape);

    GraphicItem *getItem(uint itemID) const;

    void removeItem(GraphicItem* item);

    void removeItem(uint itemID);

    void removeAllItems();

    void showAxis(const bool &show);

    QList<GraphicItem *> &getItems() const;

    QTransform &getTransform() const;

private:
    QList<GraphicItem*> *items;
    QList<uint> *itemIDs;
    bool _drawAxis;
    QTransform *transform;
    static uint itemID;

    GraphicsWidget(const GraphicsWidget &) : QWidget(0){}
    GraphicsWidget &operator =(const GraphicsWidget &);

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *);
};

#endif // GRAPHICSWIDGET_H
