#include "testobjecttree.h"

TestObjectTree::TestObjectTree(QObject *parent)
    : QObject{parent}
{
    qDebug() << this << " constructed";
}

TestObjectTree::~TestObjectTree()
{
    qDebug() << this << " deconstructed";
}
