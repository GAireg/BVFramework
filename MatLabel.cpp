/***********************************************************
 *
 * MatLabel.cpp - A Label displaying an OpenCV Matrix
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

#include "MatLabel.h"
#include "ui_matlabel.h"
#include <qdebug.h>


MatLabel::MatLabel(QWidget *parent) :
    QLabel(parent),
    ui(new Ui::MatLabel)
{
    ui->setupUi(this);
}

MatLabel::~MatLabel()
{
    delete ui;
}

QImage MatLabel::convertImage()
{
    double min_,max_;
    minMaxLoc(tmpMat,&min_,&max_);
    // 8-bits unsigned, NO. OF CHANNELS=1
    if(tmpMat.channels()==1)
    {
        if(tmpMat.type()!=CV_8UC1){
            double scale = std::numeric_limits<uchar>::max()/max_;
            tmpMat.convertTo(tmpMat,CV_8UC1,scale,min_<-1?128:0);
            minMaxLoc(tmpMat,&min_,&max_);
        }
        // Set the color table (used to translate colour indexes to qRgb values)
        QVector<QRgb> colorTable;
        colorTable.reserve(300);
        for (int i=0; i<256; i++)
            colorTable.push_back(qRgb(i,i,i));
        // Copy input Mat
        const uchar *qImageBuffer = (const uchar*)tmpMat.data;
        // Create QImage with same dimensions as input Mat
        QImage img(qImageBuffer, tmpMat.cols, tmpMat.rows, tmpMat.step, QImage::Format_Indexed8);
        img.setColorTable(colorTable);
        return img;
    }
    // 8-bits unsigned, NO. OF CHANNELS=3
    if(tmpMat.channels()==3)
    {
        if(tmpMat.type()!=CV_8UC3){
            double scale = std::numeric_limits<uchar>::max()/max_;
            tmpMat.convertTo(tmpMat,CV_8UC3,scale,min_<-1?128:0);
        }
        // Copy input Mat
        const uchar *qImageBuffer = (const uchar*)tmpMat.data;
        // Create QImage with same dimensions as input Mat
        QImage img(qImageBuffer, tmpMat.cols, tmpMat.rows, tmpMat.step, QImage::Format_RGB888);
        return img.rgbSwapped();
    }
    else
    {
        qDebug() << "ERROR: Mat could not be converted to QImage.";
        return QImage();
    }
}

void MatLabel::setMatrix(cv::Mat &mat, bool scale){
    if(mat.empty()) return;
    mat.copyTo(tmpMat);
    scaleImage = scale;
    QImage img = convertImage();
    QPixmap pix = QPixmap::fromImage(img);
    origImage = pix;
    if(scaleImage){
        this->setPixmap(pix.scaled(size(),Qt::KeepAspectRatio));
    }
    else {
        this->setPixmap(pix);
    }
}

void MatLabel::resizeEvent(QResizeEvent *event){
    QLabel::resizeEvent(event);
    if(!origImage.isNull()){
        if(scaleImage){
        this->setPixmap(origImage.scaled(size(),Qt::KeepAspectRatio));
        }
        else{
            this->setPixmap(origImage);
        }
    }
}
