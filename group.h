#ifndef GROUP_H
#define GROUP_H

#include <qstring.h>
#include <QDataStream>

class Group
{
    int Id;
    QString Name;
public:
    Group();
    Group(const Group & group);
    Group(const int & id,
          const QString & name);
    int getId() const;
    QString getName() const;
    void setName(const QString &value);

    friend QDataStream & operator <<(QDataStream & out,const Group & group);
    friend QDataStream & operator >>(QDataStream & in, Group & group);
    friend bool operator <(const Group & g1,const Group & g2);
};

#endif // GROUP_H
