#ifndef KEY_H
#define KEY_H

// Qt
#include <QDir>
#include <QString>
#include <QFile>
#include <QDataStream>


namespace RsaToolbox {
	class Key {
        QDir path;

		// Constructor
        Key(QDir path) {
            this->path = path;
        }

		// Get
        template <class T>
        bool Get(QString key, T &value) {
            AppendThisPath(key);
            QFile file(key);
            file.open(QIODevice::ReadOnly);
            if (file.isOpen()) {
                QDataStream keyfile(file);
                keyfile >> value;
                file.close();
                return(true);
            }
            else {
                return(false);
            }
        }

		// Set
        template <class T>
        bool Set(QString key, T value) {
            AppendThisPath(key);
            QFile file(key);
            file.open(QIODevice::WriteOnly);
            if (file.isOpen()) {
                QDataStream keyfile(file);
                keyfile << value;
                file.close();
                return(true);
            }
            else {
                return(false);
            }
        }

	private:
		// Helpers
        void AppendThisPath(QString &key) {
            key = path.path() + "/" + key;
        }
    };
}


#endif
