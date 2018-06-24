#include "contact.h"


Contact::Contact(){}

Contact::Contact(const Contact &c)
{
    this->Id=c.Id;
    this->FirstName=c.FirstName;
    this->LastName=c.LastName;
    this->Phone=c.Phone;
}

Contact::Contact(const int &Id, const QString &FirstName, const QString &LastName, const QString &Phone)
{
    this->Id=Id;
    this->FirstName=FirstName;
    this->LastName=LastName;
    this->Phone=Phone;
}

void Contact::SetFirstName(const QString &FirstName)
{
    this->FirstName=FirstName;
}

void Contact::SetLastName(const QString &LastName)
{
    this->LastName=LastName;
}

void Contact::SetPhone(const QString &Phone)
{
    this->Phone=Phone;
}

int Contact::GetId() const
{
    return Id;
}

QString Contact::GetFirstName() const
{
    return FirstName;
}

QString Contact::GetLastName() const
{
    return LastName;
}

QString Contact::GetPhone() const
{
    return Phone;
}

bool operator <(const Contact &c1, const Contact &c2)
{

    if(c1.LastName<c2.LastName)
        return true;
    else if(c1.LastName>c2.LastName)
        return false;
    if(c1.FirstName<c2.FirstName)
        return true;
    else if(c1.FirstName>c2.FirstName)
        return false;
    if(c1.Phone<c2.Phone)
        return true;
    else if(c1.Phone>c2.Phone)
        return false;
    if(c1.Id<c2.Id)
        return true;
    else if(c1.Id>c2.Id)
        return false;
    return false;
}

