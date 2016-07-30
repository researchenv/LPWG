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

#ifndef GRAPHICITEM
#define GRAPHICITEM

#include <QtCore>

class QBrush;
class QPen;
class QPainter;
class QTransform;
class QPoint;
class AbstractGraphicItem;

class GraphicItem
{
public:
    explicit GraphicItem(AbstractGraphicItem *graphicItemInterface);

    virtual ~GraphicItem();

    void paintEvent(QPainter &painter);

    const bool &isVisible() const;

    QTransform &getTransform() const;

    QBrush &getBrush() const;

    QPen &getPen() const;

    QPoint &getDisplacement() const;

    const QPoint &getAxisPosition() const;

    const qreal &getRotation() const;

    void setAxisPosition(const QPoint &axisPosition);

    void setRotation(const qreal& degree);

    void setVisible(const bool &visible);

private:
    QPoint axisPosition;
    bool visible;
    qreal rotationDegree;

    AbstractGraphicItem * graphicItemInterface;
    QBrush *brush;
    QPen *pen;
    QPoint *displacement;

    GraphicItem(const GraphicItem &){}
    GraphicItem &operator=(const GraphicItem &);
};

#endif // GRAPHICITEM



