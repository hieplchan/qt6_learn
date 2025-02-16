#include <QCoreApplication>

#include "source.h"
#include "destination.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Source oSource;
    Destination oDestination;

    QObject::connect(&oSource, &Source::mySignal, &oDestination, &Destination::mySlot);
    oSource.testSignal();

    // Can use slot as normal function
    // oDestination.mySlot("Hello from main");

    return a.exec();
}
