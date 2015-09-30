/***********************************************************
 *
 * MatLabel.h - A Label for displaying an OpenCV Mat
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
