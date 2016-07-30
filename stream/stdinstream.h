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

#ifndef STDINSTREAM_H
#define STDINSTREAM_H

#include "../interfaces/streaminterface.h"

class QTextStream;

class StdinStream : public StreamInterface
{
    Q_OBJECT

public:
    explicit StdinStream(QObject *parent=0);

    virtual ~StdinStream();

    void stopStream();

public slots:
    void startStream();

private:
    QTextStream *stream;
    bool isRunning;

    StdinStream &operator =(const StdinStream&);
};


#endif // STDINSTREAM_H
