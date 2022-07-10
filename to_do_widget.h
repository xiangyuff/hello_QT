#ifndef TO_DO_WIDGET_H
#define TO_DO_WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QTextEdit>
#include <QString>
#include <QLineEdit>
#include <QPalette>
#include <QLabel>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include "todolist.h"


namespace Ui {
class to_do_widget;
}

class to_do_widget : public QWidget
{
    Q_OBJECT
    // QList<QLabel*> labelList;
     QTextEdit*textedit = nullptr;
     QList<QLineEdit*> lineEdit;
 //    QFile timelineFile("./timeline.txt");


public:
    explicit to_do_widget(QWidget *parent = nullptr);
    ~to_do_widget();
     void paintEvent(QPaintEvent*);
     QWidget* returnthis(void);

private:
    Ui::to_do_widget *ui;
};

#endif // TO_DO_WIDGET_H
