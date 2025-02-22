#include <QCoreApplication>
#include <QDebug>
#include <QDate>
#include <QTime>
#include <QDateTime>

void testType()
{
    qInfo() << __FUNCTION__;

    qint8 value8 = 0;
    qint16 value16 = 0;
    qint32 value32 = 0;
    qint64 value64 = 0;
    qintptr valueptr = 0;

    // Qt make sure size of these type is the same on "different OS"
    qInfo() << sizeof(value8);
    qInfo() << sizeof(value16);
    qInfo() << sizeof(value32);
    qInfo() << sizeof(value64);
    qInfo() << sizeof(valueptr);
}

void testDateTime()
{
    qInfo() << __FUNCTION__;

    QDate today = QDate::currentDate();
    qInfo() << today;
    qInfo() << today.addDays(1);
    qInfo() << today.addYears(20);
    qInfo() << today.toString(Qt::DateFormat::ISODate);
    qInfo() << today.toString(Qt::DateFormat::RFC2822Date);
    qInfo() << today.toString(Qt::DateFormat::TextDate);

    QTime now = QTime::currentTime();
    qInfo() << now.toString(Qt::DateFormat::ISODate);
    qInfo() << now.toString(Qt::DateFormat::RFC2822Date);
    qInfo() << now.toString(Qt::DateFormat::TextDate);

    QDateTime currentDateTime = QDateTime::currentDateTime();
    QDateTime expiredTime = currentDateTime.addDays(45);
    if (currentDateTime > expiredTime)
    {
        qInfo() << "Expired: " << expiredTime;
    }
    else
    {
        qInfo() << "Still ok: " << expiredTime;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    testType();

    testDateTime();

    return a.exec();
}
