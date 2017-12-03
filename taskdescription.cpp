#include "taskdescription.h"
#include <QApplication>

TaskDescription::TaskDescription(QWidget *parent) :
 QDialog(parent)
{
 setUpGUI();
 setWindowTitle( tr("Enter task description") );
 setModal( true );
 resize(600, 150);
}

void TaskDescription::setUpGUI(){
 // set up the layout
 formGridLayout = new QGridLayout( );


 editDescription = new QPlainTextEdit( this );

// initialize the labels
 labelDescription = new QLabel( this );
 labelDescription->setText( tr( "Description" ) );
 labelDescription->setBuddy( editDescription );

// initialize buttons
 buttons = new QDialogButtonBox( this );
 buttons->addButton( QDialogButtonBox::Ok );
 buttons->addButton( QDialogButtonBox::Cancel );
 buttons->button( QDialogButtonBox::Ok )->setText( tr("Enter") );
 buttons->button( QDialogButtonBox::Cancel )->setText( tr("Abort") );

 // connects slots
 connect( buttons->button( QDialogButtonBox::Cancel ),
 SIGNAL (clicked()),
 this,
 SLOT (quitDialog())
 );

 //quit app on closing the login dialog


connect( buttons->button( QDialogButtonBox::Ok ),
 SIGNAL (clicked()),
 this,
 SLOT (slotAcceptDescription()) );

// place components into the dialog
 formGridLayout->addWidget( labelDescription, 0, 0 );
 formGridLayout->addWidget( editDescription, 0, 1 );
 formGridLayout->addWidget( buttons, 2, 0, 1, 2 );

setLayout( formGridLayout );

}

void TaskDescription::setDescription(QString description){

 editDescription->setFocus();
}

//bool TaskDescription::getGo(){
//    return logStatus;
//}

QString TaskDescription::getDescription()
{
    return description;
}

void TaskDescription::quitDialog(){
    description = "";
    close();
}

void TaskDescription::slotAcceptDescription(){
    description = editDescription->toPlainText();
    qDebug() << description;
    close();
}

