QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = linkhelp-liu
TEMPLATE = app
CONFIG += c++11 link_pkgconfig
PKGCONFIG += dtkwidget

SOURCES += \
        main.cpp \
    Mainhelpothers.cpp \
    Mainneedhelp.cpp \
    Mainselect.cpp

RESOURCES +=         resources.qrc

HEADERS += \
    Mainhelpothers.h \
    Mainneedhelp.h \
    Mainselect.h
