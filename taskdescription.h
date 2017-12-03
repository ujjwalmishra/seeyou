#ifndef TASKDESCRIPTION_H
#define TASKDESCRIPTION_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QPlainTextEdit>
#include <QComboBox>
#include <QGridLayout>
#include <QStringList>
#include <QDebug>
#include "mainwindow.h"

/*!
 '''Makes class LoginDialog a child to its parent, QDialog
*/
class TaskDescription : public QDialog
{
/*!
 '''Turns Login Dialog into a QObject
*/
 Q_OBJECT

private:
 /*!
 * A label for the description component.
 */
 QLabel *labelDescription;


/*!
 * A field to let the user enters task description.
 */
 QPlainTextEdit  *editDescription;

/*!
 * The standard dialog button box.
 */
 QDialogButtonBox *buttons;

 QGridLayout *formGridLayout;

/*!
 * A method to set up all dialog components and
 * initialize them.
 */
 void setUpGUI();

public:
 explicit TaskDescription(QWidget *parent = 0);


 void setDescription( QString username );
 QString getDescription();

 bool getGo();

signals:

/*!
 * A signal emitted when descriptioni is added
 */
// void acceptDescription( QString& description );

public slots:
 /*!
 * A lot to adjust the emitting of the signal.
 */
 void quitDialog();
 void slotAcceptDescription();

private:
    QString description;
};


#endif // TASKDESCRIPTION_H
