

// RSToolbox includes
#include "Definitions.h"
#include "Log.h"

// Qt
#include <QDateTime>

using namespace RsaToolbox;


// Constructor, Destructor
Log::Log() {} // Dangerous?
Log::Log(QString path, QString filename, QString program_name, QString program_version) {
    this->path = path;
    filename = path + "/" + filename;
    this->file.setFileName(filename);
    this->file.open(QIODevice::WriteOnly);
    this->stream.setDevice(&this->file);
    this->app_name = program_name;
    this->app_version = program_version;
}
Log::~Log() {
    stream.flush();
    Close();
}

// Status
bool Log::isOpen(void) {
    return(file.isOpen());
}
bool Log::isClosed(void) {
    return(!isOpen());
}

// Actions
void Log::Open(void) {
    if (file.isOpen() == false)
        file.open(QFile::WriteOnly);
}
void Log::Close(void) {
    if (file.isOpen())
        file.close();
}
void Log::Rename(QString filename) {
    file.rename(filename);
}
void Log::PrintProgramHeader() {
    stream << app_name << " Version " << app_version << endl;
    stream << "(C) 2013 Rohde & Schwarz America" << endl << endl;
    stream << QDateTime::currentDateTime().toString() << endl << endl;
}

// Slots
void Log::Print(QString formatted_text) {
    stream << formatted_text;
    stream.flush();
}

