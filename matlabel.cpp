#include "matlabel.h"
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
    this->setPixmap(pix.scaled(size(),Qt::KeepAspectRatio));
}

void MatLabel::resizeEvent(QResizeEvent *event){
    QLabel::resizeEvent(event);
    if(!origImage.isNull()){
        this->setPixmap(origImage.scaled(size(),Qt::KeepAspectRatio));
    }
}
