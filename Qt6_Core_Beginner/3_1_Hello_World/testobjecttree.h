#ifndef TESTOBJECTTREE_H
#define TESTOBJECTTREE_H

#include <QObject>
#include "animal.h"

class TestObjectTree : public QObject
{
    Q_OBJECT
public:
    explicit TestObjectTree(QObject *parent = nullptr);
    ~TestObjectTree();

    Animal* animal;

signals:
};

#endif // TESTOBJECTTREE_H
