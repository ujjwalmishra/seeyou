#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "statediscoverer.h"
#include "peer.h"
#include "peerstate.h"
#include <QVector>
#include "event.h"

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

public slots:
    void addTask();

private:
    Ui::MainWindow *ui;
    StateDiscoverer *discoverer;
    Peer *peer;
    PeerState *pState;
    QVector<Event*> events;
};

#endif // MAINWINDOW_H
