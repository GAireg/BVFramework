/***********************************************************
 *
 * WidgetCaptionMatLabel.h - A MatLabel with a Caption
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
    void setMatrix(cv::Mat matrix, bool scale = false);
    void setCaption(QString text);

private:
    Ui::WidgetCaptionMatLabel *ui;
};

#endif // WIDGETCAPTIONMATLABEL_H
