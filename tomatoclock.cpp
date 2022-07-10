#include "tomatoclock.h"
#include <QWidget>
#include<QDebug>

//#define sound_1 ":/sound/coin.wav"  //我需要像这样的两个定义去选择播放曲目
#define music_1 "阿巴阿巴"
#define music_2 "阿巴阿巴"

TomatoClock::TomatoClock(QWidget *parent,int wid,int heig,QString str)
    : QMainWindow(parent) ,time(0),timeout(25 * 60),timesum(0),rest(5*60), clocknum(2), StartOrNot(false), sate(true) {

    background=":/image/sky_image_two";

//    this -> setWindowTitle("番茄钟");
//    this -> setFixedSize(wid, heig);
//    this->setWindowIcon(QPixmap("图标图的路径"));//这里之后补上软件图标(不补也行，这个就软件小图标，之后想设计可以设计一下，不想设计直接注释掉)

    soundbutton=new MyPushButton(this);
    soundbutton1=new MyPushButton(this);
    soundbutton1->hide();
    soundbutton2=new MyPushButton(this);
    soundbutton2->hide();


    soundbutton->move(0, 720-50);
    soundbutton->setText("选择音乐");
    soundbutton->setFixedSize(100,50);

    soundbutton1->move(100, 720-50);
    soundbutton1->setText("音乐1");
    soundbutton1->setFixedSize(100,50);

    soundbutton2->move(200, 720-50);
    soundbutton2->setText("音乐2");
    soundbutton2->setFixedSize(100,50);

    QSoundEffect * startSound = new QSoundEffect(this);

  //  QSound *music2=new QSound(music_2,this);
    connect(soundbutton,&QPushButton::clicked,[=]()
    {
        if(soundclickORnot==false)
        {
            sound_player();
            soundclickORnot=true;
            soundbutton->setText("取消选择");
        }
        else
        {
            soundbutton1->hide();
            soundbutton2->hide();
            soundclickORnot=false;
            soundbutton->setText("选择音乐");
        }
    });

    connect(soundbutton1,&QPushButton::clicked,[=]()
    {
        soundbutton1->hide();
        soundbutton2->hide();
        startSound->setSource(QUrl::fromLocalFile(":/music/0.wav"));
        startSound->play();//设置单曲循环
        startSound->setLoopCount(-1);
        soundclickORnot=false;
        soundbutton->setText("选择音乐");
    });

    connect(soundbutton2,&QPushButton::clicked,[=]()
    {
        soundbutton1->hide();
        soundbutton2->hide();
        startSound->setSource(QUrl::fromLocalFile(":/music/1.wav"));
        startSound->play();//设置单曲循环
        startSound->setLoopCount(-1);
        soundclickORnot=false;
        soundbutton->setText("选择音乐");
    });


    WorkAddMin=new QPushButton;
    WorkSubMin=new QPushButton;
    RestAddMin=new QPushButton;
    RestSubMin=new QPushButton;
    ClockNumAddMin=new QPushButton;
    ClockNumSubMin=new QPushButton;
    Begin=new MyPushButton(this);//界面1的开始

    Start=new MyPushButton(this);//暂停or开始
    Over=new MyPushButton(this);//结束番茄种
    Start->move(250, 530);
    Start->setText("暂停");
    Start->setFixedSize(280,80);

    Over->move(742, 530);
    Over->setText("停止");
    Over->setFixedSize(280,80);


    Start->hide();
    Over->hide();

    Begin->move(500, 531);
    Begin->setText("开始");
    Begin->setFixedSize(280,80);


    WorkAddMin->setParent(this);
    WorkAddMin->setText("+");
    WorkAddMin->move(360, 367);
    WorkAddMin->resize(30,30);
    WorkAddMin->setStyleSheet("QPushButton {"
                         "  background-color: rgb(255,255,255);"
                         "  font-family: \"KaiTi\";"
                         "  font: bold;"
                         "  color: rgb(0,119,182);"
                         "  border-style: solid;"
                         "  border-radius: 2px;"
                         "  border-width: 1px;"
                         "}"
                         "QPushButton:pressed {"
                         "  background-color: rgb(101,200,255);"
                         "  border-color: rgb(255,255,255);"
                         "  color: rgb(255,255,255);"
                         "}");

    WorkSubMin->setParent(this);
    WorkSubMin->setText("-");
    WorkSubMin->move(85, 367);
    WorkSubMin->resize(30,30);
    WorkSubMin->setStyleSheet("QPushButton {"
                         "  background-color: rgb(255,255,255);"
                         "  font-family: \"KaiTi\";"
                         "  font: bold;"
                         "  color: rgb(0,119,182);"
                         "  border-style: solid;"
                         "  border-radius: 2px;"
                         "  border-width: 1px;"
                         "}"
                         "QPushButton:pressed {"
                         "  background-color: rgb(101,200,255);"
                         "  border-color: rgb(255,255,255);"
                         "  color: rgb(255,255,255);"
                         "}");

    RestAddMin->setParent(this);
    RestAddMin->setText("+");
    RestAddMin->move(765, 367);
    RestAddMin->resize(30,30);
    RestAddMin->setStyleSheet("QPushButton {"
                         "  background-color: rgb(255,255,255);"
                         "  font-family: \"KaiTi\";"
                         "  font: bold;"
                         "  color: rgb(0,119,182);"
                         "  border-style: solid;"
                         "  border-radius: 2px;"
                         "  border-width: 1px;"
                         "}"
                         "QPushButton:pressed {"
                         "  background-color: rgb(101,200,255);"
                         "  border-color: rgb(255,255,255);"
                         "  color: rgb(255,255,255);"
                         "}");

    RestSubMin->setParent(this);
    RestSubMin->setText("-");
    RestSubMin->move(481, 367);
    RestSubMin->resize(30,30);
    RestSubMin->setStyleSheet("QPushButton {"
                         "  background-color: rgb(255,255,255);"
                         "  font-family: \"KaiTi\";"
                         "  font: bold;"
                         "  color: rgb(0,119,182);"
                         "  border-style: solid;"
                         "  border-radius: 2px;"
                         "  border-width: 1px;"
                         "}"
                         "QPushButton:pressed {"
                         "  background-color: rgb(101,200,255);"
                         "  border-color: rgb(255,255,255);"
                         "  color: rgb(255,255,255);"
                         "}");

    ClockNumAddMin->setParent(this);
    ClockNumAddMin->setText("+");
    ClockNumAddMin->move(1165, 367);
    ClockNumAddMin->resize(30,30);
    ClockNumAddMin->setStyleSheet("QPushButton {"
                         "  background-color: rgb(255,255,255);"
                         "  font-family: \"KaiTi\";"
                         "  font: bold;"
                         "  color: rgb(0,119,182);"
                         "  border-style: solid;"
                         "  border-radius: 2px;"
                         "  border-width: 1px;"
                         "}"
                         "QPushButton:pressed {"
                         "  background-color: rgb(101,200,255);"
                         "  border-color: rgb(255,255,255);"
                         "  color: rgb(255,255,255);"
                         "}");

    ClockNumSubMin->setParent(this);
    ClockNumSubMin->setText("-");
    ClockNumSubMin->move(882, 367);
    ClockNumSubMin->resize(30,30);
    ClockNumSubMin->setStyleSheet("QPushButton {"
                         "  background-color: rgb(255,255,255);"
                         "  font-family: \"KaiTi\";"
                         "  font: bold;"
                         "  color: rgb(0,119,182);"
                         "  border-style: solid;"
                         "  border-radius: 2px;"
                         "  border-width: 1px;"
                         "}"
                         "QPushButton:pressed {"
                         "  background-color: rgb(101,200,255);"
                         "  border-color: rgb(255,255,255);"
                         "  color: rgb(255,255,255);"
                         "}");

    worktimedisplayer.setParent(this);
    worktimedisplayer.move(135+50,322);
    worktimedisplayer.resize(200-20, 120);
    worktimedisplayer.setStyleSheet("QLabel {"
                                "   color:rgb(0,119,182);"
                                "   font-family:\"KaiTi\";"
                                "   font: bold 20px;"
                                "   font-size: 40px"
                                "}");
    worktimedisplayer.setAttribute(Qt::WA_TranslucentBackground);
    if(timeout<10*60)
    {
        worktimedisplayer.setText("0"+QString::number(timeout/60, 10)+":00");
    }
    else
    {
        worktimedisplayer.setText(QString::number(timeout/60, 10)+":00");
    }
    worktimedisplayer.setAlignment(Qt::AlignHCenter);
    worktimedisplayer.setAlignment(Qt::AlignVCenter);


    resttimedisplayer.setParent(this);
    resttimedisplayer.move(537+50,322);
    resttimedisplayer.resize(200-20, 120);
    resttimedisplayer.setStyleSheet("QLabel {"
                                "   color:rgb(0,119,182);"
                                "   font-family:\"KaiTi\";"
                                "   font: bold 20px;"
                                "   font-size: 40px"
                                "}");
    resttimedisplayer.setAttribute(Qt::WA_TranslucentBackground);
    if(rest<10*60)
    {
        resttimedisplayer.setText("0"+QString::number(rest/60, 10)+":00");
    }
    else
    {
        resttimedisplayer.setText(QString::number(rest/60, 10)+":00");
    }
    resttimedisplayer.setAlignment(Qt::AlignHCenter);
    resttimedisplayer.setAlignment(Qt::AlignVCenter);


    clocknumdisplayer.setParent(this);
    clocknumdisplayer.move(937+50,322);
    clocknumdisplayer.resize(200-20, 120);
    clocknumdisplayer.setStyleSheet("QLabel {"
                                "   color:rgb(0,119,182);"
                                "   font-family:\"KaiTi\";"
                                "   font: bold 20px;"
                                "   font-size: 40px"
                                "}");
    clocknumdisplayer.setText(" "+QString::number(clocknum, 10)+"个");
    clocknumdisplayer.setAlignment(Qt::AlignHCenter);
    clocknumdisplayer.setAlignment(Qt::AlignVCenter);
    clocknumdisplayer.setAttribute(Qt::WA_TranslucentBackground);


    tip[0].setParent(this);
    tip[0].move(500+50, 52);
    tip[0].resize(280, 110);
    tip[0].setStyleSheet("QLabel {"
                       "   color:rgb(0,119,182);"
                       "   font-family:\"KaiTi\";"
                       "   font: bold 20px;"
                       "   font-size: 40px"
                       "}");
    tip[0].setText("工作中");
    tip[0].setAttribute(Qt::WA_TranslucentBackground);
    tip[0].hide();

    tip[1].setParent(this);
    tip[1].move(100+50, 207);
    tip[1].resize(280, 80);
    tip[1].setStyleSheet("QLabel {"
                       "   color:rgb(0,119,182);"
                       "   font-family:\"KaiTi\";"
                       "   font: bold 20px;"
                       "   font-size: 40px"
                       "}");
    tip[1].setText("工作时间");
    tip[1].setAttribute(Qt::WA_TranslucentBackground);

    tip[2].setParent(this);
    tip[2].move(500+50, 207);
    tip[2].resize(280, 80);
    tip[2].setStyleSheet("QLabel {"
                       "   color:rgb(0,119,182);"
                       "   font-family:\"KaiTi\";"
                       "   font: bold 20px;"
                       "   font-size: 40px"
                       "}");
    tip[2].setText("休息时间");
    tip[2].setAttribute(Qt::WA_TranslucentBackground);

    tip[3].setParent(this);
    tip[3].move(900+50, 207);
    tip[3].resize(280, 80);
    tip[3].setAttribute(Qt::WA_TranslucentBackground);
    tip[3].setStyleSheet("QLabel {"
                       "   color:rgb(0,119,182);"
                       "   font-family:\"KaiTi\";"
                       "   font: bold 20px;"
                       "   font-size: 40px"
                       "}");
    tip[3].setText("番茄钟数");
    tip[1].setAttribute(Qt::WA_TranslucentBackground);
    tip[2].setAttribute(Qt::WA_TranslucentBackground);
    tip[3].setAttribute(Qt::WA_TranslucentBackground);
    for(int i=0;i<4;i++)
    {
        tip[i].setAlignment(Qt::AlignHCenter);
        tip[i].setAlignment(Qt::AlignVCenter);
    }

    connect(&timer, &QTimer::timeout, this, &TomatoClock::onClockTime);
    connect(Begin, &QPushButton::clicked, this, &TomatoClock::BeginClock);
    connect(Start, &QPushButton::clicked, this, &TomatoClock::startClock);

    connect(WorkAddMin, &QPushButton::clicked, this, &TomatoClock::WorkAddtime);
    connect(WorkSubMin, &QPushButton::clicked, this, &TomatoClock::WorkSubtime);
    connect(RestAddMin, &QPushButton::clicked, this, &TomatoClock::RestAddtime);
    connect(RestSubMin, &QPushButton::clicked, this, &TomatoClock::RestSubtime);
    connect(ClockNumAddMin, &QPushButton::clicked, this, &TomatoClock::ClockNumAdd);
    connect(ClockNumSubMin, &QPushButton::clicked, this, &TomatoClock::ClockNumSub);

    if(clocknum<0)//这里就是结束时刻了
    {
        this->clockover();
    }

    connect(Over,&QPushButton::clicked,//自己结束的操作
            [=]()
    {
        this->click_over();
    });
}

