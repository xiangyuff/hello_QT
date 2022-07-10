#include "dayclockin.h"
#include<QDebug>

DayClockin::DayClockin()
{

}

DayClockin::DayClockin(QWidget *parent,int wid,int heig,QString str) : QMainWindow(parent)
{

    background=":/image/sky_image_two";

    this -> setWindowTitle("每日打卡");
    this -> setFixedSize(wid, heig);
    this->setWindowIcon(QPixmap("://image/background.jpg"));//这里之后补上软件图标

    show_isin.setParent(this);
    show_isin.move(716, 260);
    show_isin.resize(360, 200);
    show_isin.setStyleSheet("QLabel {"
                       "   color:rgb(0,119,182);"
                       "   font-family:\"KaiTi\";"
                       "   font: bold 20px;"
                       "   font-size: 40px"
                       "}");
    show_isin.setAttribute(Qt::WA_TranslucentBackground);


    dailyClockin=new MyPushButton(this);
    dailyClockin->move(124, 127);
    dailyClockin->setText("今日打卡");
    dailyClockin->setFixedSize(253,80);
    connect(dailyClockin,&QPushButton::clicked,[=](){

        QDate date = QDate::currentDate();
        QString data=date.toString();
        QFile file("daily_clock_in.txt");
        if(!file.open(QIODevice::WriteOnly|QIODevice::Text)){
                qDebug()<<"文件打开失败";
            }
            //对文件进行写操作
            file.write(data.toStdString().c_str());
            file.close();
            show_isin.setText("今日已打卡");

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
            intpoint_TXT=intpoint_TXT+5;
            strpoint_TXT=QString::number(intpoint_TXT);

            if(!point_TXT.open(QIODevice::WriteOnly|QIODevice::Text))
            {
                    qDebug()<<"文件打开失败";
            }
            point_TXT.write(strpoint_TXT.toStdString().c_str());
            point_TXT.close();

            dailyClockin->hide();

    });


    QFile fileread("daily_clock_in.txt");
    QString dataread;
    if(!fileread.open(QIODevice::ReadOnly|QIODevice::Text))
    {
            qDebug()<<"文件打开失败";
    }
    while (!fileread.atEnd())
    {
             QByteArray line = fileread.readLine();
             dataread=line.toStdString().c_str();
    }
    fileread.close();
    QDate date1 = QDate::currentDate();
    QString data1=date1.toString();
    if(data1==dataread)
    {
        show_isin.setText("今日已打卡");
        dailyClockin->hide();
    }
    else
    {
        show_isin.setText("今日未打卡");
        dailyClockin->show();
    }


    calendar=new QCustomCalendarWidget(this);
    calendar->move(124,244);
    qDebug()<<"here"<<calendar->width()<<" "<<calendar->height();

}

void DayClockin::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    //画背景
    QPixmap pix;
    pix.load(background);
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
