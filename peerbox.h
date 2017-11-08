#ifndef PEERBOX_H
#define PEERBOX_H
#include <QWidget>
#include <QString>
#include <QPushButton>
#include <QHBoxLayout>

class PeerBox : public QWidget
{

    Q_OBJECT

    public:
        explicit PeerBox(QWidget *parent = 0);
        void init(QString name);
        void addButtons();
        void showButtons();
        void paintEvent(QPaintEvent *e) override;

    public slots:
        void removePeer();
        void viewPeer();

    private:
        QPushButton *viewPeerButton;
        QPushButton *removePeerButton;
        QString peername;
        QHBoxLayout *gridLayout;

};

#endif // PEERBOX_H
