#ifndef DOG_H
#define DOG_H

#include <QObject>

#include "mammal.h"

class Dog : public Mammal
{
    Q_OBJECT
public:
    explicit Dog(QObject *parent = nullptr);

    void bark()
    {
        qDebug() << "Gau gau";
    }

signals:
};

#endif // DOG_H
