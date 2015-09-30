#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "widgetaufgaben.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionAufgabe_W_hlen_triggered();

    void on_actionBild_ffnen_triggered();

    void on_actionKamera_ffnen_triggered();

private:
    Ui::MainWindow *ui;
    WidgetAufgaben *currentAufgabeWidget;
};

#endif // MAINWINDOW_H
