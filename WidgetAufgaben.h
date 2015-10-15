/***********************************************************
 *
 * WidgetAufgaben.h - Header for Aufgaben Parent
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
    int maxWidth = 1600;
    int maxHeight = 900;

private:
    Ui::WidgetAufgaben *ui;
    QTimer *timer;
    cv::VideoCapture *capture;

private slots:
    void timerTick();
};

#endif // WIDGETAUFGABEN_H
