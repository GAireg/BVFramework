#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "DialogSelectAufgabe.h"
#include "EnumAufgaben.h"
#include <QFileDialog>
#include "WidgetAufgabe1.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentAufgabeWidget = new WidgetAufgabe1(this);
    ui->verticalLayout->addWidget(currentAufgabeWidget);
    currentAufgabeWidget->show();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete currentAufgabeWidget;
}

void MainWindow::on_actionAufgabe_W_hlen_triggered()
{
    DialogSelectAufgabe dia(this);
    dia.minAufgabe = Aufgaben::Aufgabe_1;
    dia.maxAufgabe = Aufgaben::Aufgabe_3;
    dia.debugAufgabe = Aufgaben::Aufgabe_1;
    if(dia.exec() != QDialog::Accepted){
        return;
    }
    ui->verticalLayout->removeWidget(currentAufgabeWidget);
    if(currentAufgabeWidget != NULL) delete currentAufgabeWidget;
    currentAufgabeWidget = NULL;
    auto aufgabe = dia.selectedAufgabe();
    switch (aufgabe) {
    case Aufgabe_1:
        currentAufgabeWidget = new WidgetAufgabe1(this);
        break;
    case Aufgabe_2:
        //currentAufgabeWidget = new WidgetAufgabe2(this);
        break;
    case Aufgabe_3:
        //currentAufgabeWidget = new WidgetAufgabe3(this);
        break;
    default:
        break;
    }
    ui->verticalLayout->addWidget(currentAufgabeWidget);
    currentAufgabeWidget->show();
}

void MainWindow::on_actionBild_ffnen_triggered()
{
    if(currentAufgabeWidget == NULL){return;}
    QFileDialog dia(this,"Bild Öffnen","/home/gaireg/git/Studium/BV/Praktikum/bilder/","*");
    if(dia.exec() != QDialog::Accepted) return;
    currentAufgabeWidget->OpenImage(dia.selectedFiles()[0]);
}

void MainWindow::on_actionKamera_ffnen_triggered()
{
    if(currentAufgabeWidget == NULL){return;}
    currentAufgabeWidget->openCamera();
}
