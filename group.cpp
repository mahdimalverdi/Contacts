#include "group.h"

int Group::getId() const
{
    return Id;
}

QString Group::getName() const
{
    return Name;
}

void Group::setName(const QString &value)
{
    Name = value;
}

Group::Group()
{

}

Group::Group(const Group &group)
{
    this->Id=group.Id;
    this->Name=group.Name;
}

Group::Group(const int &id, const QString &name)
{
    this->Id=Id;
    this->Name=Name;
}
