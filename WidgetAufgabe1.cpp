#include "WidgetAufgabe1.h"
#include "ui_WidgetAufgabe1.h"

WidgetAufgabe1::WidgetAufgabe1(QWidget *parent) :
    WidgetAufgaben(parent),
    ui(new Ui::WidgetAufgabe1)
{
    ui->setupUi(this);
}

WidgetAufgabe1::~WidgetAufgabe1()
{
    delete ui;
}
