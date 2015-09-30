/***********************************************************
 *
 * DialogSelectAufgabe.h - Dialog to select the Aufgabe
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

#ifndef DIALOGSELECTAUFGABE_H
#define DIALOGSELECTAUFGABE_H

#include <QDialog>
#include <EnumAufgaben.h>

namespace Ui {
class DialogSelectAufgabe;
}

class DialogSelectAufgabe : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSelectAufgabe(QWidget *parent = 0);
    ~DialogSelectAufgabe();

    enum Aufgaben selectedAufgabe();
    int exec();
    int maxAufgabe;
    int debugAufgabe;
    int minAufgabe;

private:
    Ui::DialogSelectAufgabe *ui;

};

#endif // DIALOGSELECTAUFGABE_H
