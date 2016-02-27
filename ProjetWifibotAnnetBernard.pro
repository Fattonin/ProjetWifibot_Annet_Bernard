#-------------------------------------------------
#
# Project created by QtCreator 2016-02-26T08:32:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjetWifibotAnnetBernard
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    connexionServeur.cpp \
    connexionClient.cpp

HEADERS  += mainwindow.h \
    connexionServeur.h \
    connexionClient.h

FORMS    += mainwindow.ui
