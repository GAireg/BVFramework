#ifndef WIDGETAUFGABEN_H
#define WIDGETAUFGABEN_H

#include <QWidget>
#include <QLabel>
#include <opencv2/opencv.hpp>
#include <QTimer>

typedef std::complex<double> complex;

namespace Ui {
class WidgetAufgaben;
}

class WidgetAufgaben : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetAufgaben(QWidget *parent = 0);
    ~WidgetAufgaben();
    virtual void OpenImage(QString path);
    void openCamera();

protected:
    QString basePath = "/home/gaireg/git/Studium/BV/Praktikum/bilder/";
    void drawLineOnLabel(QList<double> list, QLabel *label);
    virtual void updateLayout();

    bool grayscale = false;

    cv::Mat originalImage;

private:
    Ui::WidgetAufgaben *ui;
    QTimer *timer;
    cv::VideoCapture *capture;

private slots:
    void timerTick();
};

#endif // WIDGETAUFGABEN_H
