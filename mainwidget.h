#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QDebug>
#include <QPainter>

#include "mypushbutton.h"
#include "welcome_widget.h"
#include "to_do_widget.h"
#include "dataclasswidget.h"
#include "tomatoclock.h"
#include "dayclockin.h"

namespace Ui {
class mainWidget;
}

class mainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit mainWidget(QWidget *parent = nullptr);
    ~mainWidget();

private:
    Ui::mainWidget *ui;
    int eggFlag = 0 ;
};

#endif // MAINWIDGET_H
