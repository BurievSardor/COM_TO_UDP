#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QSerialPort>
#include <QDebug>
#include <QTimer>
#include "message.h"

class Worker : public QObject
{
    Q_OBJECT
public:
    Worker(QString _comPort, int _udpPort, QObject *parent = nullptr);

    void sendData();
private:
    QTimer timer;
    QSerialPort SerialPort;
    QString data;

    QString comPort;
    int udpPort = -1;
};

#endif // WORKER_H
