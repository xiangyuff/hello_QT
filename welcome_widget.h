#ifndef WELCOME_WIDGET_H
#define WELCOME_WIDGET_H

#include <QWidget>
#include <QTime>
#include <QLabel>
#include <QPainter>
#include <QSoundEffect>
#include <QDebug>

#include "encouragement.h"
#include "provide_eyes.h"

QT_BEGIN_NAMESPACE
namespace Ui { class welcome_Widget; }
QT_END_NAMESPACE

class welcome_Widget : public QWidget
{
    Q_OBJECT
    int ev_id_1;
    int ev_id_2;

public:
    welcome_Widget(QWidget *parent = nullptr);
    ~welcome_Widget();
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent*ev);
    QWidget* returnthis(void);

private:
    Ui::welcome_Widget *ui;
    QTime time = QTime::currentTime();
    QDate date = QDate::currentDate();
    provide_eyes *eyes = new provide_eyes(this);
};
#endif // WELCOME_WIDGET_H
