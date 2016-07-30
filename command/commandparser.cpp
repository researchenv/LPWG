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

#include "commandparser.h"
#include "../command/command.h"
#include "../interfaces/controlinterface.h"

CommandParser::CommandParser()
{
}

CommandParser::~CommandParser()
{
}

void CommandParser::addCommandLine(const CommandLineInput &commandLine)
{
    commands.insert(commandLine.getCommand(),commandLine);
}

bool CommandParser::parse(const QString &commandLineStr, Command &cmd)
{
    bool ok=false;

    if(!commandLineStr.isEmpty())
    {
        cmd.clear();

        QStringList strlist;

        if(commandLineStr.contains(","))
        {
            strlist = commandLineStr.split(",");
        } else {
            strlist << commandLineStr;
        }

        QString cmdStr = strlist.takeFirst();

        if(commands.contains(cmdStr) && commands.value(cmdStr).validateCommand(commandLineStr) ){

            cmd.setCommand(cmdStr);

            const CommandLineInput::ParametersType &p = commands.value(cmdStr).getParamtersType();

            int count = p.size();

            if(count > 0){
                for(int i=0; i< count; i++)
                {
                    const QString &str = strlist.at(i);
                    switch (p.at(i))
                    {
                    case CommandLineInput::PARAMATER_TYPE_INTEGER:
                        cmd.addParameter(str.toInt());
                        break;
                    case CommandLineInput::PARAMATER_TYPE_UINTEGER:
                        cmd.addParameter(str.toUInt());
                        break;
                    case CommandLineInput::PARAMATER_TYPE_FLOAT:
                        cmd.addParameter(str.toFloat());
                        break;
                    case CommandLineInput::PARAMATER_TYPE_STRING:
                        cmd.addParameter(str);
                        break;
                    }
                }
            }
            ok=true;
        }
    }

    return ok;
}
