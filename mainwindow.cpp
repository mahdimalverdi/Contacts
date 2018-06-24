#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "contactmanager.h"
#include "contactwindow.h"
#include "addcontactwindow.h"
#include <iostream>
#include <string>
#include "groupswindow.h"
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ContactManager cm;
    RefreshContactsList(cm.SortByLastName(cm.GetAllContacts()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BtnAddContact_clicked()
{
    AddContactWindow w;
    this->hide();
    w.exec();
    ContactManager cm;
    RefreshContactsList(cm.SortByLastName(cm.GetAllContacts()));
    this->show();

}

void MainWindow::RefreshContactsList(QList<Contact> c)
{
    ui->tableWidgetContacts->setRowCount(c.size());
    ui->tableWidgetContacts->setColumnCount(2);
    ui->tableWidgetContacts->setHorizontalHeaderItem(0,new QTableWidgetItem("ردیف"));
    ui->tableWidgetContacts->setColumnHidden(0,true);
    ui->tableWidgetContacts->setHorizontalHeaderItem(1,new QTableWidgetItem("نام و نام خانوادگی"));
    int i=0;
    for(auto item:c)
    {
        ui->tableWidgetContacts->setItem(i,0,new QTableWidgetItem(QString::fromStdString(to_string( item.GetId()))));
        ui->tableWidgetContacts->setItem(i,1,new QTableWidgetItem(item.GetLastName()+" ، "+ item.GetFirstName()));
        i++;
    }
    ui->tableWidgetContacts->resizeColumnsToContents();
    ui->tableWidgetContacts->resizeRowsToContents();
}

void MainWindow::on_TxtSearchBox_textChanged(const QString &arg1)
{
    ContactManager cm;
    RefreshContactsList(cm.SortByLastName(cm.Search(ui->TxtSearchBox->text())));
}

void MainWindow::on_tableWidgetContacts_cellDoubleClicked(int row, int column)
{
}

void MainWindow::on_tableWidgetContacts_cellClicked(int row, int column)
{
    ContactWindow cw((*ui->tableWidgetContacts->item(row,0)).text().toInt());
    this->hide();
    cw.exec();
    ContactManager cm;
    RefreshContactsList(cm.SortByLastName(cm.Search(ui->TxtSearchBox->text())));
    this->show();
}

void MainWindow::on_BtnGroups_clicked()
{
    GroupsWindow gw;
    this->hide();
    gw.exec();
    this->show();
}
