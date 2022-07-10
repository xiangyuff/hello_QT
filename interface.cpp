#include "interface.h"
#include<QFile>
#include<QDebug>

Interface::Interface()
{

}

QVector<int> Interface::FocusNum()//一共2个数,第一个是用户开始使用以来的总专注次数，第二个总的专注时间  单位min
{
    //次数
    QVector<int> data;
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
    data.push_back(intfocus_num);

    //时间
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
    data.push_back(intfocus_time);
    return data;

}
QVector<int> Interface::WeekNum()//一共7个数 表示本周周一到周日的专注时间（如果本周还是周五的话，周六周日就设为-1吧）
{

    QVector<int> data;
    for(int i=1;i<=7;i++)
    {
        QString str1=QString("./File/focus_time%1.txt").arg(i);
        QFile focus_time1(str1);
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
        data.push_back(intfocus_time1);
    }
    return data;
}
int Interface::getScore_YUPart()
{
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
    return intpoint_TXT;

}
