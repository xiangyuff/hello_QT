#ifndef INTERFACE_H
#define INTERFACE_H

#include<QMainWindow>
#include<QVector>

//接口文件，记得引用

class Interface:public QMainWindow
{
    Q_OBJECT
public:
    Interface();
    static QVector<int> FocusNum();//一共2个数,第一个是用户开始使用以来的总专注次数，第二个总的专注时间  单位min
    static QVector<int> WeekNum();//一共7个数 表示本周周一到周日的专注时间（如果本周还是周五的话，周六周日就设为-1吧）
    int getScore_YUPart();
};

#endif // INTERFACE_H
