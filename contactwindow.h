#ifndef CONTACTWINDOW_H
#define CONTACTWINDOW_H

#include <QDialog>
#include "contact.h"
namespace Ui {
class ContactWindow;
}

class ContactWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ContactWindow(int Id, QWidget *parent = 0);
    ~ContactWindow();

private slots:
    void on_BtnClose_clicked();

    void on_BtnDelete_clicked();

    void on_BtnEdit_clicked();

private:
    Contact c;
    Ui::ContactWindow *ui;
};

#endif // CONTACTWINDOW_H
