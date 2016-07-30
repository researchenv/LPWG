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

#include "line.h"
#include <QPainter>
#include <QPoint>

Line::Line(const int &x0, const int &y0, const int &x1, const int &y1)
{
    this->x0=x0;
    this->y0=y0;
    this->x1=x1;
    this->y1=y1;
}

Line::~Line()
{

}

void Line::paintEvent(QPainter &painter)
{
    int dx = getDisplacement().x();
    int dy = getDisplacement().y();
    painter.drawLine(x0+dx,y0+dy,x1+dx,y1+dy);
}
