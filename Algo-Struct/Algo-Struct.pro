QT += core
QT -= gui

CONFIG += c++11

TARGET = Algo-Struct
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

DEFINES += ELPP_QT_LOGGING    \
          ELPP_FEATURE_ALL \
          ELPP_STL_LOGGING   \
          ELPP_STRICT_SIZE_CHECK ELPP_UNICODE \
          ELPP_MULTI_LOGGER_SUPPORT \
          ELPP_THREAD_SAFE

SOURCES += main.cpp \
    list/list.cpp \
    sort/sort.cpp \
    easylogging++.cc \
    gloabl.cpp

HEADERS += \
    list/list.h \
    sort/sort.h \
    easylogging++.h \
    gloabl.h
