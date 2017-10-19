#ifndef COREAPP_H
#define COREAPP_H

#include "PeerInfo.h"
#include "PeerData.h"
#include "mainwindow.h"
#include "UDPReceiver.h"
#include <QMap>


class CoreApp {

public:
    ~CoreApp();
    void broadCastSelfState(MainWindow &w);
    PeerInfo & getPeerInfo();
    void addPeer(PeerInfo & peer);
    static CoreApp *getObject(MainWindow &w);
    static CoreApp *getObject();

private:
    CoreApp();
    CoreApp(MainWindow &w);
    void initApp(MainWindow &w);
    void initTCPServer(MainWindow &w);
    void initSelfState();
    void initStateReceiver();
    void initTCPClient();
    PeerInfo *peerInfo;
    PeerData *peerData;
    Receiver *rcvr;
    static CoreApp *myInstance;
    QMap<QUuid, PeerInfo> peers;
    //Database
};



#endif // COREAPP_H
