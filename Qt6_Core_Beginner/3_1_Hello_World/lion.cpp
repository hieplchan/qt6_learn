#include "lion.h"

Lion::Lion(QObject *parent)
    : Cat{parent}
{}

void Lion::speak()
{
    qDebug() << "ROAR!!!!";
    Cat::speak();
}
