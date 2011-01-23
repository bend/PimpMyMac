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
#include <QMessageBox>

UI::UI(QWidget *parent) : QMainWindow(parent){
    setupUI();
}

void UI::setupUI(){
    commandExecQL = new CommandExecuterQL();
    this->setAttribute(Qt::WA_MacMetalStyle);
    this->setFixedSize(600,500);
    central = new QWidget();
    this->setCentralWidget(central);
    grid = new QGridLayout();
    drawerGrid = new QVBoxLayout();

    tab = new QTabWidget(central);
    tab->setGeometry(20,20,550,450);
    dockTab = new QWidget();
    connect(commandExecQL, SIGNAL(dockRestartRequired()),this,SLOT(restartDock()));
    connect(commandExecQL, SIGNAL(finderRestartRequired()),this, SLOT(restartFinder()));

   // tab->addTab(dockTab,"Dock");

    setupQuickLookTab();

}

UI::~UI(){
}

void UI::setupQuickLookTab(){
    quickLookTab = new QWidget();

    QGridLayout *grid = new QGridLayout();
    quickLookTab->setLayout(grid);
    QIcon qlIcon("../Resources/QL.png");
    QIcon checkIcon("../Resources/check.png");
    QIcon uncheckIcon("../Resources/uncheck.png");

    tab->addTab(quickLookTab, qlIcon,"QuickLook");
    QLabel *xray = new QLabel("X-Raying");
    grid->addWidget(xray,0,0);
    QPushButton *enable_ray = new QPushButton(checkIcon,"Enable");
    QPushButton *disable_ray = new QPushButton(uncheckIcon,"Disable");
    grid->addWidget(enable_ray,0,6);
    grid->addWidget(disable_ray,1,6);
    connect(enable_ray, SIGNAL(clicked()), commandExecQL, SLOT(enableXRay()));
    connect(disable_ray, SIGNAL(clicked()), commandExecQL, SLOT(disableXRay()));


    QLabel *slowMo = new QLabel("Slow-Motion");
    grid->addWidget(slowMo,2,0);
    QPushButton *enable_sm = new QPushButton(checkIcon,"Enable");
    QPushButton *disable_sm = new QPushButton(uncheckIcon,"Disable");
    grid->addWidget(enable_sm,2,6);
    grid->addWidget(disable_sm,3,6);
    connect(enable_sm, SIGNAL(clicked()), commandExecQL, SLOT(enableSlowMo()));
    connect(disable_sm, SIGNAL(clicked()), commandExecQL, SLOT(disableSlowMo()));

    QLabel *hideQL = new QLabel("Hide QuickLook Window When Finder Isn't In Front");
    grid->addWidget(hideQL,4,0);
    QPushButton *enable_hql = new QPushButton(checkIcon,"Enable");
    QPushButton *disable_hql = new QPushButton(uncheckIcon,"Disable");
    //enable_hql->setFlat(true);
    grid->addWidget(enable_hql,4,6);
    grid->addWidget(disable_hql,5,6);
    connect(enable_hql, SIGNAL(clicked()), commandExecQL, SLOT(enableHql()));
    connect(disable_hql, SIGNAL(clicked()), commandExecQL, SLOT(disableHql()));

    QLabel *keepPlay = new QLabel("Keep playing Icon previews even if not selected");
    grid->addWidget(keepPlay,6,0);
    QPushButton *enable_kp = new QPushButton(checkIcon,"Enable");
    QPushButton *disable_kp = new QPushButton(uncheckIcon,"Disable");
    grid->addWidget(enable_kp,6,6);
    grid->addWidget(disable_kp,7,6);
    connect(enable_kp, SIGNAL(clicked()), commandExecQL, SLOT(enableKp()));
    connect(disable_kp, SIGNAL(clicked()), commandExecQL, SLOT(disableKp()));


    QLabel *inLine = new QLabel("Enable In-Line Previews For ANY Icon Size");
    grid->addWidget(inLine,8,0);
    QPushButton *enable_il = new QPushButton(checkIcon,"Enable");
    QPushButton *disable_il = new QPushButton(uncheckIcon,"Disable");
    grid->addWidget(enable_il,8,6);
    grid->addWidget(disable_il,9,6);
    connect(enable_il, SIGNAL(clicked()), commandExecQL, SLOT(enableInLine()));
    connect(disable_il, SIGNAL(clicked()), commandExecQL, SLOT(disableInLine()));

}

void UI::restartDock(){
    //QMessageBox box();
    //box.setAttribute(Qt::Sheet);
}

void UI::restartFinder(){
    WarningDialog *dial = new WarningDialog(this,"Finder must be restarted","Finder");
    connect(dial,SIGNAL(restartNow()),commandExecQL,SLOT(restart()));
    dial->show();
}

