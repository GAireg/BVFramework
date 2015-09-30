/***********************************************************
 *
 * WidgetAufgabe1 - Header for Aufgabe 1
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

#include "WidgetAufgabe1.h"
#include "ui_WidgetAufgabe1.h"

WidgetAufgabe1::WidgetAufgabe1(QWidget *parent) :
    WidgetAufgaben(parent),
    ui(new Ui::WidgetAufgabe1)
{
    ui->setupUi(this);
    ui->label_original->setCaption("Original Image");
}

WidgetAufgabe1::~WidgetAufgabe1()
{
    delete ui;
}

void WidgetAufgabe1::updateLayout()
{
    ui->label_original->setMatrix(originalImage,false);
}
