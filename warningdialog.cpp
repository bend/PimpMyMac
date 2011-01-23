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

#include "warningdialog.h"

WarningDialog::WarningDialog(QWidget *parent,QString text,QString prog) :QDialog(parent,Qt::Sheet){
    this->setFixedSize(350,150);
    this->prog = prog;
    this->setAttribute( Qt::WA_DeleteOnClose );
    this->setAttribute(Qt::WA_MacBrushedMetal);

    QImage img("../Resources/Restart.png");

    QGridLayout *layout = new QGridLayout();
    this->setLayout(layout);
    QPushButton *restart = new QPushButton("Restart now");
    QPushButton *later = new QPushButton("Restart later");
    QLabel *label = new QLabel(text+"\n"+"Do you want to restart it now?");
    QLabel *icon = new QLabel();
    icon->setPixmap(QPixmap::fromImage(img));
    layout->addWidget(icon,0,0);
    layout->addWidget(label,0,1,1,2);
    layout->addWidget(restart,2,0);
    layout->addWidget(later,2,2);
    connect(restart,SIGNAL(clicked()),this,SLOT(restart()));
    connect(later,SIGNAL(clicked()),this,SLOT(later()));
}

void WarningDialog::restart(){
    emit restartNow();
    this->close();

}

void WarningDialog::later(){
    this->close();
}


