#include "contactmanager.h"
#include <QtAlgorithms>
#include <algorithm>
using namespace std;

QDataStream & operator <<(QDataStream & out,const Contact & c)
{
    return out<<c.Id<<c.FirstName<<c.LastName<<c.Phone;
}
QDataStream & operator >>(QDataStream & in, Contact & c)
{
    return in>>c.Id>>c.FirstName>>c.LastName>>c.Phone;
}

ContactManager::ContactManager()
{
    this->FileAddress="Contacts.dat";
    ReadFromFile();
}

void ContactManager::Add(const Contact &contact)
{
    int Id=1;
    if(!Data.empty())
        Id=Data.back().GetId()+1;
    Contact c(Id,contact.GetFirstName(),contact.GetLastName(),contact.GetPhone());
    Data.push_back(c);
}

void ContactManager::WriteToFile()
{
    QFile file(FileAddress);
    QDataStream dStream(&file);
    file.open(QIODevice::WriteOnly);
    dStream<<Data;
    file.close();
}

void ContactManager::ReadFromFile()
{
    QFile file(FileAddress);
    QDataStream dStream(&file);
    file.open(QIODevice::ReadOnly);
    dStream>>Data;
    file.close();
}

void ContactManager::SaveChange()
{
    WriteToFile();
}

QList<Contact> ContactManager::GetAllContacts()
{
    return Data;
}

bool cmpByFirstName(const Contact &c1, const Contact &c2)
  {

      if(c1.GetFirstName()<c2.GetFirstName())
          return true;
      else if(c1.GetFirstName()>c2.GetFirstName())
          return false;
      if(c1.GetLastName()<c2.GetLastName())
          return true;
      else if(c1.GetLastName()>c2.GetLastName())
          return false;
      if(c1.GetPhone()<c2.GetPhone())
          return true;
      else if(c1.GetPhone()>c2.GetPhone())
          return false;
      if(c1.GetId()<c2.GetId())
          return true;
      else if(c1.GetId()>c2.GetId())
          return false;
      return false;
  }

QList<Contact> ContactManager::SortByLastName(QList<Contact> l)
{
    qSort(l);
    return l;
}

QList<Contact> ContactManager::Search(QString str)
{
    QList<Contact> l;
    for(auto item:Data)
    {
        if(item.GetFirstName().contains(str)||item.GetLastName().contains(str))
        {
            l.push_back(item);
        }
    }
    return l;
}

Contact ContactManager::Edit(const Contact &conact)
{
    int i=0;
    for(auto item:Data)
    {
        if(item.GetId()==conact.GetId())
        {
            Data.removeAt(i);
            Data.push_back(conact);
            return item;
        }
        i++;
    }
    throw new exception();
}

Contact ContactManager::GetById(const int & Id)
{
    for(auto item:Data)
    {
        if(item.GetId()==Id)
        {
            return item;
        }
    }
    throw new exception();
}

Contact ContactManager::DeleteById(const int& Id)
{
int i=0;
    for(auto item:Data)
    {
        if(item.GetId()==Id)
        {
            Data.removeAt(i);
            return item;
        }
        i++;
    }
    throw new exception();
}

QList<Contact> ContactManager::SortByFirstName(QList<Contact> l)
{
    sort(l.begin(),l.end(),cmpByFirstName);
    return l;
}
