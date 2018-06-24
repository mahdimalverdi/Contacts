#ifndef EDITCONTACTWINDOW_H
#define EDITCONTACTWINDOW_H

#include <QDialog>
#include "contact.h"

namespace Ui {
class EditContactWindow;
}

class EditContactWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditContactWindow(int Id,QWidget *parent = 0);
    ~EditContactWindow();

private slots:
    void on_BtnSubmit_clicked();

private:
    Contact c;
    Ui::EditContactWindow *ui;
};

#endif // EDITCONTACTWINDOW_H
