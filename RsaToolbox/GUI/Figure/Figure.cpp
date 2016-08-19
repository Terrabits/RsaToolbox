#include "Figure.h"
#include "ui_Figure.h"


// RsaToolbox
#include "General.h"
using namespace RsaToolbox;

// Qt
#include <QScopedPointer>


uint Figure::_figureIndex = 1;

Figure::Figure(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Figure)
{
    ui->setupUi(this);
    setWindowTitle(QString("Figure %1").arg(_figureIndex++));
    _initialize();
}
Figure::Figure(uint rows, uint columns,
               QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Figure)
{
    ui->setupUi(this);
    setWindowTitle(QString("Figure %1").arg(_figureIndex++));
    _initialize(rows, columns);
}
Figure::~Figure()
{
    delete ui;
}
uint Figure::rows() {
    return(_rows);
}
uint Figure::columns() {
    return(_columns);
}
void Figure::setRows(uint rows) {
    if (rows == 0 || rows == _rows)
        return;

    if (rows > _rows)
        _addRows(rows);
    else
        _deleteRows(rows);

    _rows = rows;
    if (_i >= _rows)
        _i = _rows-1;
    _setMinimumSizes();
}
void Figure::setColumns(uint columns) {
    if (columns == 0 || columns == _columns)
        return;

    if (columns > _columns)
        _addColumns(columns);
    else
        _deleteColumns(columns);

    _columns = columns;
    if (_i >= _columns)
        _i = _columns-1;
    _setMinimumSizes();
}
void Figure::select(uint row, uint column) {
    if (row > 0 && row <= _rows) {
        if (column > 0 && column <= _columns) {
            _i = row-1;
            _j = column-1;
        }
    }
}

QCustomPlot* Figure::plot(uint row, uint column) {
    QLayoutItem* item = _layout()->itemAtPosition(row, column);
    if (item == NULL)
        return(NULL);
    return((QCustomPlot*)item->widget());
}
void Figure::addTrace(QRowVector y, Qt::GlobalColor color, QString name) {
    QRowVector x;
    linearSpacing(x, 0, y.size()-1.0, y.size());
    addTrace(x, y, QPen(color), name);
}
void Figure::addTrace(QRowVector x, QRowVector y, Qt::GlobalColor color, QString name) {
    addTrace(x, y, QPen(color), name);
}
void Figure::addTrace(QRowVector y, QPen pen, QString name) {
    QRowVector x;
    linearSpacing(x, 0, y.size()-1.0, y.size());
    addTrace(x, y, pen, name);
}
void Figure::addTrace(QRowVector x, QRowVector y, QPen pen, QString name) {
    QCustomPlot* plot = this->plot(_i, _j);
    uint index = plot->graphCount();
    plot->addGraph();
    plot->graph(index)->setName(name);
    plot->graph(index)->setPen(pen);
    plot->graph(index)->setData(x, y);
    plot->rescaleAxes();
}

bool Figure::saveBmp(QString filename, int quality) {
    return(save(filename, "bmp", quality));
}
bool Figure::saveJpg(QString filename, int quality) {
    return(save(filename, "jpg", quality));
}
bool Figure::savePng(QString filename, int quality) {
    return(save(filename, "png", quality));
}
bool Figure::save(const QString &fileName, const char *format, int quality) {
    QPixmap screenshot(size());
    render(&screenshot);
    return(screenshot.toImage().save(fileName, format, quality));
}

// Private
void Figure::_initialize(uint rows, uint columns) {
    QPalette defaultPalette = palette();
    defaultPalette.setColor(QPalette::Window, Qt::white);
    setPalette(defaultPalette);

    QScopedPointer<QGridLayout> grid(new QGridLayout());
    if (rows == 0)
        rows = 1;
    if (columns == 0)
        columns = 1;

    _i = 0;
    _j = 0;
    _rows = rows;
    _columns = columns;

    QScopedPointer<QCustomPlot> plot;
    for (uint i = 0; i < rows; i++) {
        for (uint j = 0; j < columns; j++) {
            plot.reset(new QCustomPlot());
            grid->addWidget(plot.take(), i, j);
        }
    }
    setLayout(grid.take());
    _margins = 7;
    _minFigureHeight = 150;
    _minFigureWidth = 300;
    _setMinimumSizes();
}
void Figure::_setMinimumSizes() {
    _layout()->setContentsMargins(_margins, _margins, _margins, _margins);
    _layout()->setSpacing(_margins);
    setMinimumWidth((2 + _columns-1)*_margins + _columns*_minFigureWidth);
    setMinimumHeight((2 + _rows-1)*_margins + _rows*_minFigureHeight);
}
QGridLayout* Figure::_layout() {
    return(qobject_cast<QGridLayout*>(layout()));
}

void Figure::_addRows(uint rows) {
    QScopedPointer<QCustomPlot> plot;
    for (uint i = _rows; i < rows; i++) {
        for (uint j = 0; j < _columns; j++) {
            plot.reset(new QCustomPlot());
            _layout()->addWidget(plot.take(), i, j);
        }
    }
}
void Figure::_deleteRows(uint rows) {
    for (uint i = rows; i < _rows; i++) {
        for (uint j = 0; j < _columns; j++) {
            QLayoutItem *item = _layout()->itemAtPosition(i, j);
            _layout()->removeItem(item);
            delete item;
        }
    }
}
void Figure::_addColumns(uint columns) {
    QScopedPointer<QCustomPlot> plot;
    for (uint i = 0; i < _rows; i++) {
        for (uint j = _columns; j < columns; j++) {
            plot.reset(new QCustomPlot());
            _layout()->addWidget(plot.take(), i, j);
        }
    }
}
void Figure::_deleteColumns(uint columns) {
    for (uint i = 0; i < _rows; i++) {
        for (uint j = columns; j < _columns; j++) {
            QLayoutItem *item = _layout()->itemAtPosition(i, j);
            _layout()->removeItem(item);
            delete item;
        }
    }
}
