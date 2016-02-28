#-------------------------------------------------
#
# Project created by QtCreator 2016-02-28T08:19:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = calculator
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    parser.cpp

HEADERS  += widget.h \
    parser.h

FORMS    += widget.ui
