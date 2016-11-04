#-------------------------------------------------
#
# Project created by QtCreator 2016-11-01T12:26:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Calculator
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    numberbutton.cpp \
    operationbutton.cpp \
    operationbuttonadd.cpp \
    operationbuttonnegate.cpp \
    operationbuttondivision.cpp \
    operationbuttonmultiplication.cpp

HEADERS  += widget.h \
    numberbutton.h \
    operationbutton.h \
    operationbuttonadd.h \
    operationbuttonnegate.h \
    operationbuttondivision.h \
    operationbuttonmultiplication.h
