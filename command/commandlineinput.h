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

#ifndef COMMANDLINEINPUP_H
#define COMMANDLINEINPUP_H

#include <QList>
#include <QRegularExpression>

/**
 * @brief The CommandLineInput class
 * Defindes the command and the command parameters type.
 */
class CommandLineInput
{
public:
    enum ParameterType
    {
        PARAMATER_TYPE_INTEGER,
        PARAMATER_TYPE_UINTEGER,
        PARAMATER_TYPE_FLOAT,
        PARAMATER_TYPE_STRING

    };

    typedef QList<ParameterType> ParametersType;

    CommandLineInput();


    explicit CommandLineInput(const QString &command,
                              const ParametersType &parameters);

    const QString &getCommand() const;

    const ParametersType &getParamtersType() const;

    /**
     * @brief validateCommand Validates the input commandLine. Check if command and parameters in commandLine matches
     * command and parameters types defined in the constructor.
     * @param commandLine A string with a command line. Ex: axis_translate,20,30
     * @return
     */
    bool validateCommand(const QString &commandLine) const;

private:
    ParametersType parameters;
    QString command;
    QRegularExpression re;

    void setCommand(const QString &commandString,
                    const ParametersType &parameters);
};

#endif // COMMANDLINEINPUP_H
