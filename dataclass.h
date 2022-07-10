#ifndef DATACLASS_H
#define DATACLASS_H

#include <QWidget>
#include<QtCharts>
#include<QPainter>
#include<QColor>
#include <QGridLayout>

#include "todolist.h"
#include "interface.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DataClass; }
QT_END_NAMESPACE

class DataClass : public QWidget
{
    Q_OBJECT

public:
    DataClass(QWidget *parent = nullptr);
    ~DataClass();

private:
    Ui::DataClass *ui;
    QChart *chart;
    QChart *chart2;
    QChartView *chartView;
    QChartView *chartView2;

//    QBarSet *set0;
//    QBarSeries *serie;
    QValueAxis *axisY;
    Interface i ;


    void paintEvent (QPaintEvent *);
};
#endif // DATACLASS_H
