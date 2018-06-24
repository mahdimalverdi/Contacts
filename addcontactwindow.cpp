#include "addcontactwindow.h"
#include "ui_addcontactwindow.h"
#include "contactmanager.h"
AddContactWindow::AddContactWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddContactWindow)
{
    ui->setupUi(this);
}

AddContactWindow::~AddContactWindow()
{
    delete ui;
}

void AddContactWindow::on_BtnSubmit_clicked()
{
    ContactManager cm;
    Contact c;
    c.SetFirstName(ui->TxtFirstName->text());
    c.SetLastName(ui->TxtLastName->text());
    c.SetPhone(ui->TxtPhone->text());
    cm.Add(c);
    cm.SaveChange();
    this->close();
}
