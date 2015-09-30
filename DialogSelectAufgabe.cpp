#include "DialogSelectAufgabe.h"
#include "ui_dialogselectaufgabe.h"
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
