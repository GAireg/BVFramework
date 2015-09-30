#-------------------------------------------------
#
# Project created by QtCreator 2014-11-27T14:13:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BVFramework
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialogselectaufgabe.cpp \
    matlabel.cpp \
    widgetaufgaben.cpp \
    widgetcaptionmatlabel.cpp \
    WidgetAufgabe1.cpp

HEADERS  += mainwindow.h \
    EnumAufgaben.h \
    dialogselectaufgabe.h \
    matlabel.h \
    widgetaufgaben.h \
    widgetcaptionmatlabel.h \
    WidgetAufgabe1.h

FORMS    += mainwindow.ui \
    dialogselectaufgabe.ui \
    matlabel.ui \
    widgetaufgaben.ui \
    widgetcaptionmatlabel.ui \
    WidgetAufgabe1.ui

QMAKE_CXXFLAGS += -std=c++11
CONFIG += c++11

LIBS += -lopencv_calib3d
LIBS += -lopencv_contrib
LIBS += -lopencv_core
LIBS += -lopencv_features2d
LIBS += -lopencv_flann
LIBS += -lopencv_highgui
LIBS += -lopencv_imgproc
LIBS += -lopencv_legacy
LIBS += -lopencv_ml
LIBS += -lopencv_objdetect
LIBS += -lopencv_photo
LIBS += -lopencv_stitching
LIBS += -lopencv_superres
LIBS += -lopencv_video
LIBS += -lopencv_videostab
