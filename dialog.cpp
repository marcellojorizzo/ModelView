//dialog.cpp

#include "dialog.h"
#include "ui_dialog.h"

// Constructor for the Dialog class
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    // Sets up the user interface from the .ui file
    ui->setupUi(this);

    // Create a new QStringListModel instance
    model = new QStringListModel(this);

    // Initialize a QStringList to store the items
    QStringList list;

    // Add some example items to the list
    list << "cats" << "dogs" << "birds";

    // Set the model's string list with the items
    model->setStringList(list);

    // Set the model for the listView and comboBox widgets
    ui->listView->setModel(model);
    ui->comboBox->setModel(model);

    // Enable editing in the listView by pressing any key or double-clicking an item
    ui->listView->setEditTriggers(QAbstractItemView::AnyKeyPressed | QAbstractItemView::
