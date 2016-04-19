

// %ProjectName%
#include "MeasureThread.h"

// Rsa
#include "Vna.h"
using namespace RsaToolbox;

// Qt
#include <QApplication>


MeasureThread::MeasureThread(Vna &vna, QObject *parent) :
    vna(vna),
    QThread(parent)
{
    // Constructor.
    // Additional instance preparation goes here
}

void MeasureThread::run() {


    emit progress(0);

    //
    // Place your multithreaded code here
    //

    emit progress(100);


    // Change thread affinity of Vna back to main thread
    vna.moveToThread(QApplication::instance()->thread());
}
