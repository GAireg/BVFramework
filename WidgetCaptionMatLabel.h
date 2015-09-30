#ifndef WIDGETCAPTIONMATLABEL_H
#define WIDGETCAPTIONMATLABEL_H

#include <QWidget>
#include <opencv2/opencv.hpp>

namespace Ui {
class WidgetCaptionMatLabel;
}

class WidgetCaptionMatLabel : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetCaptionMatLabel(QWidget *parent = 0);
    ~WidgetCaptionMatLabel();
    void setMat(cv::Mat matrix);
    void setCaption(QString text);

private:
    Ui::WidgetCaptionMatLabel *ui;
};

#endif // WIDGETCAPTIONMATLABEL_H
