#ifndef LOG_H
#define LOG_H

// Qt Library:
#include <QString>
#include <QFile>
#include <QDir>
#include <QTextStream>

// RsaToolbox:
#include "Definitions.h"

// Qt
#include <QObject>
#include <QTextStream>


namespace RsaToolbox {

class Log : public QObject {
private: Q_OBJECT

public:
    // Constructor / Destructor
    explicit Log(QObject *parent = 0);
    Log(QString directory, QString filename,
        QString applicationName, QString applicationVersion, QObject *parent = 0);
    ~Log();

    // Status
    bool isOpen(void);
    bool isClosed(void);

    void reset(QString directory, QString filename, QString appplicationName, QString applicationVersion);

    // Operators
    template <class T>
    Log& operator<<(T item) {
        _stream << item;
        return(*this);
    }

signals:
    void closed();
    void opened();
    void renamed(QString pathName);

public slots:
    void open();
    void close();
    void rename(QString pathName);

    void printApplicationHeader();
    void print(QString text);
    void printLine(QString text);

private:
    QString _applicationName;
    QString _applicationVersion;
    QString _directory;
    QFile _file;
    QTextStream _stream;
};
}


#endif


