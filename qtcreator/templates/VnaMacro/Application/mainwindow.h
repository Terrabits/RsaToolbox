#ifndef MAINWINDOW_H
#define MAINWINDOW_H


// RsaToolbox
#include <Keys.h>
#include <Vna.h>

// Qt
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(RsaToolbox::Vna *vna, RsaToolbox::Keys *keys, QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    RsaToolbox::Vna  *_vna;
    RsaToolbox::Keys *_keys;
};

#endif // MAINWINDOW_H
