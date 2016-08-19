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
    Log(QString filename,
        QString appName, QString version,
        QObject *parent = 0);
    ~Log();

    // Status
    bool isOpen(void) const;
    bool isClosed(void) const;
    QString filename() const;
    bool reset(QString filename, QString appName, QString version);

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
    bool open();
    void close();
    bool rename(QString pathName);

    bool printHeader();
    bool print(QString text);
    bool printLine(QString text);

private:
    QString _appName;
    QString _version;

    QString _filename;
    QFile _file;
    QTextStream _stream;
};
}


#endif


