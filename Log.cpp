
// RSToolbox includes
#include "Definitions.h"
#include "Log.h"

// Qt
#include <QDateTime>

using namespace RsaToolbox;


// Constructor, Destructor
Log::Log(QDir path, QString filename, QString program_name, QString program_version) {
    this->path = path;
    filename = path.path() + "/" + filename;
    this->file.setFileName(filename);
    this->file.open(QFile::WriteOnly);
    this->stream.setDevice(&this->file);
    this->program_name = program_name;
    this->program_version = program_version;
}
Log::~Log() {
    stream.flush();
    Close();
}

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
    stream << program_name << " Version " << program_version << endl;
    stream << "(c) 2013 Rohde & Schwarz America" << endl << endl;
    stream << QDateTime::currentDateTime().toString() << endl << endl;
}
