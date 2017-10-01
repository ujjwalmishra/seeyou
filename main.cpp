#include "mainwindow.h"
#include "seeyouclient.h"
#include "seeyouserver.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    w.show();
    SeeyouServer server;
    ServerConn conn = server.connectToPort();

    if(conn.flag) {
        w.setCheckBox( conn.flag);
        w.setProgressBar(conn.flag);
    }
    w.initBroadCastPeerState();

    return a.exec();
}
