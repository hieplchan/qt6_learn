#include "cat.h"

Cat::Cat(QObject *parent)
    : Mammal{parent}
{
    qDebug() << this << " constructed";
}

void Cat::speak()
{
    qDebug() << "meow";
}
