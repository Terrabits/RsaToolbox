

// Header:

// RsaToolbox
#include "Update.h"
using namespace RsaToolbox;


// Declare
bool isUpdateMenu(int argc, char *argv[], Update &update);

// Main
Update update(&keys);
if (isUpdateMenu(argc, argv, update)) {
	return a.exec();
}

// ...

// After main window is created:
// (to make sure updates are on top)
if (update.isUpdateDue())
        update.automaticUpdate();


// Below Main:
bool isUpdateMenu(int argc, char *argv[], Update &update) {
	update.setApplicationName(APP_NAME);
	update.setApplicationVersion(APP_VERSION);
	update.setJsonUrl(JSON_UPDATE_URL);

    if (argc != 2)
        return false;

    QString arg(argv[1]);
    arg = arg.trimmed().toUpper();
    if (arg == "-UPDATE" || arg == "--UPDATE") {
        update.manualUpdate();
        return true;
    }

    return false;
}

// Settings.h
const QString JSON_UPDATE_URL = "https://vna.rs-us.net/applications/___.json";