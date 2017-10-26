#ifndef STATUSSIGNAL_H
#define STATUSSIGNAL_H
#include <QWidget>
#include <QBrush>


class StatusSignal: public QWidget
{
    Q_OBJECT

public:
    StatusSignal(QWidget *parent = 0);
    void setBrush(const QBrush &brush);
    QSize minimumSizeHint() const override;

protected:
    void paintEvent(QPaintEvent *event) override;

private:

    QBrush brush;

};

#endif // STATUSSIGNAL_H
