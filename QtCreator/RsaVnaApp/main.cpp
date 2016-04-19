

// %ProjectName%
#include "Settings.h"
#include "mainwindow.h"

// RsaToolbox
#include "Log.h"
#include "Vna.h"
#include "Keys.h"
using namespace RsaToolbox;

// Qt
#include <QApplication>
#include <QMessageBox>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    // Create log
    Log log(LOG_FILENAME, APP_NAME, APP_VERSION);
    log.printHeader();
    
    // Create Key(s)
    Keys keys(KEY_PATH);
    
    // Create, display window
    MainWindow w(log, keys);
    w.setWindowFlags(w.windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
    w.show();
    return a.exec();
}

