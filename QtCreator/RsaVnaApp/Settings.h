#ifndef SETTINGS_H
#define SETTINGS_H


// RsaToolbox
#include "General.h"


// Application settings
const QString APP_NAME = "%APPLICATION_NAME%";
const QString APP_VERSION = "1.0.0"; //http://semver.org/
const QString APP_FOLDER = "%APP_FOLDER%";

// Log, Key
#ifdef DEBUG_MODE
const QString LOG_PATH = SOURCE_DIR;
const QString LOG_FILENAME = "DEBUG_LOGFILE.txt";
const QString KEY_PATH = QString(SOURCE_DIR) + "/Keys/";
#else
const QString LOG_PATH = RsaToolbox::GetAppDataPath(APP_FOLDER);
const QString LOG_FILENAME = "%LOG_FILENAME%";
const QString KEY_PATH = LOG_PATH + "/Settings/";
#endif

// Connection settings
const unsigned int TIMEOUT_MS = 1000;

// Keys
const QString EXAMPLE_KEY = "EXAMPLE"; // Place your keys here


#endif

