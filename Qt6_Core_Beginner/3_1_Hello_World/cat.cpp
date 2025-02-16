#include "cat.h"

Cat::Cat(QObject *parent)
    : Mammal{parent}
{
    qDebug() << this << " constructed";
}
