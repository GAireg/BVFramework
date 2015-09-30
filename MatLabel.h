#ifndef MATLABEL_H
#define MATLABEL_H

#include <QLabel>
#include <opencv2/core/core.hpp>

namespace Ui {
class MatLabel;
}

class MatLabel : public QLabel
{
    Q_OBJECT

public:
    explicit MatLabel(QWidget *parent = 0);
    ~MatLabel();

    void setMatrix(cv::Mat &mat,bool scale=true);

private:
    Ui::MatLabel *ui;
    cv::Mat tmpMat;
    QImage convertImage();
    QPixmap origImage;
    bool scaleImage;
    void resizeEvent(QResizeEvent *event);
};

#endif // MATLABEL_H
