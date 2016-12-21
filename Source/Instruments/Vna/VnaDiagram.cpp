

// RsaToolbox
#include "General.h"
#include "IndexName.h"
#include "VnaDiagram.h"
#include "Vna.h"
using namespace RsaToolbox;

// Qt
#include <QDebug>

/*!
 * \class RsaToolbox::VnaDiagram
 * \ingroup VnaGroup
 * \brief The \c %VnaDiagram class
 * manipulates a diagram.
 */

VnaDiagram::VnaDiagram(QObject *parent) :
    QObject(parent)
{
    placeholder.reset(new Vna());
    _vna = placeholder.data();
    _index = 0;
}

VnaDiagram::VnaDiagram(const VnaDiagram &other)
{
    if (other.isFullyInitialized()) {
        _vna = other._vna;
        _index = other._index;
    }
    else {
        placeholder.reset(new Vna());
        _vna = placeholder.data();
        _index = 0;
    }
}

VnaDiagram::VnaDiagram(Vna *vna, uint index, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _index = index;
}
VnaDiagram::~VnaDiagram() {

}

void VnaDiagram::select() {
    // No SCPI command to make diagram
    // active (select)
    if (isMaximized()) {
        normalSize();
        maximize();
    }
    else {
        maximize();
        normalSize();
    }
}

QVector<uint> VnaDiagram::channels() {
    QVector<uint> chans;
    QStringList traces = this->traces();
    foreach (QString trace, traces) {
        uint c = _vna->trace(trace).channel();
        if (!chans.contains(c))
            chans << c;
    }
    qSort(chans);
    return chans;
}

QStringList VnaDiagram::traces() {
    QString scpi = ":DISP:WIND%1:TRAC:CAT?\n";
    scpi = scpi.arg(_index);
    QString result = _vna->query(scpi, 4000).trimmed();
    QVector<IndexName> indexNames;
    indexNames = IndexName::parse(result, ",", "\'");
    return IndexName::names(indexNames);
}
void VnaDiagram::deleteTraces() {
    QStringList traces = this->traces();
    foreach (QString trace, traces)
        _vna->deleteTrace(trace);
}

bool VnaDiagram::isTitleOn() {
    QString scpi = ":DISP:WIND%1:TITL?\n";
    scpi = scpi.arg(_index);
    return _vna->query(scpi).trimmed() == "1";
}
bool VnaDiagram::isTitleOff() {
    return !isTitleOn();
}
void VnaDiagram::titleOn(bool isOn) {
    QString scpi = ":DISP:WIND%1:TITL %2\n";
    scpi = scpi.arg(_index);
    if (isOn)
        scpi = scpi.arg(1);
    else
        scpi = scpi.arg(0);
    _vna->write(scpi);
}
void VnaDiagram::titleOff(bool isOff) {
    titleOn(!isOff);
}

QString VnaDiagram::title() {
    QString scpi = ":DISP:WIND%1:TITL:DATA?\n";
    scpi = scpi.arg(_index);
    return _vna->query(scpi).trimmed().remove("\'");
}
void VnaDiagram::setTitle(QString title) {
    titleOn();
    QString scpi = ":DISP:WIND%1:TITL:DATA \'%2\'\n";
    scpi = scpi.arg(_index);
    scpi = scpi.arg(title);
    _vna->write(scpi);
}

bool VnaDiagram::isMaximized() {
    QString scpi = ":DISP:WIND%1:MAX?\n";
    scpi = scpi.arg(_index);
    return _vna->query(scpi).trimmed() == "1";
}
void VnaDiagram::maximize() {
    QString scpi = ":DISP:WIND%1:MAX 1\n";
    scpi = scpi.arg(_index);
    _vna->write(scpi);
}
void VnaDiagram::normalSize() {
    QString scpi = ":DISP:WIND%1:MAX 0\n";
    scpi = scpi.arg(_index);
    _vna->write(scpi);
}

void VnaDiagram::autoscale() {
    qDebug() << "ERROR: VnaDiagram::autoscale not written...";
    _vna->print("SCPI Error: VnaDiagram::autoscale not written...\n\n");
}
void VnaDiagram::setYAxisMinimum(double min) {
    QStringList traces = this->traces();
    foreach (QString trace, traces)
        _vna->trace(trace).setYAxisMinimum(min);
}
void VnaDiagram::setYAxisMaximum(double max) {
    QStringList traces = this->traces();
    foreach (QString trace, traces)
        _vna->trace(trace).setYAxisMaximum(max);
}
void VnaDiagram::setYAxis(double min, double max) {
    QStringList traces = this->traces();
    foreach (QString trace, traces)
        _vna->trace(trace).setYAxis(min, max);
}

bool VnaDiagram::saveScreenshot(QString filename, ImageFormat format) {
    QString extension = "." + toString(format);
    if (!filename.endsWith(extension, Qt::CaseInsensitive))
        filename += extension;

    select();
    _vna->settings().setFileDestination(filename);
    _vna->settings().setImageFormat(format);
    _vna->write(":HCOP:PAGE:WIND ACT\n");
    _vna->write(":HCOP\n");
    _vna->pause();
    return _vna->fileSystem().isFile(filename);
}
bool VnaDiagram::saveScreenshotLocally(QString filename, ImageFormat format) {
    QString extension = "." + toString(format);
    QString tempFilename = uniqueAlphanumericString() + extension;
    if (!filename.endsWith(extension, Qt::CaseInsensitive))
        filename += extension;

    bool isFile = saveScreenshot(tempFilename, format);
    if (isFile) {
        _vna->fileSystem().downloadFile(tempFilename, filename);
        _vna->fileSystem().deleteFile(tempFilename);
    }
    return isFile;
}

void VnaDiagram::operator=(VnaDiagram const &other) {
    if (other.isFullyInitialized()) {
        _vna = other._vna;
        _index = other._index;
    }
    else {
        placeholder.reset(new Vna());
        _vna = placeholder.data();
        _index = 0;
    }
}

// Private
bool VnaDiagram::isFullyInitialized() const {
    if (_vna == NULL)
        return(false);
    if (_vna == placeholder.data())
        return(false);

    //else
    return(true);
}
