#ifndef MeasureThread_THREAD_H
#define MeasureThread_THREAD_H


// Rsa
#include "Vna.h"

// Qt
#include <QThread>


class MeasureThread : public QThread
{
    Q_OBJECT
public:
    explicit MeasureThread(RsaToolbox::Vna &vna, QObject *parent = 0);
    
signals:
    void progress(int percent);
    
public slots:

private:
    RsaToolbox::Vna &vna;

    void run(void);
    
};


#endif // MeasureThread_THREAD_H
