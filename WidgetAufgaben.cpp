/***********************************************************
 *
 * WidgetAufgaben.cpp - Parent for Aufgaben, opening image/cam
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

#include "WidgetAufgaben.h"
#include "ui_WidgetAufgaben.h"

#include <QPainter>
#include <QTimer>

WidgetAufgaben::WidgetAufgaben(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetAufgaben)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    capture = NULL;
}

WidgetAufgaben::~WidgetAufgaben()
{
    delete ui;
    delete timer;
    if(capture != NULL){
        delete capture;
        capture = NULL;
    }
}

void WidgetAufgaben::OpenImage(QString path){
    //stop timer if its running and close the camera
    if(timer->isActive()){
        timer->stop();
        delete capture;
        capture = NULL;
    }
    //open image and convert to grayscale
    if(grayscale){
        originalImage = cv::imread(path.toStdString());
        if(originalImage.channels()>1){
            cv::cvtColor(originalImage,originalImage,CV_BGR2GRAY);
        }
    }
    else{
        originalImage= cv::imread(path.toStdString());
    }
    //scale image to fit to screen
    if (originalImage.rows > maxHeight)
    {
        double factor = double(maxHeight) / originalImage.rows;
        cv::resize(originalImage,originalImage,cv::Size(),factor,factor);
    }
    if(originalImage.cols > maxWidth)
    {
        double factor = double(maxWidth) /originalImage.cols;
        cv::resize(originalImage,originalImage,cv::Size(),factor,factor);

    }
    updateLayout();
}

void WidgetAufgaben::drawLineOnLabel(QList<double> list, QLabel *label){
    QPixmap pix(500,100);
    double x_scale = pix.width()/(list.length()-1);
    pix.fill();
    QPainter painter((QPaintDevice*)&pix);
    painter.drawRect(0,0,500-1,100-1);
    QLineF lines[list.length()-1];
    double min=std::numeric_limits<double>::max();
    for(int i=0;i<list.length();i++){
        if(list[i]<min) min=list[i];
    }
    if(min<0){
        for(int i=0;i<list.length();i++){
            std::abs(list[i]);
            list[i]+=-min;
        }
    }
    for(int i=0;i<list.length()-1;i++){
        lines[i].setLine(i*x_scale,pix.height() - list[i]*20,(i+1)*x_scale,pix.height() - list[i+1]*20);
    }
    painter.drawLines(lines,list.length()-1);
    label->setPixmap(pix);
}

void WidgetAufgaben::openCamera(){
    capture = new cv::VideoCapture(0); //open camera 0
    if(!capture->isOpened()){
        delete capture;
        capture = NULL;
        return;
    }
    timer->start(1000/30); //acieve 30FPS
    connect(timer,SIGNAL(timeout()),this,SLOT(timerTick()));
}

void WidgetAufgaben::timerTick(){
    if(capture==NULL) return;
    if(!capture->grab()) return;
    timer->stop();
    capture->retrieve(originalImage);
    if(grayscale){
        cv::cvtColor(originalImage,originalImage,CV_BGR2GRAY);
    }
    updateLayout();
    timer->start(30/1000);
}

void WidgetAufgaben::updateLayout(){
    return;
}
