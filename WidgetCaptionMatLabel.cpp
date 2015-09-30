#include "WidgetCaptionMatLabel.h"
#include "ui_widgetcaptionmatlabel.h"

WidgetCaptionMatLabel::WidgetCaptionMatLabel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetCaptionMatLabel)
{
    ui->setupUi(this);
}

WidgetCaptionMatLabel::~WidgetCaptionMatLabel()
{
    delete ui;
}

void WidgetCaptionMatLabel::setCaption(QString text){
    ui->labelText->setText(text);
}

void WidgetCaptionMatLabel::setMat(cv::Mat matrix){
    ui->labelImg->setMatrix(matrix);
}
