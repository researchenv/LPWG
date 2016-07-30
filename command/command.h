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

#ifndef COMMAND_H
#define COMMAND_H

#include "interfaces/controlinterface.h"
#include <QString>

/**
 * @brief The Command class
 * Stores a command to be executed. The command are definde by a string and a list of parameteres.
 */
class Command
{
public:
    explicit Command();

    ~Command();

    /**
     * @brief getCommand The command string. Ex: axis_translate.
     * @return The command string.
     */
    const QString &getCommand() const;

    /**
     * @brief getParameters List of parameter respective to the command.
     * @return List of parameters.
     */
    const Parameters &getParameters() const;

    /**
     * @brief setCommand Sets the command string.
     * @param command A string for the command. Ex:"axis_translate"
     */
    void setCommand(const QString &command);

    /**
     * @brief addParameter
     * @param value A command paramenter value.
     * Example: command axis_translate,20,30 translates the axis 20 pixel in x direcion
     * and 30 pixels in y direction. Add parameter are called with 20 and then with 30.
     */
    void addParameter(const QVariant &value);

    /**
     * @brief clear Clear command and parameters.
     */
    void clear();

private:
    Parameters parameters;
    QString command;
};

#endif // COMMAND_H



