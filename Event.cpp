#include "Event.h"
#include "ui_event.h"

Event::Event(const QString& name, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Event)
{
    ui->setupUi(this);
    setName(name);
}

Event::~Event()
{
    delete ui;
}

void Event::setName(const QString& name)
{
    ui->label->setText(name);
}

QString Event::name() const
{
    return ui->label->text();
}
