#ifndef SEEYOUSERVERTHREAD_H
#define SEEYOUSERVERTHREAD_H
#include <QThread>
#include <QTcpSocket>

//! [0]
class SeeyouServerThread : public QThread
{
    Q_OBJECT

public:
    SeeyouServerThread(int socketDescriptor, const QString &fortune, QObject *parent);

    void run() override;

signals:
    void error(QTcpSocket::SocketError socketError);

private:
    int socketDescriptor;
    QString text;
};
//! [0]


#endif // SEEYOUSERVERTHREAD_H
