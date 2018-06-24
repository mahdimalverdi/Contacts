#ifndef ADDCONTACTWINDOW_H
#define ADDCONTACTWINDOW_H

#include <QDialog>

namespace Ui {
class AddContactWindow;
}

class AddContactWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddContactWindow(QWidget *parent = 0);
    ~AddContactWindow();

private slots:
    void on_BtnSubmit_clicked();

private:
    Ui::AddContactWindow *ui;
};

#endif // ADDCONTACTWINDOW_H
