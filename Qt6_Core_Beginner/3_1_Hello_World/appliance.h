#ifndef APPLIANCE_H
#define APPLIANCE_H

#include <QObject>
#include <QDebug>

#include "Freezer.h"
#include "Toaster.h"
#include "Microwave.h"

class Appliance : public QObject, public Freezer, public Toaster, public Microwave
{
    Q_OBJECT
public:
    explicit Appliance(QObject *parent = nullptr);

    // Microwave interface
    bool cook();

    // Toaster interface
    bool grill();

    // Freezer interface
    bool freeze();

signals:
};

#endif // APPLIANCE_H
