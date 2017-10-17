#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "UDPBroadcaster.h"
#include "PeerInfo.h"
#include "PeerData.h"
#include <QVector>
#include "Event.h"
#include "UDPReceiver.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool setCheckBox( bool flag);
    bool setProgressBar(bool flag);
    Ui::MainWindow getUIObject();
    void initBroadCastPeerState();
    void initPeerState();
    void initPeer();
    void initReciever();

public slots:
    void addTask();

private:
    Ui::MainWindow *ui;
 //   StateDiscoverer *discoverer;
    PeerState *pState;
//    QVector<Event*> events;
    Receiver *rcvr;
};

#endif // MAINWINDOW_H
