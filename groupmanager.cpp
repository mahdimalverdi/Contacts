#include "groupmanager.h"
#include "group.h"
#include <QtAlgorithms>
#include <exception>
QDataStream & operator <<(QDataStream & out,const Group & group)
{
    return out<<group.Id<<group.Name;
}
QDataStream & operator >>(QDataStream & in, Group & group)
{
    return in>>group.Id>>group.Name;
}

bool operator <(const Group & g1,const Group & g2)
{
    if(g1.getName().localeAwareCompare(g2.getName())<0)
        return true;
    if(g1.getName().localeAwareCompare(g2.getName())>0)
        return false;
    if(g1.getId()<g2.getId())
        return true;
    if(g1.getId()>g2.getId())
        return false;
    return false;

}
void GroupManager::WriteToFile()
{
    QFile file(FileAddress);
    QDataStream dStream(&file);
    file.open(QIODevice::WriteOnly);
    dStream<<Data;
    file.close();
}

void GroupManager::ReadFromFile()
{
    QFile file(FileAddress);
    QDataStream dStream(&file);
    file.open(QIODevice::ReadOnly);
    dStream>>Data;
    file.close();
}

GroupManager::GroupManager()
{
    this->FileAddress="Groups.dat";
    ReadFromFile();
}

QList<Group> GroupManager::GetAllGroups()
{
    return Data;
}

QList<Group> GroupManager::SortByName(QList<Group> l)
{
    qSort(l);
    return l;
}

QList<Group> GroupManager::Search(QString str)
{
    QList<Group> l;
    for(auto item:Data)
    {
        if(item.getName().startsWith(str))
            l.push_back(item);
    }
    return l;
}

Group GroupManager::Edit(const Group &group)
{

    Group g;
    for(auto item:Data)
    {
        if(group.getId()==item.getId())
        {
            item.setName(group.getName());
            return item;
        }
    }
    return g;
}

Group GroupManager::GetById(const int &Id)
{
    Group g;
    for(auto item:Data)
    {
        if(Id==item.getId())
        {
            return item;
        }
    }
    return g;
}

Group GroupManager::DeleteById(const int &Id)
{
    int i=0;
    for(auto item:Data)
    {
        if(item.getId()==Id)
        {
            Data.removeAt(i);
            return item;
        }
        i++;
    }
    throw "not found";
}

void GroupManager::Add(const Group &group)
{
    int Id=1;
    if(!Data.empty())
        Id=Data.back().getId()+1;
    Group g(Id,group.getName());
    Data.push_back(g);
}
