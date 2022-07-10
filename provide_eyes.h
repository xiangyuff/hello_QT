#ifndef PROVIDE_EYES_H
#define PROVIDE_EYES_H

#include <QObject>
#include <QWidget>
#include <QTime>
#include <QTextEdit>
#include <QString>
#include <QTimerEvent>
#include <QTimer>
#include <QSoundEffect>

class provide_eyes : public QObject
{
    Q_OBJECT
    QTime time = QTime::currentTime();
    QList<QString>statements;
    QWidget *m_widget;
    QTextEdit* textedit = nullptr;
    QTimer *Timer_;

public:
    explicit provide_eyes(QWidget* widget,QObject *parent = nullptr);
    void set_text (QString text);
    void init_statement (void) ;
  //  void timerEvent(QTimerEvent*);
    void show(void);

signals:

};

#endif // PROVIDE_EYES_H
