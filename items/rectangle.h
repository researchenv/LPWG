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

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QtCore>
#include "../interfaces/abstractgraphicitem.h"

class Rectangle : public AbstractGraphicItem
{
public:
    Rectangle(const int &x, const int &y, const uint &width, const uint &height);

    virtual ~Rectangle();

    // PaintInterface interface
    void paintEvent(QPainter &painter);

private:
    uint x;
    uint y;
    int width;
    int height;
};

#endif // RECTANGLE_H