TomatoClock::~TomatoClock() {
    timer.stop();
}

void TomatoClock::onClockTime() {
    if((time < timeout)&&sate == true) {
        worktimedisplayer.setText(QString("%1").arg(time/60, 2, 10, QLatin1Char('0'))+":"+QString("%1").arg(time%60, 2, 10, QLatin1Char('0')));
        resttimedisplayer.setText(QString("%1").arg((timeout-time)/60, 2, 10, QLatin1Char('0'))+":"+QString("%1").arg((timeout-time)%60, 2, 10, QLatin1Char('0')));
        clocknumdisplayer.setText(QString::number(clocknum));
        time++;
        timesum++;
    }else {
        if(sate == true) {//排除法
            time = sate = 0;
            timeout2 = timeout;
            timeout = rest;
            clocknum--;
            tip[0].setText("休息中");
            tip[1].setText("休息时长");
            tip[2].setText("距离下次工作");
        }
    }

    if((time < timeout)&&sate == false) {
        worktimedisplayer.setText(QString("%1").arg(time/60, 2, 10, QLatin1Char('0'))+":"+QString("%1").arg(time%60, 2, 10, QLatin1Char('0')));
        resttimedisplayer.setText(QString("%1").arg((timeout-time)/60, 2, 10, QLatin1Char('0'))+":"+QString("%1").arg((timeout-time)%60, 2, 10, QLatin1Char('0')));
        clocknumdisplayer.setText(QString::number(clocknum));
        time++;
    }else {
        if(sate == false) {
            time = 0;
            sate = 1;
            timeout = timeout2;
            tip[0].setText("工作中");
            tip[1].setText("专注时长");
            tip[2].setText("距离下次休息");
        }
    }

}

