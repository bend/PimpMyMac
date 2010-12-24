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

#include "ui.h"

UI::UI(QWidget *parent) : QMainWindow(parent){
    setupUI();

}

void UI::setupUI(){
    this->setAttribute(Qt::WA_MacMetalStyle);
    this->setFixedSize(600,400);
    QWidget *central = new QWidget();
    this->setCentralWidget(central);
    QGridLayout *grid = new QGridLayout();
    QVBoxLayout *drawerGrid = new QVBoxLayout();

}
