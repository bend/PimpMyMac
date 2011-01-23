/*
*   Copyright © Benoit Daccache
*   ben.daccache@gmail.com
*
*
*   This is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef COMMANDEXECUTERQL_H
#define COMMANDEXECUTERQL_H

#include <QWidget>
#include "commandexecuter.h"

class CommandExecuterQL : public CommandExecuter
{
    Q_OBJECT
public:
    explicit CommandExecuterQL(QWidget *parent = 0);

signals:

public slots:
    void enableXRay();
    void disableXRay();
    void enableSlowMo();
    void disableSlowMo();
    void enableHql();
    void disableHql();
    void enableKp();
    void disableKp();
    void enableInLine();
    void disableInLine();
    void restart();

};

#endif // COMMANDEXECUTERQL_H
