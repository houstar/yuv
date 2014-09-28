#-------------------------------------------------
#
# Project created by QtCreator 2014-09-25T20:42:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = yuv
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    yuv2rgb16tab.c \
    yuv420rgb888c.c

HEADERS  += widget.h \
    yuv2rgb.h

FORMS    += widget.ui
