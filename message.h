#ifndef MESSAGE_H
#define MESSAGE_H

#include <QString>

class Message
{
public:
    explicit Message(const QString& str);

    QString encrypt(){

        auto temp = _str.toStdString();

        for(std::size_t i = 0; i < temp.size(); i++){

            temp[i] = temp[i] + 1;
        }

        temp = "HELLO"+temp;
        return QString::fromStdString(temp);
    }

private:
    QString _str;
};

#endif // MESSAGE_H
