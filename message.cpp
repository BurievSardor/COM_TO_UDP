#include "message.h"

Message::Message(const QString& str) : _str(str) { }

QString Message::encrypt(){

    auto temp = _str.toStdString();

    for(std::size_t i = 0; i < temp.size(); i++){

        temp[i] = temp[i] + 1;
    }

    temp = "HELLO"+temp;
    return QString::fromStdString(temp);
}
