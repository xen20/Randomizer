#-------------------------------------------------
#
# Project created by QtCreator 2017-08-23T22:36:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Randomizer
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
    src/messagedialog.cpp \
    src/progressbar.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/folderbrowser.cpp \
    src/folderhistory.cpp \
    src/folderrandomizer.cpp \
    src/browseparameters.cpp \
    src/settings.cpp \
    src/fonthandler.cpp \
    src/filecopyfunctions.cpp \
    src/movieplayerwidget.cpp

HEADERS += \
    src/messagedialog.h \
    src/progressbar.h \
    src/mainwindow.h \
    src/folderbrowser.h \
    src/folderhistory.h \
    src/folderrandomizer.h \
    src/browseparameters.h \
    src/settings.h \
    src/fonthandler.h \
    src/filecopyfunctions.h \
    src/movieplayerwidget.h

FORMS += \
    mainwindow.ui \
    messagedialog.ui \
    movieplayerwidget.ui \
    progressbar.ui

RESOURCES += \
    resources.qrc
