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

// std lib
#include <cassert>


namespace RsaToolbox {

class Log : public QObject {
Q_OBJECT

public:
    // Constructor / Destructor
    explicit Log(QObject *parent = 0);
    Log(QString filename,
        QString appName, QString version,
        QObject *parent = 0);
    ~Log();

    bool    isOpen  (void) const;
    QString filename() const;

    // Operators
    template <class T>
    Log& operator<<(T item) {
        _stream << item;
        return *this;
    }

signals:
    void closed();
    void opened();
    void renamed(QString filename);

public slots:
    bool open  ();
    void close ();
    void flush ();
    bool rename(QString filename);
    bool printHeader();
    bool print (QString text);

private:
    QString _application;
    QString _version;

    QString     _filename;
    QFile       _file;
    QTextStream _stream;
    bool open(QString filename, QString application, QString version);
};
}


#endif


