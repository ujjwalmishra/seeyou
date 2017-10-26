#include "statussignal.h"
#include <QPainter>

StatusSignal::StatusSignal(QWidget *parent)
    :QWidget(parent)
{
//    setBackgroundRole(QPalette::Base);
//    setAutoFillBackground(true);
}

QSize StatusSignal::minimumSizeHint() const
{
    return QSize(80, 40);
}

void StatusSignal::paintEvent(QPaintEvent * /* event */)
{
    QRect rect(5, 5, 120, 30);
    QPainter painter(this);
    painter.setPen(Qt::transparent);
    painter.setBrush(brush);
    painter.drawRect(rect);
}

void StatusSignal::setBrush(const QBrush &brush)
{
    this->brush = brush;
    update();
}
