#include "worker.h"

Worker::Worker(QString _comPort, int _udpPort, QObject *parent)
    : comPort(_comPort), udpPort(_udpPort), QObject{parent}
{
    timer.setSingleShot(true);
    timer.setInterval(5000); // 5s

    SerialPort.setBaudRate(9600);
    SerialPort.setPortName(comPort);

    connect(&timer, &QTimer::timeout,this, [this](){ sendData(); });

    connect(&SerialPort, &QSerialPort::readyRead, this,[this](){

        data += SerialPort.readAll();

        timer.start();

        qDebug() << "data: " << data;

        if ( data.contains("\r") ){

            timer.stop();
            data.remove("\r");
            sendData();
        }

    });

    if ( SerialPort.open(QIODevice::ReadWrite) ){

        qDebug() << "serial port opened";
    }else{

        qDebug() << "serial not port opened";
    }
}

void Worker::sendData()
{
    qDebug() << "sending... " << data;
    data.clear();
}
