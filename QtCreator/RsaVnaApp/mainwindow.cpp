

// %ProjectName%
#include "Settings.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

// RsaToolbox
using namespace RsaToolbox;

// Qt
#include <QMessageBox>


MainWindow::MainWindow(Log &log, Keys &keys, QWidget *parent) :
    log(log), keys(keys),
    QMainWindow(parent), ui(new ::Ui::MainWindow)
{
    ui->setupUi(this);
    vna.reset(new Vna());
    
    setWindowTitle(QString(APP_NAME) + " " + APP_VERSION);
    toggleInputs(false);
    updateStatus();

    //
    // ...
    //
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateStatus() {
    ui->status_bar->clearMessage();
    QString new_message;
    if (vna->isConnected()) {
        new_message = toString(vna->properties().model())
            + " connected. Ready for measurements.";
    }
    else {
        new_message = "No instrument connected";
    }
    ui->status_bar->showMessage(new_message);
}
void MainWindow::updateInstrumentInfo() {
    VnaModel model = vna->properties().model();
    if (vna->isConnected() && model != UNKNOWN_MODEL) {
        ui->make_line_edit->setText("Rohde & Schwarz");
        ui->model_line_edit->setText(toString(model));
        ui->serial_no_line_edit->setText(vna->properties().serialNumber());
        ui->firmware_version_line_edit->setText(vna->properties().firmwareVersion());
        ui->frequency_range_line_edit->setText(
                    formatValue(vna->properties().minimumFrequency_Hz(), 1, HERTZ_UNITS)
                    + " to "
                    + formatValue(vna->properties().maximumFrequency_Hz(), 1, HERTZ_UNITS));
        ui->power_range_line_edit->setText(
                    formatDouble(vna->properties().minimumPower_dBm(), 1)
                    + " to +"
                    + formatValue(vna->properties().maximumPower_dBm(), 1, DECIBEL_MILLIWATTS_UNITS));
    }
    else {
        ui->make_line_edit->clear();
        ui->model_line_edit->clear();
        ui->serial_no_line_edit->clear();
        ui->firmware_version_line_edit->clear();
        ui->frequency_range_line_edit->clear();
        ui->power_range_line_edit->clear();
    }
}
void MainWindow::updateInputs() {
    // Updates the bounds for valid
    // user inputs...
}

bool MainWindow::isValidInputs() {
    // Checks for valid user input...
    return(false);
}

void MainWindow::toggleConnect(bool isEnabled) {
    ui->address_line_edit->setEnabled(isEnabled);
    ui->connection_type_combo_box->setEnabled(isEnabled);
    ui->connect_push_button->setEnabled(isEnabled);
}
void MainWindow::toggleInputs(bool isEnabled) {
    ui->measure_button->setEnabled(isEnabled);
}

void MainWindow::on_connect_push_button_clicked()
{
    if (ui->connect_push_button->text() == "Connect") {
        ConnectionType connection_type
                = toConnectionType(
                    ui->connection_type_combo_box->currentText());
        QString address = ui->address_line_edit->text();
        vna.reset(new Vna(connection_type, address));
        vna->useLog(&log);
        if (vna->isConnected() && vna->properties().isKnownModel()) {
            vna->printInfo();
            ui->connect_push_button->setText("Disconnect");
            updateInputs();
            toggleInputs(true);
        }
        else {
            vna.reset(new Vna());
            QString warning = QString()
                    + "Could not connect to a Rohde & Schwarz VNA at "
                    + ui->connection_type_combo_box->currentText()
                    + " address " + address
                    + "\nPlease check your setup and try again.";
            QMessageBox::warning(this, APP_NAME, warning);
        }
    }
    else { // Disconnect
        vna.reset(new Vna());
        ui->connect_push_button->setText("Connect");
        toggleInputs(false);
    }
    
    updateStatus();
    updateInstrumentInfo();
}

void MainWindow::on_measure_button_clicked()
{
    // Check for invalid input
    if (isValidInputs() == false) {
        //
        // Handle invalid inputs
        //
        QMessageBox::warning(this,
                             APP_NAME, QString() +
                             "Invalid input.\n"
                           + "Please check your measurement values and try again.");
        return;
    }

    // Test instrument for disconnect
    if (vna->idString().isEmpty()) {
        QMessageBox::warning(this,
                             APP_NAME,
                             "Instrument is not responding. It appears to have disconnected.");
        on_connect_push_button_clicked();
        return;
    }

    toggleConnect(false);
    toggleInputs(false);

    //
    // Additional setup for measurement...
    //

    // Start measurement
    ui->status_bar->showMessage("Initializing...");
    measure.reset(new MeasureThread(*vna.data()));
    this->connect(measure.data(), SIGNAL(progress(int)), SLOT(progress(int)));
    this->connect(measure.data(), SIGNAL(finished(QPrivateSignal)), SLOT(finished()));
    vna->moveToThread(measure.data());
    measure->start();
}
void MainWindow::progress(int percent)
{
    QString message;
    if (percent < 10)
        message = "Measurements  " + QVariant(percent).toString() + "% complete";
    else
        message = "Measurements " + QVariant(percent).toString() + "% complete";
    ui->status_bar->showMessage(message);
}
void MainWindow::finished()
{
    // Enable GUI
    toggleConnect(true);
    toggleInputs(true);
    updateStatus();
}
