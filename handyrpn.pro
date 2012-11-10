#-------------------------------------------------
#
# Project created by QtCreator 2012-11-10T08:39:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = handyrpn
TEMPLATE = app


SOURCES += main.cpp\
        rpnwidget.cpp \
    rpncalc.cpp \
    rpnlineedit.cpp

HEADERS  += rpnwidget.h \
    rpncalc.h \
    rpnlineedit.h

FORMS    += rpnwidget.ui
