#-------------------------------------------------
#
# Project created by QtCreator 2017-09-29T19:37:34
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SeeYou
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    Event.cpp \
    PeerInfo.cpp \
    PeerData.cpp \
    TCPClient.cpp \
    TCPServer.cpp \
    ServerThreader.cpp \
    UDPBroadcaster.cpp \
    UDPReceiver.cpp \
    PeerEvent.cpp \
    CoreApp.cpp \
    peerstate.cpp \
    statussignal.cpp \
    logindialog.cpp

HEADERS += \
        mainwindow.h \
    TCPServer.h \
    CoreApp.h \
    Event.h \
    TCPClient.h \
    PeerInfo.h \
    ServerThreader.h \
    UDPBroadcaster.h \
    PeerData.h \
    UDPReceiver.h \
    Database.h \
    PeerEvent.h \
    PeerState.h \
    statussignal.h \
    logindialog.h \
    peerbox.h

FORMS += \
        mainwindow.ui \
    event.ui

RESOURCES += \
    resources.qrc
