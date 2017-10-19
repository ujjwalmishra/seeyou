

#include "TCPServer.h"
#include "ServerThreader.h"
#include <QtNetwork>
#include <stdlib.h>

//! [0]
SeeyouServer::SeeyouServer(QObject *parent)
    : QTcpServer(parent)
{

}
//! [0]

//! [1]
void SeeyouServer::incomingConnection(qintptr socketDescriptor)
{
    SeeyouServerThread *thread = new SeeyouServerThread(socketDescriptor, this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}

ServerConn SeeyouServer::connectToPort()
{
    if (!this->listen(QHostAddress::Any, 11111)) {
//        QMessageBox::critical(this, tr("Threaded Fortune Server"),
//                              tr("Unable to start the server: %1.")
//                              .arg(server.errorString()));
        close();
        struct ServerConn conn;
        conn.flag = false;
        conn.message = "Unable to start the server";
        return conn;
    }

    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    // if we did not find one, use IPv4 localhost
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
        struct ServerConn conn;
        conn.flag = true;
        conn.message = "Server is up and running";
        qDebug() << ipAddress;
        return conn;
//    statusLabel->setText(tr("The server is running on\n\nIP: %1\nport: %2\n\n"
//                            "Run the Fortune Client example now.")
//                         .arg(ipAddress).arg(server.serverPort()));

}
//! [2]
