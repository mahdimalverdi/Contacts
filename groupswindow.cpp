#include "groupswindow.h"
#include "ui_groupswindow.h"
#include "groupmanager.h"
using namespace std;
GroupsWindow::GroupsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GroupsWindow)
{
    ui->setupUi(this);
    GroupManager gm;
    RefreshContactsList(gm.GetAllGroups());
}

GroupsWindow::~GroupsWindow()
{
    delete ui;
}

void GroupsWindow::RefreshContactsList(QList<Group> g)
{
    ui->tableWidgetGroups->setRowCount(g.size());
    ui->tableWidgetGroups->setColumnCount(2);
    ui->tableWidgetGroups->setHorizontalHeaderItem(0,new QTableWidgetItem("ردیف"));
    ui->tableWidgetGroups->setColumnHidden(0,true);
    ui->tableWidgetGroups->setHorizontalHeaderItem(1,new QTableWidgetItem("نام"));
    int i=0;
    for(auto item:g)
    {
        ui->tableWidgetGroups->setItem(i,0,new QTableWidgetItem(QString::fromStdString(to_string( item.getId()))));
        ui->tableWidgetGroups->setItem(i,1,new QTableWidgetItem( item.getName()));
        i++;
    }
    ui->tableWidgetGroups->resizeColumnsToContents();
    ui->tableWidgetGroups->resizeRowsToContents();
}