void TomatoClock::startClock()
{
    if(StartOrNot != true) {
        timer.start(1000);
        Start->setText("暂停");
        StartOrNot = !StartOrNot;
    }else {
        timer.stop();
        Start->setText("开始");
        StartOrNot = !StartOrNot;
    }
}

void TomatoClock::BeginClock()
{

    tip[0].setText("工作中");
    tip[0].show();
    tip[1].setText("专注时长");
    tip[2].setText("距离下次休息");
    tip[3].setText("剩余番茄钟数");

    WorkAddMin->hide();
    WorkSubMin->hide();
    RestAddMin->hide();
    RestSubMin->hide();
    ClockNumAddMin->hide();
    ClockNumSubMin->hide();
    Begin->hide();

    Start->show();
    Over->show();

    timer.start(1000);
    Start->setText("暂停");
    StartOrNot = !StartOrNot;
}
void TomatoClock::WorkAddtime() {
    timeout += 60;
    if(timeout<10*60)
    {
        worktimedisplayer.setText("0"+QString::number(timeout/60, 10)+":00");
    }
    else
    {
        worktimedisplayer.setText(QString::number(timeout/60, 10)+":00");
    }
}
void TomatoClock::WorkSubtime() {
    if(timeout>60){
        timeout -=60;
    }else{
        timeout = 60;
    }
    if(timeout<10*60)
    {
        worktimedisplayer.setText("0"+QString::number(timeout/60, 10)+":00");
    }
    else
    {
        worktimedisplayer.setText(QString::number(timeout/60, 10)+":00");
    }
}

