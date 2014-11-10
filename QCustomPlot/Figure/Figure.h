#ifndef FIGURE_H
#define FIGURE_H


// RsaToolbox
#include "Definitions.h"

// QCustomPlot
#include "qcustomplot.h"

// Qt
#include <QWidget>
#include <QDialog>
#include <QGridLayout>

namespace Ui {
class Figure;
}

namespace RsaToolbox {

class Figure : public QDialog
{
    Q_OBJECT

public:
    explicit Figure(QWidget *parent = 0);
    explicit Figure(uint rows, uint columns,
                    QWidget *parent = 0);
    ~Figure();

    uint rows();
    uint columns();
    void setRows(uint rows);
    void setColumns(uint columns);

    QCustomPlot* plot(uint row, uint column);
    void select(uint row, uint column);
    void addTrace(RsaToolbox::QRowVector y, Qt::GlobalColor color = Qt::black, QString name = "");
    void addTrace(RsaToolbox::QRowVector y, QPen pen, QString name = "");
    void addTrace(RsaToolbox::QRowVector x, RsaToolbox::QRowVector y, Qt::GlobalColor color = Qt::black, QString name = "");
    void addTrace(RsaToolbox::QRowVector x, RsaToolbox::QRowVector y, QPen pen, QString name = "");

    bool saveBmp(QString filename, int quality = -1);
    bool saveJpg(QString filename, int quality = -1);
    bool savePng(QString filename, int quality = -1);
    bool save(const QString & fileName, const char * format = 0, int quality = -1);

private:
    Ui::Figure *ui;

    static uint _figureIndex;

    // index
    uint _i, _j;

    uint _rows;
    uint _columns;
    uint _margins;
    uint _minFigureHeight;
    uint _minFigureWidth;

    void _initialize(uint rows = 1, uint columns = 1);
    void _setMinimumSizes();
    QGridLayout* _layout();

    void _addRows(uint rows);
    void _deleteRows(uint rows);
    void _addColumns(uint columns);
    void _deleteColumns(uint columns);
};
}

#endif // FIGURE_H
