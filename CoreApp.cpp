#include "CoreApp.h"
#include "PeerInfo.h"
#include "PeerData.h"
#include "mainwindow.h"
#include "TCPServer.h"
#include "CoreApp.h"
#include "UDPReceiver.h"

CoreApp * CoreApp::myInstance = nullptr;
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
        w.setCheckBox( conn.flag);
        w.setProgressBar(conn.flag);
    }
}

void CoreApp::initSelfState()
{
    peerInfo = new PeerInfo();
    peerInfo->generatePeerId();
    peerInfo->setPeerState(PeerState::INITIALIZED);
}

void CoreApp::initStateReceiver()
{
    rcvr = new Receiver();
    rcvr->init();
}

void CoreApp::initTCPClient()
{

}