void TomatoClock::RestAddtime() {
    rest += 60;
    if(rest<10*60)
    {
        resttimedisplayer.setText("0"+QString::number(rest/60, 10)+":00");
    }
    else
    {
        resttimedisplayer.setText(QString::number(rest/60, 10)+":00");
    }
}

void TomatoClock::RestSubtime() {
    if(rest>60){
        rest -=60;
    }else{
        rest = 60;
    }
    if(rest<10*60)
    {
        resttimedisplayer.setText("0"+QString::number(rest/60, 10)+":00");
    }
    else
    {
        resttimedisplayer.setText(QString::number(rest/60, 10)+":00");
    }
}

void TomatoClock::ClockNumAdd() {
    clocknum++;
    clocknumdisplayer.setText(" "+QString::number(clocknum, 10)+"个");
}
void TomatoClock::ClockNumSub() {
    if(clocknum>1){
        clocknum--;
    }else{
        clocknum=1;
    }
    clocknumdisplayer.setText(" "+QString::number(clocknum, 10)+"个");
}

void TomatoClock::click_over()
{
    this->startClock();
    int ret=QMessageBox::information(this, "结束", "是否要提前结束番茄钟?", QMessageBox::Yes | QMessageBox::No);
        if(ret==QMessageBox::Yes){
            this->startClock();
            this->clockover();
        }
        else
            this->startClock();
           return;
}


