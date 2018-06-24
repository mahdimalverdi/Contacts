#include "editcontactwindow.h"
#include "ui_editcontactwindow.h"
#include "contactmanager.h"
EditContactWindow::EditContactWindow(int Id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditContactWindow)
{
    ui->setupUi(this);
    ContactManager cm;
    c=cm.GetById(Id);
    ui->TxtFirstName->setText(c.GetFirstName());
    ui->TxtLastName->setText(c.GetLastName());
    ui->TxtPhone->setText(c.GetPhone());
}

EditContactWindow::~EditContactWindow()
{
    delete ui;
}

void EditContactWindow::on_BtnSubmit_clicked()
{

    ContactManager cm;
    c.SetFirstName(ui->TxtFirstName->text());
    c.SetLastName(ui->TxtLastName->text());
    c.SetPhone(ui->TxtPhone->text());
    cm.Edit(c);
    cm.SaveChange();
    this->close();
}
