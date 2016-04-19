#ifndef SETTINGS_H
#define SETTINGS_H


// RsaToolbox
#include "General.h"
#include "GenericBus.h"


// Application settings
const QString APP_NAME = "%APPLICATION_NAME%";
const QString APP_VERSION = "1.0";
const QString MANUFACTURER_FOLDER = "Rohde-Schwarz";
const QString APP_FOLDER = "%APP_FOLDER%";

// Log, Key
#ifdef DEBUG_MODE
const QDir dataDir(SOURCE_DIR);
const QString LOG_FILENAME = dataDir.filePath("DEBUG_LOGFILE.txt");
const QString KEY_PATH = dataDir.filePath("Keys");
#else
const QDir dataDir(RsaToolbox::GetAppDataPath(MANUFACTURER_FOLDER, APP_FOLDER));
const QString LOG_FILENAME = dataDir.filePath("%LOG_FILENAME%");
const QString KEY_PATH = dataDir.filePath("Settings");
#endif

// Connection settings
const RsaToolbox::ConnectionType CONNECTION_TYPE = RsaToolbox::TCPIP_CONNECTION;
const QString INSTRUMENT_ADDRESS = "127.0.0.1";
const unsigned int TIMEOUT_MS = 1000;

// Keys
const QString EXAMPLE_KEY = "EXAMPLE"; // Place your keys here


#endif
