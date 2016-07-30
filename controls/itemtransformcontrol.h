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

#ifndef ITEMTRANSFORMCONTROL_H
#define ITEMTRANSFORMCONTROL_H

#include "../interfaces/controlinterface.h"
#include "../command/commandlineinput.h"

class ItemTransformControl : public ControlInterface
{
public:
    enum Transform
    {
        TRANSFORM_TRANSLATE,    //relative to parent axis
        TRANSFORM_ROTATE        //relative to item axis
    };

    explicit ItemTransformControl(const Transform &transform);

    virtual ~ItemTransformControl();

    // ControlInterface interface
    const CommandLineInput &getCommandLine() const;

    void execCommand(GraphicsWidget *gw,
              const Parameters &parameters);

private:
    Transform transform;
    CommandLineInput commandLine;
};

#endif // ITEMTRANSFORMCONTROL_H
