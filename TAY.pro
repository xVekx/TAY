#-------------------------------------------------
#
# Project created by QtCreator 2015-03-11T23:11:06
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 003
TEMPLATE = app


SOURCES += main.cpp\
        mw.cpp \
    core/point.cpp \
    core/box.cpp \
    core/net.cpp \
    core/examples.cpp \
    core/scheme.cpp


HEADERS  += mw.h \
    core/point.h \
    core/box.h \
    core/net.h \
    core/examples.h \
    core/scheme.h

FORMS    += mw.ui

OTHER_FILES +=
