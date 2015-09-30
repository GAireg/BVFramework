#ifndef WIDGETAUFGABE1_H
#define WIDGETAUFGABE1_H

#include "widgetaufgaben.h"

namespace Ui {
class WidgetAufgabe1;
}

class WidgetAufgabe1 : public WidgetAufgaben
{
    Q_OBJECT

public:
    explicit WidgetAufgabe1(QWidget *parent = 0);
    ~WidgetAufgabe1();

private:
    Ui::WidgetAufgabe1 *ui;
};

#endif // WIDGETAUFGABE1_H
