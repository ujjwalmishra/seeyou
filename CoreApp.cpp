#include "CoreApp.h"
#include "PeerInfo.h"
#include "PeerData.h"
#include "mainwindow.h"
#include "TCPServer.h"
#include "CoreApp.h"
#include "UDPReceiver.h"
#include <QFile>

CoreApp * CoreApp::myInstance = nullptr;
CoreApp::CoreApp(QObject *parent)
    : QObject(parent)
{

}

CoreApp::CoreApp(MainWindow &w)
{
    initApp(w);
}

CoreApp::~CoreApp()
{
    delete peerInfo;
    delete peerData;
}

CoreApp* CoreApp::getObject(MainWindow &w)
{
    if(myInstance) {
        return myInstance;
    }
    else {
        myInstance = new CoreApp(w);
        return myInstance;
    }
};

CoreApp* CoreApp::getObject()
{
    return myInstance;
}

void CoreApp::initApp(MainWindow &w)
{
    appUIDFile = "./app.txt";
    initSelfState();
    initTCPServer(w);
    initStateReceiver();
    broadCastSelfState(w);
}

void CoreApp::addPeer(PeerInfo &peer)
{
    if(peerInfo->peerid != peer.peerid){
        peers.insert(peer.peerid, peer);
    }
}

void CoreApp::addTCPServerID(QString string)
{
    peerInfo->setPeerTCPIP(string);
}

PeerInfo & CoreApp::getPeerInfo()
{
    return *peerInfo;
}

void CoreApp::broadCastSelfState(MainWindow &w)
{
    w.initBroadCastPeerState();
}

void CoreApp::initTCPServer(MainWindow &w)
{
    SeeyouServer server;
    ServerConn conn = server.connectToPort();

    if(conn.flag) {
        w.statusText = conn.message;
        w.brush = QBrush(Qt::green);
        addTCPServerID(conn.serverip);
    }
    else {
        w.statusText = conn.message;
        w.brush = QBrush(Qt::red);
    }
    w.addLayouts();
}

void CoreApp::checkLogin(QString &user, QString &pass)
{
    qDebug() << user;
    qDebug() << pass;
}

void CoreApp::initSelfState()
{
    QUuid uid = getUidFromFile();
    qDebug() << uid;
    peerInfo = new PeerInfo();
    if(!uid.isNull()) {
        peerInfo->peerid = uid;
    }
    else {
        peerInfo->generatePeerId();
        writeUidToFile(peerInfo->peerid);
    }

    peerInfo->setPeerState(PeerState::INITIALIZED);
}

QUuid CoreApp::getUidFromFile()
{
    QUuid uid;
    QFile file(appUIDFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return uid;

    QDataStream in(&file);
    in >> uid;
    file.close();
    return uid;
}

void CoreApp::writeUidToFile(QUuid uid)
{
    QFile file(appUIDFile);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QDataStream out(&file);
    out << uid;
    file.flush();
    file.close();
}

void CoreApp::initStateReceiver()
{
    rcvr = new Receiver();
    rcvr->init();
}

void CoreApp::initTCPClient()
{

}
