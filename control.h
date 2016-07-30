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

#ifndef CONTROL_H
#define CONTROL_H

#include <QHash>
#include <QString>
#include <QList>

class GraphicsWidget;
class ControlInterface;

class CommandParser;
class Command;

/**
 * @brief The Control class
 * Create a set of commands to control GraphicWidget.
 * The commands are defined in ControlInterface.
 */
class Control
{
public:
    explicit Control(GraphicsWidget *graphicsWidget);

    virtual ~Control();
    /**
     * @brief executeCommand  Execute input string commands to control GraphicsWidget.
     * @param strCommand A string command defined in ControlInterface.
     * @return true if the command is recognized and executed otherwise returns false.
     */
    bool executeCommand(const QString &strCommand);

private:
    GraphicsWidget *graphicsWidget;
    QHash<QString, ControlInterface*> *controls;
    CommandParser *commandParser;
    Command *command;

    void loadControlls();
    void setWindowControl(QList<ControlInterface *> &cmd);
    void setAxisControl(QList<ControlInterface *> &cmd);
    void setTransformControls(QList<ControlInterface *> &cmd);
    void setPropertiesControl(QList<ControlInterface *> &cmd);
    void setCreationControl(QList<ControlInterface *> &cmd);

    Control &operator =(const Control &);
    Control(const Control &){}
};

#endif // CONTROL_H
