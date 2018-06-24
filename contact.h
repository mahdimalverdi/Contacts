#ifndef CONTACT_H
#define CONTACT_H
#include <qstring.h>
#include <QDataStream>

class Contact
{
    int Id;
    QString FirstName;
    QString LastName;
    QString Phone;
public:
    Contact();
    Contact(const Contact & c);
    Contact(const int & Id,
            const QString & FirstName,
            const QString & LastName,
            const QString & Phone);
    void SetFirstName(const QString & FirstName);
    void SetLastName(const QString & LastName);
    void SetPhone(const QString & Phone);
    int GetId() const;
    QString GetFirstName() const;
    QString GetLastName() const;
    QString GetPhone() const;
    friend QDataStream & operator <<(QDataStream & out,const Contact & c);
    friend QDataStream & operator >>(QDataStream & in,Contact & c);
    friend bool operator <(const Contact & c1,const Contact & c2);
};


#endif // CONTACT_H
