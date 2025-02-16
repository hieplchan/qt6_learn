#include "animal.h"

Animal::Animal(QObject *parent)
    : QObject{parent}
{
    qDebug() << this << " constructed";
}

Animal::~Animal()
{
    qDebug() << this << " deconstructed";
}
