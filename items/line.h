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

#ifndef LINE_H
#define LINE_H

#include "../interfaces/abstractgraphicitem.h"

class Line : public AbstractGraphicItem
{
public:
    Line(const int &x0, const int &y0, const int &x1, const int &y1);

    virtual ~Line();

    // PaintInterface interface
    void paintEvent(QPainter &painter);

private:
    int x0;
    int y0;
    int x1;
    int y1;

};

#endif // LINE_H
