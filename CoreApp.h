/*
 *Core functionality - Maintains global state of application
 *
 *
 */

#ifndef COREAPP_H
#define COREAPP_H

#include "PeerInfo.h"
#include "PeerData.h"
#include "mainwindow.h"
#include "UDPReceiver.h"
#include "UDPBroadcaster.h"
#include <QMap>
#include <QUuid>
#include "taskinfo.h"
#include "TCPClient.h"
#include <QVector>



class CoreApp
{
public:
    ~CoreApp();    
    static CoreApp *getObject(MainWindow &w, QString name);
    static CoreApp *getObject();
    void broadCastSelfState(MainWindow &w);
    void addPeer(PeerInfo &peer);
    void removePeer(QString uid);
    void addTCPServerID(QString string);  
    void setLatestTask(TaskInfo* task);
    void updateEvent(TaskInfo *task);
    void initTasks(MainWindow &w);
    void checkStuff(QString & uid);
    PeerInfo * getPeerInfo();
    TaskInfo * getLatestTask();
    QMap<QString, PeerInfo*> peers; //Peers PeerInfo objects
    QMap<QString, PeerBox*> peersUI; //Reference to UI Objects to remove later
    QMap<QString, QVector<TaskInfo>> peerTasks; //Peer wise tasks vector list


private:
    CoreApp();
    CoreApp(MainWindow &w, QString name);    
    static CoreApp *myInstance;
    void initApp(MainWindow &w);
    void initTCPServer(MainWindow &w);
    void initSelfState();
    void initStateReceiver();
    void initTCPClient();
    QUuid getUidFromFile();
    void writeUidToFile(QUuid uid);    
    MainWindow *win;
    QString appUIDFile;
    QString username;
    PeerInfo *peerInfo;
    PeerData *peerData;
    Receiver *rcvr;
    TaskInfo *latestTask;
    UDPBroadcaster * discoverer;
};



#endif // COREAPP_H
