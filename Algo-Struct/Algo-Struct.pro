QT += core
QT -= gui

CONFIG += c++11

TARGET = Algo-Struct
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    list/list.cpp

HEADERS += \
    list/list.h
