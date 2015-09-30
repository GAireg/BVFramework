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
