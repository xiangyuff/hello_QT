#ifndef DATACLASSWIDGET_H
#define DATACLASSWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPalette>
#include "dataclass.h"

namespace Ui {
class dataClassWidget;
}

class dataClassWidget : public QWidget
{
    Q_OBJECT

public:
    explicit dataClassWidget(QWidget *parent = nullptr);
    ~dataClassWidget();

private:
    Ui::dataClassWidget *ui;
};

#endif // DATACLASSWIDGET_H
