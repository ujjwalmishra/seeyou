#include "CoreApp.h"
#include "PeerInfo.h"
#include "PeerData.h"
#include "mainwindow.h"
#include "TCPServer.h"


CoreApp::CoreApp()
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

void CoreApp::initApp(MainWindow &w)
{
    initSelfState();
    initTCPServer(w);
    broadCastSelfState(w);
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
        w.setCheckBox( conn.flag);
        w.setProgressBar(conn.flag);
    }
}

void CoreApp::initSelfState()
{

}

void CoreApp::initStateReceiver()
{
   //  w.initReciever();
}

void CoreApp::initTCPClient()
{

}
