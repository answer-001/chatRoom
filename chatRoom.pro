#-------------------------------------------------
#
# Project created by QtCreator 2026-04-07T19:46:28
#
#-------------------------------------------------

QT       += core gui network texttospeech sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chatRoom
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        chatroom.cpp \
    flash.cpp \
    register.cpp \
    rollitem.cpp \
    login.cpp \
    sqlite.cpp \
    rollpix.cpp \
    chatlist.cpp \
    userform.cpp

HEADERS += \
        chatroom.h \
    flash.h \
    register.h \
    rollitem.h \
    login.h \
    sqlite.h \
    rollpix.h \
    chatlist.h \
    userform.h

FORMS += \
        chatroom.ui \
    flash.ui \
    register.ui \
    login.ui \
    chatlist.ui \
    userform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
