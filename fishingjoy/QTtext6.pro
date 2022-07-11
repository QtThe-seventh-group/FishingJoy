#-------------------------------------------------
#
# Project created by QtCreator 2022-07-06T06:37:10
#
#-------------------------------------------------

QT              += core gui multimedia network
CONFIG += resources_big

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTtext6
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        widget.cpp \
    qbullet.cpp \
    qfish.cpp \
    qgun.cpp \
    qnet.cpp \
    qpixmapitem.cpp \
    easyview.cpp \
    choosewidget.cpp \
    finishwidget.cpp \
    helpchoosewidget.cpp \
    helprulewidget.cpp \
    helpwidget.cpp \
    qpfish.cpp \
    qffish.cpp \
    qbfish.cpp \
    qgfish.cpp \
    goldshopwidget.cpp \
    voice.cpp \
    white.cpp

HEADERS += \
        widget.h \
    qbullet.h \
    qfish.h \
    qgun.h \
    qnet.h \
    qpixmapitem.h \
    easyview.h \
    ui_widget.h \
    choosewidget.h \
    finishwidget.h \
    helpchoosewidget.h \
    helprulewidget.h \
    helpwidget.h \
    qpfish.h \
    qffish.h \
    qbfish.h \
    qgfish.h \
    goldshopwidget.h \
    voice.h \
    white.h

FORMS += \
        widget.ui

RESOURCES += \
    res.qrc
