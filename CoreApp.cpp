#include "CoreApp.h"
#include "PeerInfo.h"
#include "PeerData.h"
#include "mainwindow.h"
#include "TCPServer.h"
#include "CoreApp.h"
#include "UDPReceiver.h"
#include <QFile>
#include <QString>

CoreApp * CoreApp::myInstance = nullptr;
CoreApp::CoreApp(QObject *parent)
    : QObject(parent)
{

}

CoreApp::CoreApp(MainWindow &w, QString name)
{
    username = name;
    win = &w;
    initApp(w);
}

CoreApp::~CoreApp()
{
    delete peerInfo;
    delete peerData;
}

CoreApp* CoreApp::getObject(MainWindow &w, QString name)
{
    if(myInstance) {
        return myInstance;
    }
    else {
        myInstance = new CoreApp(w, name);

        return myInstance;
    }
}

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
    initTasks(w);
}

void CoreApp::addPeer(PeerInfo *peer)
{
    CoreApp *app = CoreApp::getObject();
    if(app->getPeerInfo().peerid.toString().compare(peer->peerid.toString()) != 0){
        peers.insert(peer->peerid.toString(), peer);
    };
    app->peers.insert(peer->peerid.toString(), peer);
    PeerBox *box = app->win->addPeerUI(peer);
    app->peersUI.insert(peer->peerid.toString(), box);
}

void CoreApp::addTCPServerID(QString string)
{
    peerInfo->setPeerTCPIP(string);
}

PeerInfo & CoreApp::getPeerInfo()
{
    return *peerInfo;
}

void CoreApp::initTasks(MainWindow &w)
{
    w.populateTasks(peerInfo->peerid);
    //add empty task array map
    QVector<TaskInfo> vector;
    peerTasks.insert(peerInfo->peerid.toString(), vector);
}

TaskInfo* CoreApp::getLatestTask()
{
     return latestTask;
}

void CoreApp::setLatestTask(TaskInfo *task)
{
    latestTask = task;
}

void CoreApp::updateEvent(TaskInfo *task)
{
    CoreApp *app = CoreApp::getObject();
    qDebug() << "got here";
    qDebug() << app->peersUI.value(task->peerid.toString());
    PeerBox *box = app->peersUI.value(task->peerid.toString());
    qDebug() << "0.12";
    qDebug() << task->peerid.toString();
    box->toggleNotif();
    qDebug() << "updating event";
}

void CoreApp::broadCastSelfState(MainWindow &w)
{
   w.initBroadCaster();
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

void CoreApp::initSelfState()
{
    QUuid uid = getUidFromFile();
    peerInfo = new PeerInfo();
    peerInfo->setPeerName(username);
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
