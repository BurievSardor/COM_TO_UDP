#include <QCoreApplication>
#include <QDebug>
#include "worker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString comPort = "no com port";
    int udpPort = -1;

    if(argc > 1 ){ comPort = QString::fromStdString( std::string(argv[1]) ); }
    if(argc > 2 ){ udpPort = std::stoi( std::string(argv[2]) ); }

    qDebug() << "comPort: " << comPort << " udpPort: " << udpPort;

    Worker worker(comPort,udpPort);

    return a.exec();
}
