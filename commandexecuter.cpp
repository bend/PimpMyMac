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

void CommandExecuter::enableXRay(){
    executeCommand("defaults write com.apple.Finder QLEnableXRayFolders 1");
}

void CommandExecuter::disableXRay(){
    executeCommand("defaults write com.apple.Finder QLEnableXRayFolders 0");
}

void CommandExecuter::enableSlowMo(){
    executeCommand("defaults write com.apple.Finder QLEnableSlowMotion 1");
}

void CommandExecuter::disableSlowMo(){
    executeCommand("defaults write com.apple.Finder QLEnableSlowMotion 0");
}

void CommandExecuter::enableHql(){
    executeCommand("defaults write com.apple.Finder QLHidePanelOnDeactivate 1");
}

void CommandExecuter::disableHql(){
    executeCommand("defaults write com.apple.Finder QLHidePanelOnDeactivate 0");
}

void CommandExecuter::enableKp(){
    executeCommand("defaults write com.apple.Finder AutoStopWhenSelectionChanges 0");
}

void CommandExecuter::disableKp(){
    executeCommand("defaults write com.apple.Finder AutoStopWhenSelectionChanges 1");
}

void CommandExecuter::enableInLine(){
    executeCommand("defaults write com.apple.Finder AutoStopWhenSelectionChanges 0");
}

void CommandExecuter::disableInLine(){
    executeCommand("defaults write com.apple.Finder AutoStopWhenSelectionChanges 1");
}




