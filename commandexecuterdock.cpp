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

#include "commandexecuterdock.h"

CommandExecuterDock::CommandExecuterDock(QWidget *parent):CommandExecuter(parent){

}

void CommandExecuterDock::enableStackH(){
    executeCommand("defaults write com.apple.dock mouse-over-hilte-stack 1");
    emit dockRestartRequired();
}

void CommandExecuterDock::disableStackH(){
    executeCommand("defaults write com.apple.dock mouse-over-hilte-stack 0");
    emit dockRestartRequired();
}

void CommandExecuterDock::enableForceDock(){
    executeCommand("defaults write com.apple.dock static-only -bool TRUE");
    emit dockRestartRequired();
}

void CommandExecuterDock::disableForceDock(){
    executeCommand("defaults write com.apple.dock static-only -bool FALSE");
    emit dockRestartRequired();
}

void CommandExecuterDock::enableHiddenApp(){
    executeCommand("defaults write com.apple.Dock showhidden -bool YES");
    emit dockRestartRequired();
}

void CommandExecuterDock::disableHiddenApp(){
    executeCommand("defaults write com.apple.Dock showhidden -bool NO");
    emit dockRestartRequired();
}

void CommandExecuterDock::enableWidgetDrag(){
    executeCommand("defaults write com.apple.dashboard devmode YES");
    emit dockRestartRequired();
}

void CommandExecuterDock::disableWidgetDrag(){
    executeCommand("defaults write com.apple.dashboard devmode NO");
    emit dockRestartRequired();
}

void CommandExecuterDock::enable2D(){
    executeCommand("defaults write com.apple.dock no-glass -boolean YES");
    emit dockRestartRequired();
}

void CommandExecuterDock::disable2D(){
    executeCommand("defaults write com.apple.dock no-glass -boolean NO");
    emit dockRestartRequired();
}

void CommandExecuterDock::restart(){
    executeCommand("killall Dock");
}


