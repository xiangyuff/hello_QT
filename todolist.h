#ifndef TODOLIST_H
#define TODOLIST_H

#include <QWidget>
#include <QLineEdit>
#include <QPalette>
#include <QPainter>
#include <QString>
#include <QFile>

#include "mypushbutton.h"

class toDoList : public QWidget
{
    Q_OBJECT
public:
    explicit toDoList(QWidget *parent = nullptr);
    explicit toDoList(int x, int y , int type,QString path = "",QWidget *parent = nullptr);
  //  void paintEvent(QPaintEvent*);
    int isvalid();
    ~toDoList();
    QList<QLineEdit*> lineedit_list;

    static void init_static(void);
    static void save_static(void);

    //潍姿看这里！ 记得引用"todolist.h",目前所有接口都在这个头文件里！
    static QList<QString> getFinishedName(void);//返回最新的三个完成的变量名 使用 --- = toDoList::getFinishedName();
    static QList<QString> getUnfinishedName(void);//返回最新的三个完成的变量名 使用 --- = toDoList::getUnfinishedName();
    static QVector<int>getNum(void);//一共两个数,第一个是未完成总数，第二个是已完成总数。
    static int getScore_bianPart(void);//返回分数。
private:
    int start_x;
    int start_y;
    QString filePath ;
    QWidget*m_parent;
    QVector<bool>valid;
    QVector<MyPushButton*> btn_vec_one;
    QVector<MyPushButton*> btn_vec_two;
    QVector<int> scoreRule;

    static QFile record_File;
    static QList<QString> finishedName;
    static QList<QString> unfinishedName;

    static int flag_one ;
    static int flag_two ;

    static int score;
    static QVector <int> num;




signals:

};

#endif // TODOLIST_H
