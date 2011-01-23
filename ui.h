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

#ifndef UI_H
#define UI_H

#include "commandexecuterql.h"
#include "warningdialog.h"

#include <QMainWindow>
#include <QLayout>
#include <QPushButton>
#include <QRadioButton>
#include <QTabWidget>
#include <QPushButton>
#include <QLabel>
#include <QIcon>

class UI : public QMainWindow
{
    Q_OBJECT
public:
    explicit UI(QWidget *parent = 0);
    ~UI();

private:
    void setupUI();
    void setupQuickLookTab();
    void setupDockTab();

    CommandExecuterQL *commandExecQL;
    //CommandExecuterDock *commandExecDock;


    QGridLayout *grid ;
    QVBoxLayout *drawerGrid;
    QWidget *central;
    QTabWidget *tab;
    QWidget *dockTab;
    QWidget *quickLookTab;


signals:

private slots:
    void restartDock();
    void restartFinder();

};

#endif // UI_H
