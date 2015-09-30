/***********************************************************
 *
 * WidgetAufgabe1.h - Header for solving Aufgabe1
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

#ifndef WIDGETAUFGABE1_H
#define WIDGETAUFGABE1_H

#include "WidgetAufgaben.h"

namespace Ui {
class WidgetAufgabe1;
}

class WidgetAufgabe1 : public WidgetAufgaben
{
    Q_OBJECT

public:
    explicit WidgetAufgabe1(QWidget *parent = 0);
    ~WidgetAufgabe1();

    void updateLayout();

private:
    Ui::WidgetAufgabe1 *ui;
};

#endif // WIDGETAUFGABE1_H
