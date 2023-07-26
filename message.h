#ifndef MESSAGE_H
#define MESSAGE_H

#include <QString>

class Message
{
public:
    explicit Message(const QString& str);

    QString encrypt();

private:
    QString _str;
};

#endif // MESSAGE_H