void TomatoClock::clockover()
{
    timer.stop();
    point=(timesum/60/25)*10;

    //专注次数
    QFile focus_num("./File/focus_num.txt");
    QString strfocus_num;
    int intfocus_num=0;
    if(!focus_num.open(QIODevice::ReadOnly|QIODevice::Text))
    {
            qDebug()<<"文件打开失败";
    }
    while (!focus_num.atEnd())
    {
             QByteArray line = focus_num.readLine();
             strfocus_num=line.toStdString().c_str();
    }
    focus_num.close();

    intfocus_num=strfocus_num.toInt();
    intfocus_num++;
    strfocus_num=QString::number(intfocus_num);

    if(!focus_num.open(QIODevice::WriteOnly|QIODevice::Text))
    {
            qDebug()<<"文件打开失败";
    }
    focus_num.write(strfocus_num.toStdString().c_str());
    focus_num.close();

    //专注时间
    QFile focus_time("./File/focus_time.txt");
    QString strfocus_time;
    int intfocus_time=0;
    if(!focus_time.open(QIODevice::ReadOnly|QIODevice::Text))
    {
            qDebug()<<"文件打开失败";
    }
    while (!focus_time.atEnd())
    {
             QByteArray line = focus_time.readLine();
             strfocus_time=line.toStdString().c_str();
    }
    focus_time.close();

    intfocus_time=strfocus_time.toInt();
    intfocus_time=intfocus_time+timesum/60;
    strfocus_time=QString::number(intfocus_time);

    if(!focus_time.open(QIODevice::WriteOnly|QIODevice::Text))
    {
            qDebug()<<"文件打开失败";
    }
    focus_time.write(strfocus_time.toStdString().c_str());
    focus_time.close();


    //分数
    QFile point_TXT("point.txt");
    QString strpoint_TXT;
    int intpoint_TXT=0;
    if(!point_TXT.open(QIODevice::ReadOnly|QIODevice::Text))
    {
            qDebug()<<"文件打开失败";
    }
    while (!point_TXT.atEnd())
    {
             QByteArray line = point_TXT.readLine();
             strpoint_TXT=line.toStdString().c_str();
    }
    point_TXT.close();

    intpoint_TXT=strpoint_TXT.toInt();
    intpoint_TXT=intpoint_TXT+point;
    strpoint_TXT=QString::number(intpoint_TXT);

    if(!point_TXT.open(QIODevice::WriteOnly|QIODevice::Text))
    {
            qDebug()<<"文件打开失败";
    }
    point_TXT.write(strpoint_TXT.toStdString().c_str());
    point_TXT.close();

    saveweek();

    QString str;
    str="您本次专注时长："+QString("%1").arg(timesum/60)+"分钟\n"+"您本次获得积分："+QString("%1").arg(point)+"分";
    QMessageBox::about(this,"恭喜！",str);

    time=0;
    timesum=0;
    rest=5*60;
    clocknum=2;
    StartOrNot=false;
    timeout=25*60;
    sate=true;
    WorkAddMin->show();
    WorkSubMin->show();
    RestAddMin->show();
    RestSubMin->show();
    ClockNumAddMin->show();
    ClockNumSubMin->show();
    Begin->show();

    if(timeout<10*60)
    {
        worktimedisplayer.setText("0"+QString::number(timeout/60, 10)+":00");
    }
    else
    {
        worktimedisplayer.setText(QString::number(timeout/60, 10)+":00");
    }

    if(rest<10*60)
    {
        resttimedisplayer.setText("0"+QString::number(rest/60, 10)+":00");
    }
    else
    {
        resttimedisplayer.setText(QString::number(rest/60, 10)+":00");
    }

    clocknumdisplayer.setText(" "+QString::number(clocknum, 10)+"个");

    Start->hide();
    Over->hide();
    tip[0].hide();
    tip[1].setText("工作时间");
    tip[2].setText("休息时间");
    tip[3].setText("番茄钟数");
}

