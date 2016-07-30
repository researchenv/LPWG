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

#ifndef ITEMPROPERTIESCONTROL_H
#define ITEMPROPERTIESCONTROL_H

#include "../interfaces/controlinterface.h"
#include "../command/commandlineinput.h"

class ItemPropertiesControl : public ControlInterface
{
public:
    enum Propertie
    {
        PROPERTY_COLOR,
        PROPERTY_FILL,
        PROPERTY_BORDER,
        PROPERTY_VISIBILITY,
        PROPERTY_POSITION
    };

    explicit ItemPropertiesControl(const Propertie &propertie);

    virtual ~ItemPropertiesControl();

    // ControlInterface interface
    const CommandLineInput &getCommandLine() const;

    void execCommand(GraphicsWidget *gw,
              const Parameters &parameters);

private:
    Propertie propertie;
    CommandLineInput commandLine;
};

#endif // ITEMPROPERTIESCONTROL_H
