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
    ui->listView->setEditTriggers(QAbstractItemView::AnyKeyPressed | QAbstractItemView::DoubleClicked);
}

// Destructor for the Dialog class
Dialog::~Dialog()
{
    // Clean up and delete the UI object
    delete ui;
}

// Slot for adding a new item when the first button is clicked
void Dialog::on_pushButton_clicked()
{
    // Get the current number of rows in the model
    int row = model->rowCount();

    // Insert a new empty row at the end of the list
    model->insertRows(row, 1);

    // Get the index of the new row
    QModelIndex index = model->index(row);

    // Set the newly added row as the current selection in the listView
    ui->listView->setCurrentIndex(index);

    // Open the editor to allow editing the new item
    ui->listView->edit(index);
}

// Slot for inserting a new item above the currently selected one
void Dialog::on_pushButton_2_clicked()
{
    // Get the index of the currently selected item in the listView
    int row = ui->listView->currentIndex().row();

    // Insert a new empty row above the currently selected row
    model->insertRows(row, 1);

    // Get the index of the newly inserted row
    QModelIndex index = model->index(row);

    // Set the newly inserted row as the current selection in the listView
    ui->listView->setCurrentIndex(index);

    // Open the editor to allow editing the new item
    ui->listView->edit(index);
}

// Slot for deleting the currently selected item when the third button is clicked
void Dialog::on_pushButton_3_clicked()
{
    // Remove the row of the currently selected item from the model
    model->removeRows(ui->listView->currentIndex().row(), 1);
}
