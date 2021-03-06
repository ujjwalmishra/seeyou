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
CoreApp::CoreApp()
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
    delete myInstance;
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

void CoreApp::addPeer(const PeerInfo &peer)
{
    CoreApp *app = CoreApp::getObject();
    if(app->getPeerInfo()->peerid.toString().compare(peer.peerid.toString()) != 0)
    {
        PeerInfo *peerN = new PeerInfo(peer);
        app->peers.insert(peer.peerid.toString(), peerN);
        PeerBox *box = app->win->addPeerUI(peerN);
        app->peersUI.insert(peer.peerid.toString(), box);
    };

}

void CoreApp::removePeer(QString uid)
{
    CoreApp *app = CoreApp::getObject();
    PeerBox *box = app->peersUI.value(uid);

    app->win->removePeerUI(box);
    app->peersUI.remove(uid);
    QMap<QString, PeerInfo*>::Iterator it = app->peers.find(uid);
    app->peers.erase(it);
    qDebug() << app->peers.size();
}

void CoreApp::addTCPServerID(QString string)
{
    peerInfo->setPeerTCPIP(string);
}

PeerInfo * CoreApp::getPeerInfo()
{
    return peerInfo;
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
    if(app->getPeerInfo()->peerid.toString().compare(task->peerid.toString()) != 0){

        PeerBox *box = app->peersUI.value(task->peerid.toString());

        box->toggleNotif();
    }

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
