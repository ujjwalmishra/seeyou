#include "event.h"
#include "ui_event.h"

Event::Event(QWidget *parent) :
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

void Task::setName(const QString& name)
{
    ui->checkBox->setText(name);
}

QString Task::name() const
{
    return ui->checkBox->text();
}
