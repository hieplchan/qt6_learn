#include "dog.h"

Dog::Dog(QObject *parent)
    : Mammal{parent}
{
    qDebug() << this << " constructed";
}
