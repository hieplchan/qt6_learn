#include "source.h"

Source::Source(QObject *parent)
    : QObject{parent}
{}

void Source::testSignal()
{
    emit mySignal("Hello from source");
}
