#include "seeyouserverthread.h"

#include <QtNetwork>

//! [0]
SeeyouServerThread::SeeyouServerThread(int socketDescriptor, const QString &fortune, QObject *parent)
    : QThread(parent), socketDescriptor(socketDescriptor), text(fortune)
{
}
//! [0]

//! [1]
void SeeyouServerThread::run()
{
    QTcpSocket tcpSocket;
//! [1] //! [2]
    if (!tcpSocket.setSocketDescriptor(socketDescriptor)) {
        emit error(tcpSocket.error());
        return;
    }
//! [2] //! [3]

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << text;
//! [3] //! [4]

    tcpSocket.write(block);
    tcpSocket.disconnectFromHost();
    tcpSocket.waitForDisconnected();
}
//! [4]
