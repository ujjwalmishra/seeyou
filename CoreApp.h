#ifndef COREAPP_H
#define COREAPP_H

#include "PeerInfo.h"
#include "PeerData.h"
#include "mainwindow.h"
#include "UDPReceiver.h"
#include "UDPBroadcaster.h"
#include <QMap>
#include <QUuid>


class CoreApp : public QObject
{
    Q_OBJECT
public:
    ~CoreApp();
    void broadCastSelfState(MainWindow &w);
    PeerInfo & getPeerInfo();
    void addPeer(PeerInfo *peer);
    void addTCPServerID(QString string);
    static CoreApp *getObject(MainWindow &w, QString name);
    static CoreApp *getObject();
    QMap<QString, PeerInfo*> peers;

public slots:
    //void checkLogin(QString&, QString&);

private:
    CoreApp(QObject *parent = 0);
    CoreApp(MainWindow &w, QString name);
    void initApp(MainWindow &w);
    void initTCPServer(MainWindow &w);
    void initSelfState();
    MainWindow *win;
    void initStateReceiver();
    void initTCPClient();
    QUuid getUidFromFile();
    void writeUidToFile(QUuid uid);
    QString appUIDFile;
    QString username;
    PeerInfo *peerInfo;
    PeerData *peerData;
    Receiver *rcvr;
    static CoreApp *myInstance;
    UDPBroadcaster * discoverer;
    //Database
};



#endif // COREAPP_H
