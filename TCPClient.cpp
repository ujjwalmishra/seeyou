

#include <QtWidgets>
#include <QtNetwork>

#include "TCPClient.h"

//! [0]
Client::Client(QObject *parent)
    : QObject(parent)
    , tcpSocket(new QTcpSocket(this))
    , networkSession(Q_NULLPTR)
{

    // find out IP addresses of this machine
//    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
//    // add non-localhost addresses
//    for (int i = 0; i < ipAddressesList.size(); ++i) {
//        if (!ipAddressesList.at(i).isLoopback())
//            hostCombo->addItem(ipAddressesList.at(i).toString());
//    }
//    // add localhost addresses
//    for (int i = 0; i < ipAddressesList.size(); ++i) {
//        if (ipAddressesList.at(i).isLoopback())
//            hostCombo->addItem(ipAddressesList.at(i).toString());
//    }

//    QLabel *hostLabel = new QLabel(tr("&Server name:"));
//    hostLabel->setBuddy(hostCombo);
//    QLabel *portLabel = new QLabel(tr("S&erver port:"));
//    portLabel->setBuddy(portLineEdit);

//! [1]
    in.setDevice(tcpSocket);
    in.setVersion(QDataStream::Qt_4_0);
//! [1]

//    connect(getFortuneButton, &QAbstractButton::clicked,
//            this, &Client::requestNewFortune);
//! [2] //! [3]
    connect(tcpSocket, &QIODevice::readyRead, this, &Client::readFortune);
//! [2] //! [4]
    connect(tcpSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
//! [3]
            this, &Client::displayError);
//! [4]

    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired) {
        // Get saved network configuration
        QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
        settings.endGroup();

        // If the saved network configuration is not currently discovered use the system default
        QNetworkConfiguration config = manager.configurationFromIdentifier(id);
        if ((config.state() & QNetworkConfiguration::Discovered) !=
            QNetworkConfiguration::Discovered) {
            config = manager.defaultConfiguration();
        }

        networkSession = new QNetworkSession(config, this);
        connect(networkSession, &QNetworkSession::opened, this, &Client::sessionOpened);

        networkSession->open();
    }
//! [5]
}
//! [5]

//! [6]
void Client::requestNewFortune(QString host)
{

    tcpSocket->abort();
//! [7]
//!

    tcpSocket->connectToHost(host, 11111);
//! [7]
}
//! [6]

//! [8]
void Client::readFortune()
{
    in.startTransaction();

    QString nextFortune;
    in >> nextFortune;

    if (!in.commitTransaction())
        return;



    currentFortune = nextFortune;
}
//! [8]

//! [13]
void Client::displayError(QAbstractSocket::SocketError socketError)
{
//    switch (socketError) {
//    case QAbstractSocket::RemoteHostClosedError:
//        break;
//    case QAbstractSocket::HostNotFoundError:
////        QMessageBox::information(this, tr("Fortune Client"),
////                                 tr("The host was not found. Please check the "
////                                    "host name and port settings."));
//        break;
//    case QAbstractSocket::ConnectionRefusedError:
////        QMessageBox::information(this, tr("Fortune Client"),
////                                 tr("The connection was refused by the peer. "
////                                    "Make sure the fortune server is running, "
////                                    "and check that the host name and port "
////                                    "settings are correct."));
//        break;
//    default:
////        QMessageBox::information(this, tr("Fortune Client"),
////                                 tr("The following error occurred: %1.")
////                                 .arg(tcpSocket->errorString()));
//    }

}
//! [13]

void Client::sessionOpened()
{
    // Save the used configuration
    QNetworkConfiguration config = networkSession->configuration();
    QString id;
    if (config.type() == QNetworkConfiguration::UserChoice)
        id = networkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
    else
        id = config.identifier();

    QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
    settings.beginGroup(QLatin1String("QtNetwork"));
    settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
    settings.endGroup();

}

