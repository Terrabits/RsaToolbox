#ifndef KEY_H
#define KEY_H


// Rsa
#include "General.h"

// Qt
#include <QDir>
#include <QString>
#include <QFile>
#include <QDataStream>


namespace RsaToolbox {
	class Key {
    private:
        QDir path;

    public:
		// Constructor
        Key() {
            path = QDir(AppendCurrentDirectory(""));
        }
        Key(QString program_folder) {
            this->path = QDir(GetAppDataPath(program_folder) + "/Settings/");
        }
        Key(QDir path) {
            this->path = path;
        }

        // Boolean key functions
        bool Exists(QString key) {
            AppendThisPath(key);
            QFile file(key);
            return(file.exists());
        }
        bool DoesNotExist(QString key) {
            return(!Exists(key));
        }
        bool isTrue(QString key) {
            bool isTrue;
            if (Get(key, isTrue) == false)
                return(false);
            else
                return(isTrue);
        }
        bool isFalse(QString key) {
            return(!isTrue(key));
        }

		// Get
        template <class T>
        bool Get(QString key, T &value) {
            AppendThisPath(key);
            QFile file(key);
            file.open(QIODevice::ReadOnly);
            if (file.isOpen()) {
                QDataStream keyfile(&file);
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
                QDataStream keyfile(&file);
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
