#include "welcome_widget.h"
#include "ui_welcome_widget.h"

welcome_Widget::welcome_Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::welcome_Widget)
{
    ui->setupUi(this);
    //设置窗口大小
    this->setFixedSize(1280,720);
    //设置定时器，每1000毫秒更新时间，实现时钟
    //显示时间和日期
    time = QTime::currentTime();
    ui->label_one->setText(time.toString("hh:mm:ss"));
    QFont font_one("华文楷体",80,QFont::Bold);
    ui->label_one->setGeometry(50,54,500,100);
    ui->label_one->setFont(font_one);
 //   ui->label_one->setStyleSheet("color:#759AD9");
    ui->label_one->setStyleSheet("color:#EEF0F4");
    ui->label_one->setAttribute(Qt::WA_TranslucentBackground);

    date = QDate::currentDate();
    ui->label_two->setText(date.toString("  yyyy/MM/dd"));
    QFont font_two("华文楷体",40,QFont::Bold);
    ui->label_two->setGeometry(50,184,500,100);
    ui->label_two->setFont(font_two);
  //  ui->label_two->setStyleSheet("color:#759AD9");
    ui->label_two->setStyleSheet("color:#EEF0F4");
    ui->label_two->setAttribute(Qt::WA_TranslucentBackground);

    ev_id_1 = startTimer(1000);
    ev_id_2 = startTimer(60000);
    //使用励志标语类
    Encouragement encouragement(this);



}

welcome_Widget::~welcome_Widget()
{
    delete ui;
}

void welcome_Widget::paintEvent(QPaintEvent *)
{


    QPainter painter(this);
    //抗锯齿
    painter.drawPixmap(0,0,QPixmap(":/image/sky_image_two.jpg"));
    painter.setRenderHint(QPainter::Antialiasing);
    //设置背景颜色
    QPen pen_one(QColor(238,240,244));
    painter.setPen(pen_one);
    QBrush brush_one(QColor(238,240,244));
    painter.setBrush(brush_one);
  //  painter.drawRect(0,0,1280,720);

    //画出右上蓝色小格子
    QColor my_blue(207,220,236);
    my_blue.setAlpha(100);
  //  QPen pen_two(QColor(207,220,236));
    QPen pen_two(my_blue);
    pen_two.setWidth(0);
    painter.setPen(pen_two);
 //   QBrush brush_two(QColor(207,220,236));
    QBrush brush_two(my_blue);
    painter.setBrush(brush_two);
    painter.drawRoundedRect(QRect(670,64,512,260),30,30);
    painter.drawRoundedRect(QRect(670,388,512,260),30,30);

    qDebug()<<"绘图";

    //画出左下紫色小格子
  //  QPen pen_three(QColor(151,158,199));
 //   painter.setPen(pen_three);
   // QBrush brush_three(QColor(151,158,199));
    //   painter.setBrush(brush_three);
   // painter.drawRect(670,388,512,260);

    //圆角修饰
//    painter.setPen(pen_one);
//    painter.setBrush(brush_one);
//    painter.drawRect(670-10,64-10,60,60);
//    painter.drawRect(1182-50,64-10,60,60);
//    painter.drawRect(670-10,324-50,60,60);
//    painter.drawRect(1182-50,324-50,60,60);

//    painter.drawRect(670-10,388-10,60,60);
//    painter.drawRect(670-10,648-50,60,60);
//    painter.drawRect(1182-50,388-10,60,60);
//    painter.drawRect(1182-50,648-50,60,60);

//    painter.setPen(pen_two);
//    painter.setBrush(brush_two);
//    painter.drawEllipse(QPoint(670+50,64+50),50,50);
//    painter.drawEllipse(QPoint(1182-50,64+50),50,50);
//    painter.drawEllipse(QPoint(670+50,324-50),50,50);
//    painter.drawEllipse(QPoint(1182-50,324-50),50,50);

//    painter.setPen(pen_three);
//    painter.setBrush(brush_three);
//    painter.drawEllipse(QPoint(670+50,388+50),50,50);
//    painter.drawEllipse(QPoint(1182-50,388+50),50,50);
//    painter.drawEllipse(QPoint(670+50,648-50),50,50);
//    painter.drawEllipse(QPoint(1182-50,648-50),50,50);

    //painter.drawPixmap(50,280,QPixmap(":/image/sky_image.jpg"));

}

void welcome_Widget::timerEvent(QTimerEvent*ev)
{
    //根据计时器更新时间
    if (ev->timerId() == ev_id_1)
    {
        time = QTime::currentTime();
        ui->label_one->setText(time.toString("hh:mm:ss"));

        date = QDate::currentDate();
        ui->label_two->setText(date.toString("yyyy/MM/dd"));
    }

    if (ev->timerId() == ev_id_2)
    {
        //调用provide_eyes里的显示函数
        eyes->show();
        //qDebug()<<"已执行";
    }


}

QWidget* welcome_Widget::returnthis(void)
{
    return this;
}

