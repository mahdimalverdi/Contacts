#include "contactwindow.h"
#include "ui_contactwindow.h"
#include "contactmanager.h"
#include "editcontactwindow.h"
ContactWindow::ContactWindow(int Id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContactWindow)
{
    ui->setupUi(this);
    ContactManager cm;
    c=cm.GetById(Id);
    ui->LabelFirstNameView->setText(c.GetFirstName());
    ui->LabelLastNameView->setText(c.GetLastName());
    ui->LabelPhoneView->setText(c.GetPhone());
}

ContactWindow::~ContactWindow()
{
    delete ui;
}

void ContactWindow::on_BtnClose_clicked()
{
    this->close();
}

void ContactWindow::on_BtnDelete_clicked()
{
    ContactManager cm;
    cm.DeleteById(c.GetId());
    cm.SaveChange();
    this->close();
}

void ContactWindow::on_BtnEdit_clicked()
{
    EditContactWindow w(c.GetId());
    this->hide();
    w.exec();
    ContactManager cm;
    c=cm.GetById(c.GetId());
    ui->LabelFirstNameView->setText(c.GetFirstName());
    ui->LabelLastNameView->setText(c.GetLastName());
    ui->LabelPhoneView->setText(c.GetPhone());
    this->close();
}
