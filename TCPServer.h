

#ifndef SEEYOUSERVER_H
#define SEEYOUSERVER_H

#include <QStringList>
#include <QTcpServer>

struct ServerConn{
    const char* message;
    bool flag;
    QString serverip;
};

//! [0]
class SeeyouServer : public QTcpServer
{
    Q_OBJECT

public:
     SeeyouServer(QObject *parent = 0);

protected:
    void incomingConnection(qintptr socketDescriptor) override;

public:
    ServerConn connectToPort();

private:
    QStringList fortunes;
};
//! [0]

#endif
