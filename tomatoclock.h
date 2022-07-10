#ifndef TOMATOCLOCK_H
#define TOMATOCLOCK_H

#include <QWidget>
#include<QMainWindow>
#include<QLabel>
#include<QTimer>
#include<QMessageBox>
#include<QFile>
#include<QTextStream>
#include<QPainter>
#include <QSoundEffect>
#include<QDateTime>
#include"mypushbutton.h"

/*这里说一下需要番茄钟需要被提供的东西
 1.创建对象的时候传背景图路径
 2.需要一个QFile，命名为Musicplay.txt，里面有一个数字保存已经解锁的音乐，函数sound_player需要这个文件(也可以合完之后发给我我来弄)
 3.需要一个宏定义音乐的文件路径，cpp文件里
 4.如果发现什么bug随时联系我
*/
class TomatoClock:public QMainWindow
{
    Q_OBJECT

public:
    explicit TomatoClock(QWidget *parent,int wid=1280,int heig=720,QString str="://image/background.jpg");//str是背景图的路径
    ~TomatoClock();
    //void paintEvent(QPaintEvent *);

    void onClockTime();
    void startClock();
    void BeginClock();

    void WorkAddtime();
    void WorkSubtime();
    void RestAddtime();
    void RestSubtime();
    void ClockNumAdd();
    void ClockNumSub();
    void clockover();
    void click_over();
    void sound_player();
    void saveweek();

    QPushButton* WorkAddMin,*WorkSubMin;
    QPushButton* RestAddMin,*RestSubMin;
    QPushButton* ClockNumAddMin,*ClockNumSubMin;
    //MyPushButton* ClockNum;
    MyPushButton* Begin;
    MyPushButton* Start;
    MyPushButton* Over;
    //MyPushButton* Back;

    MyPushButton* soundbutton,*soundbutton1,*soundbutton2;

    QLabel worktimedisplayer;
    QLabel resttimedisplayer;
    QLabel clocknumdisplayer;
    QLabel tip[4];
    QTimer timer;
    QString background;

    int time, timeout, timeout2;
    int timesum;//记录此次时长
    int rest;
    int clocknum;
    int point;
    bool StartOrNot, sate;
    bool soundclickORnot=false;
    //int Time;//此次记录时长
    void paintEvent(QPaintEvent*);


};

#endif // TOMATOCLOCK_H
