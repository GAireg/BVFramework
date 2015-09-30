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
