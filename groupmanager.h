#ifndef GROUPMANAGER_H
#define GROUPMANAGER_H
#include <QList>
#include "group.h"

class GroupManager
{
    void WriteToFile();
    void ReadFromFile();
public:
    GroupManager();
    void Add(const Group& group);
    void SaveChange();
    QList<Group> GetAllGroups();
    QList<Group> SortByName(QList<Group> l);
    QList<Group> Search(QString str);
    Group Edit(const Group &group);
    Group GetById(const int &Id);
    Group DeleteById(const int& Id);
protected:
    QString FileAddress;
    QList<Group> Data;
};

#endif // GROUPMANAGER_H
