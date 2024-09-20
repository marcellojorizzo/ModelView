// main.cpp

// Includes the header file for the Dialog class
#include "dialog.h"

// Includes the QApplication class for the Qt application
#include <QApplication>

// The main function where the program starts
int main(int argc, char *argv[])
{
    // Creates a QApplication object, which manages application-wide resources
    QApplication a(argc, argv);

    // Creates an instance of the Dialog class (the main window)
    Dialog w;

    // Shows the main window (Dialog)
    w.show();

    // Enters the application's event loop and waits for user interactions
    return a.exec();
}
