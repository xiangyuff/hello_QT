#ifndef ENCOURAGEMENT_H
#define ENCOURAGEMENT_H

#include <QObject>
#include <QWidget>
#include <QDebug>
#include <QString>
#include <ctime>
#include <QTextEdit>



class Encouragement : public QObject
{
    Q_OBJECT
    QList<QString>statements;
    QWidget * m_widget;
    public:
    explicit Encouragement(QWidget *widget,QObject *parent = nullptr);
    void init_statement (void) ;
    void set_encouragement (void);

signals:

};

#endif // ENCOURAGEMENT_H
