#ifndef KEY_H
#define KEY_H

// C++ Standard library
#include <QString>

namespace RsaToolbox {
	class Key {
        QString path;

		// Constructor
        Key(QString path);

		// Get
        bool GetSetting(QString key, bool &value);
        bool GetSetting(QString key, int &value);
        bool GetSetting(QString key, double &value);
        bool GetSetting(QString key, QString &value);

		// Set
        bool SetSetting(QString key, bool value);
        bool SetSetting(QString key, int value);
        bool SetSetting(QString key, double value);
        bool SetSetting(QString key, QString value);
        bool SetSetting(QString key, char *value);

	private:
		// Helpers
        void AppendThisPath(QString &key);
	};
}


#endif
