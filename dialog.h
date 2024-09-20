//dialog.h

#ifndef DIALOG_H
#define DIALOG_H

// Include the QDialog class for creating dialog windows
#include <QDialog>

// Include core functionality (e.g., data models, event handling)
#include <QtCore>

// Include graphical components and functionalities (e.g., drawing, rendering)
#include <QtGui>

// Start the Qt namespace block for forward declarations
QT_BEGIN_NAMESPACE

// Declare the Ui namespace and the Dialog class inside it
namespace Ui {
class Dialog;
}

// End the Qt namespace block
QT_END_NAMESPACE

// Declare the Dialog class that inherits from QDialog to create a custom dialog window
class Dialog : public QDialog
{
    // Enable signals and slots mechanism in this class
    Q_OBJECT

public:
    // Constructor: Initializes the dialog with an optional parent widget
    Dialog(QWidget *parent = nullptr);

    // Destructor: Cleans up when the Dialog object is destroyed
    ~Dialog();

private slots:
    // Slot function triggered when the first button is clicked
    void on_pushButton_clicked();

    // Slot function triggered when the second button is clicked
    void on_pushButton_2_clicked();

    // Slot function triggered when the third button is clicked
    void on_pushButton_3_clicked();

private:
    // Pointer to the user interface components designed in Qt Designer
    Ui::Dialog *ui;

    // Pointer to a QStringListModel, used to store and manipulate a list of strings
    QStringListModel *model;
};

// End the include guard to avoid multiple inclusions of the same header file
#endif // DIALOG_H

