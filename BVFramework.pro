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
        MainWindow.cpp \
    DialogSelectAufgabe.cpp \
    MatLabel.cpp \
    WidgetAufgaben.cpp \
    WidgetCaptionMatLabel.cpp \
    WidgetAufgabe1.cpp

HEADERS  += mainwindow.h \
    EnumAufgaben.h \
    DialogSelectAufgabe.h \
    MatLabel.h \
    WidgetAufgaben.h \
    WidgetCaptionMatLabel.h \
    WidgetAufgabe1.h

FORMS    += mainwindow.ui \
    DialogSelectAufgabe.ui \
    MatLabel.ui \
    WidgetAufgaben.ui \
    WidgetCaptionMatLabel.ui \
    WidgetAufgabe1.ui

QMAKE_CXXFLAGS += -std=c++11
CONFIG += c++11

LIBS += -lopencv_core
LIBS += -lopencv_imgcodecs
LIBS += -lopencv_imgproc
LIBS += -lopencv_video
LIBS += -lopencv_videoio
LIBS += -lopencv_videostab
LIBS += -lopencv_features2d
LIBS += -lopencv_xfeatures2d
