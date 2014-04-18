

// RsaToolbox
#include "Definitions.h"
#include "General.h"
#include "VisaBus.h"
#include "Vna.h"
#include "NetworkData.h"
#include "SnpStreamReader.h"
#include "SnpStreamWriter.h"
#include "Log.h"
#include "Figure.h"
using namespace RsaToolbox;

// Qt
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Vna vna(TCPIP_CONNECTION, "127.0.0.1");
    // Vna vna(new VisaBus(TCPIP_CONNECTION, "127.0.0.1"));
    // vna.preset();
    Log log("./", "rsatoolbox log.txt", "RsaToolbox", "0.0.0");
    vna.useLog(&log);

    QString projectDir = "C:\\Users\\lalic\\Documents\\Qt\\RsaToolbox";
    QString filename1 = "SnpStreamRead.s3p";
    QString filename2 = "SnpStreamWrite.s3p";
    QString pathName1 = projectDir + "\\" + filename1;
    QString pathName2 = projectDir + "\\" + filename2;

    if (vna.channel().linearSweep().saveSnp(filename1, 1, 2, 3, MAGNITUDE_DEGREES_COMPLEX)) {
        vna.fileSystem().downloadFile(filename1, pathName1, 100);
        vna.fileSystem().deleteFile(filename1);
        SnpStreamReader read(pathName1);
        SnpStreamWriter write(pathName2);
        write.open();
        qDebug() << "Is read open? " << read.isOpen();
        qDebug() << "Is write open? " << write.isOpen();
        if (read.isOpen() && write.isOpen()) {
            write.writeOptions();
            if (read.isData())
                write.writePoint(read.frequency_Hz(), read.data());
            while (read.next())
                write.writePoint(read.frequency_Hz(), read.data());
        }
    }

//    Figure fig;
//    fig.setRows(2);
//    fig.select(1,1);
//    fig.addTrace(freq, toDb(s11));
//    fig.select(2,1);
//    fig.addTrace(freq, toDb(s21));
//    fig.savePng("Test.png");
//    return(fig.exec());
    return(0);
}
