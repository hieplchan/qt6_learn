#include <QCoreApplication>
#include <QDebug>
#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QVariant>

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

void testPassByValueString(QString s) // COPY: QString is not QObject
{
    qInfo() << s;
}

void testString()
{
    qInfo() << __FUNCTION__;

    QString name = "Hiep Chan";
    qInfo() << name;
    qInfo() << name.mid(1, 3);
    qInfo() << name.insert(0, "Mr. ");
    qInfo() << name.split(" ");

    int index = name.indexOf(" ");
    if (index > -1)
    {
        qInfo() << name.remove(0, index).trimmed();
    }

    QString title = "Teacher";
    QString full = name.trimmed() + " " + title;
    qInfo() << full;

    qInfo() << full.toUtf8();

    testPassByValueString(full);
}

void testPassQVariant(QVariant value) // COPY: QVariant is not QObject
{
    qInfo() << value;

    int convertedValue = 0;
    bool isConvertedSuccess = false;

    convertedValue = value.toInt(&isConvertedSuccess);
    if (isConvertedSuccess)
    {
        qInfo() << "INT" << convertedValue;
    }
    else
    {
        qInfo() << "Can not converted to int" << value;
    }
}

void testQVariant()
{
    qInfo() << __FUNCTION__;

    QVariant test1 = 1;
    testPassQVariant(test1);

    QVariant test2 = "Hello World";
    testPassQVariant(test2);
}

void testQByeArray()
{
    qInfo() << __FUNCTION__;

    QString greeting = "Hello World!!!";
    QByteArray buffer(greeting.toUtf8());
    buffer.append("AAA");
    qInfo() << buffer;

    qInfo() << buffer.rightJustified(20, '.');
    qInfo() << buffer.at(buffer.length() - 1);

    QString modified(buffer); // convert back to string
    qInfo() << modified;

    // Basic encode/decode
    qInfo() << buffer.toBase64();
    qInfo() << buffer.toHex();
}

void testQStringList()
{
    QString data = "Hello world how are you";
    QStringList lst = data.split(" ");

    foreach (QString str, lst)
    {
        qInfo() << str;
    }

    lst.sort(Qt::CaseInsensitive);
    qInfo() << lst;

    QString myVar = "Hello";
    if (lst.contains(myVar))
    {
        int index = lst.indexOf(myVar);
        qInfo() << lst.value(index);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    testType();

    testDateTime();

    testString();

    testQByeArray();

    testQVariant();

    testQStringList();

    return a.exec();
}
