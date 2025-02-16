#include <QCoreApplication>
#include <QDebug>

#include "dog.h"
#include "cat.h"
#include "lion.h"

#include "appliance.h"

void testLog()
{
    qDebug() << "Debug";
    qWarning() << "Warning";
    qCritical() << "Critical";
    qFatal("Test crash");
}

#pragma region Func Return
// Qt dont allow copy constructor
// QObject getObject(QString name)
// {
//     QObject o;
//     o.setObjectName(name);
//     return o;
// }

// QObject& getRef(QString name)
// {
//     QObject o; // on stack
//     o.setObjectName(name);
//     return o; // deleted
// }

QObject* getPtr(QString name)
{
    QObject* o = new QObject(); // on heap
    o->setObjectName(name);
    return o;
}
#pragma endregion Func Return

void testFuncReturn()
{
    // QObject o1 = getObject("ByVal");
    // QObject o2 = getRef("ByRef");
    QObject* o3 = getPtr("ByPtr");
    qInfo() << o3->objectName();
    delete o3;
}

void testInheritance()
{
    Dog dog;

    dog.bark();
    qDebug() << dog.hasBackBone();
    qDebug() << dog.isAlive();

    Cat cat;
    cat.meow();
    qDebug() << cat.hasBackBone();
    qDebug() << cat.isAlive();

    Lion lion;
    lion.speak();
}

void testInterface()
{
    Appliance appliance;
    qDebug() << appliance.grill();
    qDebug() << appliance.freeze();
    qDebug() << appliance.cook();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // qInfo() << "Hello World";

    // testLog();
    // testFuncReturn();
    testInheritance();
    // testInterface();

    return a.exec();
}
