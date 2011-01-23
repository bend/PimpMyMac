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

#include "commandexecuterql.h"

CommandExecuterQL::CommandExecuterQL(QWidget *parent) :CommandExecuter(parent){
}


void CommandExecuterQL::enableXRay(){
    executeCommand("defaults write com.apple.Finder QLEnableXRayFolders 1");
    emit finderRestartRequired();
}

void CommandExecuterQL::disableXRay(){
    executeCommand("defaults write com.apple.Finder QLEnableXRayFolders 0");
    emit finderRestartRequired();
}

void CommandExecuterQL::enableSlowMo(){
    executeCommand("defaults write com.apple.Finder QLEnableSlowMotion 1");
    emit finderRestartRequired();
}

void CommandExecuterQL::disableSlowMo(){
    executeCommand("defaults write com.apple.Finder QLEnableSlowMotion 0");
    emit finderRestartRequired();
}

void CommandExecuterQL::enableHql(){
    executeCommand("defaults write com.apple.Finder QLHidePanelOnDeactivate 1");
    emit finderRestartRequired();
}

void CommandExecuterQL::disableHql(){
    executeCommand("defaults write com.apple.Finder QLHidePanelOnDeactivate 0");
    emit finderRestartRequired();
}

void CommandExecuterQL::enableKp(){
    executeCommand("defaults write com.apple.Finder AutoStopWhenSelectionChanges 0");
    emit finderRestartRequired();
}

void CommandExecuterQL::disableKp(){
    executeCommand("defaults write com.apple.Finder AutoStopWhenSelectionChanges 1");
    emit finderRestartRequired();
}

void CommandExecuterQL::enableInLine(){
    executeCommand("defaults write com.apple.Finder AutoStopWhenSelectionChanges 0");
    emit finderRestartRequired();
}

void CommandExecuterQL::disableInLine(){
    executeCommand("defaults write com.apple.Finder AutoStopWhenSelectionChanges 1");
    emit finderRestartRequired();
}

void CommandExecuterQL::restart(){
    executeCommand("killall quicklookd32");
    executeCommand("killall Finder");
}

