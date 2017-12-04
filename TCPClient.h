#ifndef SEEYOUCLIENT_H
#define SEEYOUCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDataStream>

QT_BEGIN_NAMESPACE
class QTcpSocket;
class QNetworkSession;
QT_END_NAMESPACE

//! [0]
class Client : public QObject
{
    Q_OBJECT

public:
    explicit Client(QObject *parent = Q_NULLPTR);

private slots:
    void requestNewFortune(QString host);
    void readFortune();
    void displayError(QAbstractSocket::SocketError socketError);
    void sessionOpened();

private:
    QTcpSocket *tcpSocket;
    QDataStream in;
    QString currentFortune;

    QNetworkSession *networkSession;
};
//! [0]


#endif // SEEYOUCLIENT_H
