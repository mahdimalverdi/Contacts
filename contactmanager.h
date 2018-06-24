#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H
#include <contact.h>
#include <QFile>
#include <qdatastream.h>
#include <QString>
class ContactManager
{
    void WriteToFile();
    void ReadFromFile();
public:
    ContactManager();
    void Add(const Contact& contact);
    void SaveChange();
    QList<Contact> GetAllContacts();
    QList<Contact> SortByFirstName(QList<Contact> l);
    QList<Contact> SortByLastName(QList<Contact> l);
    QList<Contact> Search(QString str);
    Contact Edit(const Contact &conact);
    Contact GetById(const int &Id);
    Contact DeleteById(const int& Id);
protected:
    QString FileAddress;
    QList<Contact> Data;
};


#endif // CONTACTMANAGER_H
