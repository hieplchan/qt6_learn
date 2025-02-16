#ifndef CAT_H
#define CAT_H

#include <QObject>

#include "mammal.h"

class Cat : public Mammal
{
    Q_OBJECT
public:
    explicit Cat(QObject *parent = nullptr);

    void meow()
    {
        qDebug() << "Meow meow";
    }

signals:
};

#endif // CAT_H
