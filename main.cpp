#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    try{
        return a.exec();
    }
    catch(cv::Exception &e){
        qDebug(e.what());
        throw e;
    }
}
