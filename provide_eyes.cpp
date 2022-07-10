#include "provide_eyes.h"

provide_eyes::provide_eyes(QWidget* widget,QObject *parent)
    : QObject{parent}
{
    init_statement();
    //设置要显示的界面
    m_widget = widget;
    textedit = new QTextEdit(m_widget) ;
    //打开默认是工作模式
    set_text(statements[0]);
   // startTimer(1000);
    qDebug()<<time.toString("mm");

}

void provide_eyes::init_statement (void)
{
    //初始化
    statements <<"请安心工作~";
    statements <<"请休息眼睛:眺望远方或做眼保键操";
}

void provide_eyes::set_text(QString text)
{
    //设置文本框参数
    textedit->setGeometry(690,408,422,170);
    textedit->setStyleSheet("background:transparent;border-width:0;border-style:outset");
    QFont font_one("华文楷体",36,QFont::Bold);
    textedit->setFont(font_one);
 //   textedit->setTextColor(QColor(238,240,244));
    textedit->setTextColor(QColor(117,154,217));

    textedit->setText(text);
    textedit->setReadOnly(true);

}

void provide_eyes::show()
{
    //到25分或55分提醒休息，00分或30提醒工作
    time = QTime::currentTime();
    if (time.toString("mm") =="25" ||time.toString("mm") =="55" )
    {
        set_text(statements[1]);
        QSoundEffect * startSound = new QSoundEffect(this);
        startSound->setSource(QUrl::fromLocalFile(":/music/promote_music.wav"));
        startSound->play();
    }
    else if (time.toString("mm") =="30" ||time.toString("mm") =="00")
    {
         set_text(statements[0]);
         QSoundEffect * startSound = new QSoundEffect(this);
         startSound->setSource(QUrl::fromLocalFile(":/music/promote_music.wav"));
         startSound->play();
    }
}

/*void provide_eyes::timerEvent(QTimerEvent*)
{
    time = QTime::currentTime();
    if (time.toString("mm") =="12" ||time.toString("mm") =="49" )
    {
        set_text(statements[1]);
    }
    else if (time.toString("mm") =="30" ||time.toString("mm") =="00")
    {
         set_text(statements[0]);
    }
}*/

