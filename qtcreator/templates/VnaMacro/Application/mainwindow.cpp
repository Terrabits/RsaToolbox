#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(RsaToolbox::Vna *vna, RsaToolbox::Keys *keys, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _vna(vna),
    _keys(keys)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
