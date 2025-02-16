#include <QCoreApplication>
#include <QTextStream>

#include <iostream>

#include "radio.h"
#include "station.h"

#define TOTAL_CHANNEL 3

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Radio boombox;
    Station* channels[TOTAL_CHANNEL];

    // auto delete using object tree
    channels[0] = new Station(&boombox, 101, "Rock and roll");
    channels[1] = new Station(&boombox, 92, "Hip hop");
    channels[2] = new Station(&boombox, 8, "News");

    boombox.connect(&boombox, &Radio::quit, &a, &QCoreApplication::quit, Qt::QueuedConnection);

    while (true)
    {
        qInfo() << "Enter on, off, test or quit";
        QTextStream qtin(stdin);
        QString line = qtin.readLine().trimmed().toUpper();

        if (line == "ON")
        {
            qInfo() << "Turning on radio";
            for (int i = 0; i < TOTAL_CHANNEL; i++)
            {
                Station* channel = channels[i];
                boombox.connect(channel, &Station::send, &boombox, &Radio::listen);
            }
            qInfo() << "Radio turned on";
        }
        else if (line == "OFF")
        {
            qInfo() << "Turning off radio";
            for (int i = 0; i < TOTAL_CHANNEL; i++)
            {
                Station* channel = channels[i];
                boombox.disconnect(channel, &Station::send, &boombox, &Radio::listen);
            }
            qInfo() << "Radio turned off";
        }
        else if (line == "TEST")
        {
            qInfo() << "Testing radio";
            for (int i = 0; i < TOTAL_CHANNEL; i++)
            {
                Station* channel = channels[i];
                channel->broadcast("Broadcasting live!!!");
            }
            qInfo() << "Testend";
        }
        else if (line == "QUIT")
        {
            qInfo() << "Quiting ";
            emit boombox.quit();
            break;
        }
        else
        {
            qInfo() << "Do not have this action: " << line;
        }
    }

    return a.exec();
}
