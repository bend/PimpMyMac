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

#include "commandexecuter.h"

CommandExecuter::CommandExecuter(QObject *parent) :QObject(parent){

}

void CommandExecuter::executeCommand(string commandType, int val){

}

void CommandExecuter::executeCommand(string command){
    size_t size = command.size() + 1;
    char * buffer = new char[ size ];
    strncpy( buffer, command.c_str(), size );
    system(buffer);
}







