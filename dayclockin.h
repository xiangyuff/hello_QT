#ifndef DAYCLOCKIN_H
#define DAYCLOCKIN_H

#include<QWidget>
#include<QMainWindow>
#include"mypushbutton.h"
#include<QDateTime>
#include<QFile>
#include"qcustomcalendarwidget.h"
#include<QPainter>
#include<QLabel>


class DayClockin:public QMainWindow
{
    Q_OBJECT
public:
    DayClockin();
    explicit DayClockin(QWidget *parent,int wid,int heig,QString str="://image/background.jpg");
    MyPushButton *dailyClockin;
    QCustomCalendarWidget *calendar;
    void paintEvent(QPaintEvent*);

    QString background;
    QLabel show_isin;

};

#endif // DAYCLOCKIN_H
