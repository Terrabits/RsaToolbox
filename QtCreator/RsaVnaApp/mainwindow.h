#ifndef MAINWINDOW_H
#define MAINWINDOW_H


// %ProjectName%
#include "MeasureThread.h"

// RsaToolbox
#include "Log.h"
#include "Keys.h"
#include "Vna.h"

// Qt
#include <QMainWindow>
#include <QScopedPointer>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(RsaToolbox::Log &log, RsaToolbox::Keys &keys, QWidget *parent = 0);
    ~MainWindow();

public slots:
    void progress(int percent);
    void finished();
    
private slots:
    void on_connect_push_button_clicked();
    void on_measure_button_clicked();

private:
    Ui::MainWindow *ui;
    RsaToolbox::Log &log;
    RsaToolbox::Keys &keys;
    QScopedPointer<RsaToolbox::Vna> vna;
    QScopedPointer<MeasureThread> measure;

    void updateStatus();
    void updateInstrumentInfo();
    void updateInputs();

    bool isValidInputs();

    void toggleConnect(bool isEnabled);
    void toggleInputs(bool isEnabled);
};


#endif // MAINWINDOW_H