void TomatoClock::saveweek()
{
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_week = current_date_time.toString("ddd");
    //qDebug()<<"week "<<current_week;
    if(current_week=="\"周一\"")
    {
        QFile focus_time1("./File/focus_time1.txt");
        QString strfocus_time1;
        int intfocus_time1=0;
        if(!focus_time1.open(QIODevice::ReadOnly|QIODevice::Text))
        {
                qDebug()<<"文件打开失败";
        }
        while (!focus_time1.atEnd())
        {
                 QByteArray line = focus_time1.readLine();
                 strfocus_time1=line.toStdString().c_str();
        }
        focus_time1.close();

        intfocus_time1=strfocus_time1.toInt();
        intfocus_time1=intfocus_time1+timesum/60;
        strfocus_time1=QString::number(intfocus_time1);

        if(!focus_time1.open(QIODevice::WriteOnly|QIODevice::Text))
        {
                qDebug()<<"文件打开失败";
        }
        focus_time1.write(strfocus_time1.toStdString().c_str());
        focus_time1.close();
    }
    else if(current_week=="\"周二\"")
    {
        QFile focus_time2("./File/focus_time2.txt");
        QString strfocus_time2;
        int intfocus_time2=0;
        if(!focus_time2.open(QIODevice::ReadOnly|QIODevice::Text))
        {
                qDebug()<<"文件打开失败";
        }
        while (!focus_time2.atEnd())
        {
                 QByteArray line = focus_time2.readLine();
                 strfocus_time2=line.toStdString().c_str();
        }
        focus_time2.close();

        intfocus_time2=strfocus_time2.toInt();
        intfocus_time2=intfocus_time2+timesum/60;
        strfocus_time2=QString::number(intfocus_time2);

        if(!focus_time2.open(QIODevice::WriteOnly|QIODevice::Text))
        {
                qDebug()<<"文件打开失败";
        }
        focus_time2.write(strfocus_time2.toStdString().c_str());
        focus_time2.close();
    }
    else if(current_week=="\"周三\"")
    {
        QFile focus_time3("./File/focus_time3.txt");
        QString strfocus_time3;
        int intfocus_time3=0;
        if(!focus_time3.open(QIODevice::ReadOnly|QIODevice::Text))
        {
                qDebug()<<"文件打开失败";
        }
        while (!focus_time3.atEnd())
        {
                 QByteArray line = focus_time3.readLine();
                 strfocus_time3=line.toStdString().c_str();
        }
        focus_time3.close();

        intfocus_time3=strfocus_time3.toInt();
        intfocus_time3=intfocus_time3+timesum/60;
        strfocus_time3=QString::number(intfocus_time3);

        if(!focus_time3.open(QIODevice::WriteOnly|QIODevice::Text))
        {
                qDebug()<<"文件打开失败";
        }
        focus_time3.write(strfocus_time3.toStdString().c_str());
        focus_time3.close();
    }
    else if(current_week=="\"周四\"")
    {
        QFile focus_time4("./File/focus_time4.txt");
        QString strfocus_time4;
        int intfocus_time4=0;
        if(!focus_time4.open(QIODevice::ReadOnly|QIODevice::Text))
        {
                qDebug()<<"文件打开失败";
        }
        while (!focus_time4.atEnd())
        {
                 QByteArray line = focus_time4.readLine();
                 strfocus_time4=line.toStdString().c_str();
        }
        focus_time4.close();

        intfocus_time4=strfocus_time4.toInt();
        intfocus_time4=intfocus_time4+timesum/60;
        strfocus_time4=QString::number(intfocus_time4);

        if(!focus_time4.open(QIODevice::WriteOnly|QIODevice::Text))
        {
                qDebug()<<"文件打开失败";
        }
        focus_time4.write(strfocus_time4.toStdString().c_str());
        focus_time4.close();
    }
    else if(current_week=="\"周五\"")
    {
        QFile focus_time5("./File/focus_time5.txt");
        QString strfocus_time5;
        int intfocus_time5=0;
        if(!focus_time5.open(QIODevice::ReadOnly|QIODevice::Text))
        {
                qDebug()<<"文件打开失败";
        }
        while (!focus_time5.atEnd())
        {
                 QByteArray line = focus_time5.readLine();
                 strfocus_time5=line.toStdString().c_str();
        }
        focus_time5.close();

        intfocus_time5=strfocus_time5.toInt();
        intfocus_time5=intfocus_time5+timesum/60;
        strfocus_time5=QString::number(intfocus_time5);

        if(!focus_time5.open(QIODevice::WriteOnly|QIODevice::Text))
        {
                qDebug()<<"文件打开失败";
        }
        focus_time5.write(strfocus_time5.toStdString().c_str());
        focus_time5.close();
    }
    else if(current_week=="\"周六\"")
    {
        QFile focus_time6("./File/focus_time6.txt");
        QString strfocus_time6;
        int intfocus_time6=0;
        if(!focus_time6.open(QIODevice::ReadOnly|QIODevice::Text))
        {
                qDebug()<<"文件打开失败";
        }
        while (!focus_time6.atEnd())
        {
                 QByteArray line = focus_time6.readLine();
                 strfocus_time6=line.toStdString().c_str();
        }
        focus_time6.close();

        intfocus_time6=strfocus_time6.toInt();
        intfocus_time6=intfocus_time6+timesum/60;
        strfocus_time6=QString::number(intfocus_time6);

        if(!focus_time6.open(QIODevice::WriteOnly|QIODevice::Text))
        {
                qDebug()<<"文件打开失败";
        }
        focus_time6.write(strfocus_time6.toStdString().c_str());
        focus_time6.close();
    }
    else if(current_week=="\"周日\"")
    {
        QFile focus_time7("/File/focus_time7.txt");
        QString strfocus_time7;
        int intfocus_time7=0;
        if(!focus_time7.open(QIODevice::ReadOnly|QIODevice::Text))
        {
                qDebug()<<"文件打开失败";
        }
        while (!focus_time7.atEnd())
        {
                 QByteArray line = focus_time7.readLine();
                 strfocus_time7=line.toStdString().c_str();
        }
        focus_time7.close();

        intfocus_time7=strfocus_time7.toInt();
        intfocus_time7=intfocus_time7+timesum/60;
        strfocus_time7=QString::number(intfocus_time7);

        if(!focus_time7.open(QIODevice::WriteOnly|QIODevice::Text))
        {
                qDebug()<<"文件打开失败";
        }
        focus_time7.write(strfocus_time7.toStdString().c_str());
        focus_time7.close();
    }
}

void TomatoClock::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    //画背景
    QPixmap pix;
    pix.load(background);
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

void TomatoClock::sound_player()
{
    //这两行添加文件之后之后注释掉
   // soundbutton1->show();
   // soundbutton2->show();
    //这两行添加文件之后之后注释掉

    QFile music_TXT("./File/Musicplay.txt");
    QString strmusic_TXT;
    int intmusic_TXT;
    if(!music_TXT.open(QIODevice::ReadOnly|QIODevice::Text))
    {
            qDebug()<<"文件打开失败";
    }
    while (!music_TXT.atEnd())
    {
             QByteArray line = music_TXT.readLine();
             strmusic_TXT=line.toStdString().c_str();
    }
    music_TXT.close();

    intmusic_TXT=strmusic_TXT.toInt();

    if(intmusic_TXT==12||intmusic_TXT==21)
    {
        soundbutton1->show();
        soundbutton2->show();
    }
    else if(intmusic_TXT==1)
    {
        soundbutton1->show();
    }
    else if(intmusic_TXT==2)
    {
        soundbutton2->show();
    }
}
