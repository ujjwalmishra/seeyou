#ifndef EVENT_H
#define EVENT_H

#include <QMainWindow>

namespace Ui {
class Event;
}

class Event : public QMainWindow
{
    Q_OBJECT

public:
    explicit Event(const QString& name, QWidget *parent = 0);
    ~Event();
    void setName(const QString& name);
    QString name() const;

private:
    Ui::Event *ui;
};

#endif // EVENT_H
