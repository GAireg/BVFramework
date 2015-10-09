/***********************************************************
 *
 * DialogSelectAufgabe.cpp - Dialog for selecting the Aufgabe
 *
 * Copyright 2015 Randolph Maaßen
 *
 **********************************************************/

/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "DialogSelectAufgabe.h"
#include "ui_DialogSelectAufgabe.h"
#include "EnumAufgaben.h"

#include <QString>

DialogSelectAufgabe::DialogSelectAufgabe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSelectAufgabe)
{
    ui->setupUi(this);
}

enum Aufgaben DialogSelectAufgabe::selectedAufgabe(){
    return (enum Aufgaben)(ui->comboBoxAufgabe->currentIndex()+minAufgabe);
}

DialogSelectAufgabe::~DialogSelectAufgabe()
{
    delete ui;
}

int DialogSelectAufgabe::exec(){

    for(int i=minAufgabe;i<=maxAufgabe;i++){
        ui->comboBoxAufgabe->addItem(QString("Aufgabe ") + QString::number(i));
    }
    ui->comboBoxAufgabe->setCurrentIndex(debugAufgabe-minAufgabe);
    return QDialog::exec();
}
