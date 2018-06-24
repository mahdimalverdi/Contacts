#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <contact.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void RefreshContactsList(QList<Contact> c);
private slots:
    void on_BtnAddContact_clicked();

    void on_TxtSearchBox_textChanged(const QString &arg1);

    void on_tableWidgetContacts_cellDoubleClicked(int row, int column);

    void on_tableWidgetContacts_cellClicked(int row, int column);

    void on_BtnGroups_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
