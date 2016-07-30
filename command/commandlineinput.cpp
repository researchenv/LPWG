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

#include "commandlineinput.h"

CommandLineInput::CommandLineInput()
{

}

CommandLineInput::CommandLineInput(const QString &command,
                                   const ParametersType &parameters)
{
    this->command=command;
    this->parameters=parameters;
    setCommand(command,parameters);
}

const QString &CommandLineInput::getCommand() const
{
    return command;
}

const CommandLineInput::ParametersType &CommandLineInput::getParamtersType() const
{
    return parameters;
}

bool CommandLineInput::validateCommand(const QString &commandLine) const
{
    return re.match(commandLine).hasMatch();
}

void CommandLineInput::setCommand(const QString &command,
                                  const ParametersType &parameters)
{
    QString re_str = "\\A"+command;
    foreach (const ParameterType &p, parameters) {
        switch (p)
        {
        case PARAMATER_TYPE_INTEGER:
            re_str+=",[+-]?\\d+";
            break;
        case PARAMATER_TYPE_UINTEGER:
            re_str+=",\\d+";
            break;
        case PARAMATER_TYPE_FLOAT:
            re_str+=",[-+]?(\\d*[.])?\\d*";
            break;
        case PARAMATER_TYPE_STRING:
            re_str+=",\\w+";
            break;
        }
    }
    re_str+="\\z";
    re.setPattern(re_str);
}
