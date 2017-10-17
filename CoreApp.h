#ifndef COREAPP_H
#define COREAPP_H

#include "PeerInfo.h"
#include "PeerData.h"
#include "mainwindow.h"


class CoreApp {

public:
    CoreApp();
    CoreApp(MainWindow &w);
    ~CoreApp();
    void broadCastSelfState(MainWindow &w);

private:
    void initApp(MainWindow &w);
    void initTCPServer(MainWindow &w);
    void initSelfState();
    void initStateReceiver();
    void initTCPClient();
    PeerInfo *peerInfo;
    PeerData *peerData;
    //Database
};



#endif // COREAPP_H
