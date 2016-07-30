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

#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include <QHash>
#include "commandlineinput.h"

class QString;
class Command;
class ControlInterface;

/**
 * @brief The CommandParser class
 * A command line parser. A command line contains a command followed by its parameters separeted by commas.
 * Ex: axis_translate,20,30
 */
class CommandParser
{
public:
    CommandParser();

    virtual ~CommandParser();

    /**
     * @brief addCommandLine Each commandLine inserted corresponds to a commandLineStr string.
     * @param commandLine
     */
    void addCommandLine(const CommandLineInput &commandLine);

    /**
     * @brief parse Parses the comandLineStr input string and stores the result in command object.
     * The commandLineStr string will be compared to all CommandLineInput objects added to
     * this class, and if one is mached, the comandLineStr string elements are converted to
     * apropriated command and paramters in the cmd object. If no match is found, cmd remains
     * unchaged.
     *
     * @param commandLine The command input string: Ex: axis_translate,20,30
     * @param command Stores command and parameters parsed from commandLine string.
     * @return True if commanLineStr was parsed correctly, otherwhise returns false.
     */
    bool parse(const QString &commandLineStr, Command& cmd);

private:
    QHash<QString, CommandLineInput> commands;
};

#endif // COMMANDPARSER_H
