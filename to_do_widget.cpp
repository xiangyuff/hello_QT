#include "to_do_widget.h"
#include "ui_to_do_widget.h"

to_do_widget::to_do_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::to_do_widget)
{
    //ui->widget = new toDoList(0,0,1,"",this);
    ui->setupUi(this);
  //  ui->widget = new toDoList(0,0,1,"",this);
   // ui->widget->show();
    this->setMouseTracking(true);
    this->setFixedSize(1280,720);
    //打印侧边时间轴上的时间
    textedit = new QTextEdit(this);
    textedit->setGeometry(990,10,110,720);
    textedit->setStyleSheet("background:transparent;border-width:0;border-style:outset");
    QFont font_one("华文楷体",24,QFont::Bold);
    textedit->setFont(font_one);
    textedit->setTextColor(QColor(238,240,244));
    textedit->setText("  6:00\n  7:00\n  8:00\n  9:00\n10:00\n11:00\n12:00\n13:00\n14:00\n15:00\n16:00\n17:00\n18:00\n19:00\n20:00\n21:00\n22:00\n23:00\n24:00");
    textedit->setReadOnly(true);
    QPalette pal;
 //   pal.setColor(QPalette::Text,QColor(238,240,244));


    //打开时间轴数据储存的文件，读取上次使用的数据
    QFile timelineFile("./File/timeline.txt");
    timelineFile.open(QIODevice::ReadOnly|QIODevice::Text);


    for (int i = 0 ; i < 19;i++)
    {
        lineEdit.push_back(new QLineEdit(this));
       // qDebug()<< lineEdit.size();
        lineEdit[i]->setGeometry(1100,11+i*36,140,30);
        lineEdit[i]->setFont(font_one);
        pal = lineEdit[i]->palette();
        lineEdit[i]->setStyleSheet("background:transparent;border-width:0;border-style:outset");
        pal.setColor(QPalette::Text,QColor(238,240,244));
        lineEdit[i]->setPalette(pal);
        lineEdit[i]->setEnabled(true);
  //      qDebug()<<lineEdit[i]->isReadOnly();

        QByteArray array = timelineFile.readLine();
        array.chop(1);//把文末的换行符删了！！非常重要！！！！！
        lineEdit[i]->setText(array);

    }

    timelineFile.close();


    //打印四项象限文字
    QLabel *label_one = new QLabel(this);
    QLabel *label_two = new QLabel(this);
    QLabel *label_three = new QLabel(this);
    QLabel *label_four = new QLabel(this);

    label_one->setText("紧急且重要");
    QFont font_two("华文楷体",36,QFont::Bold);
    label_one->setGeometry(10,10,400,100);
    label_one->setFont(font_two);
    label_one->setStyleSheet("color:#759AD9");

    label_two->setText("紧急不重要");
    label_two->setGeometry(10,370,400,100);
    label_two->setFont(font_two);
    label_two->setStyleSheet("color:#759AD9");

    label_three->setText("重要不紧急");
    label_three->setGeometry(500,10,400,100);
    label_three->setFont(font_two);
    label_three->setStyleSheet("color:#759AD9");

    label_four->setText("不重要不紧急");
    label_four->setGeometry(500,370,400,100);
    label_four->setFont(font_two);
    label_four->setStyleSheet("color:#759AD9");

    //设置小组件to_do列表

     toDoList *toDolist_one = new toDoList(0,0,0,"./File/toDoPartOne.txt",this);
     toDolist_one->show();
     toDolist_one->setGeometry(0,0,490,360);
     toDoList *toDolist_two = new toDoList(0,0,1,"./File/toDoPartTwo.txt",this);
     toDolist_two->setGeometry(490,0,490,360);
     toDolist_two->show();
     toDoList *toDolist_three = new toDoList(0,0,2,"./File/toDoPartThree.txt",this);
     toDolist_three->setGeometry(0,360,490,360);
     toDolist_three->show();
     toDoList *toDolist_four = new toDoList(0,0,3,"./File/toDoPartFour.txt",this);
     toDolist_four->setGeometry(490,360,490,360);
     toDolist_four->show();

     toDolist_one->init_static();
 //    qDebug()<<toDoList::getFinishedName()[0];
}

void to_do_widget ::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    //设置要用到的颜色的笔刷
    QPen pen_one(QColor(156,193,231));
    QBrush brush_one(QColor(156,193,231));
    QPen pen_two(QColor(207,220,236));
    QBrush brush_two(QColor(207,220,236));
    QColor my_White(238,240,244);
    my_White.setAlpha(150);
    QPen pen_three(my_White);
    pen_three.setWidth(2);
    QBrush brush_three(my_White);

    painter.setPen(pen_one);
    painter.setBrush(brush_one);
    painter.drawRect(980,0,300,720);

    painter.setPen(pen_two);
    painter.setBrush(brush_two);
    painter.drawRect(0,0,980,720);

    painter.setPen(pen_three);
    painter.setBrush(brush_three);
    painter.drawLine(490,10,490,710);
    painter.drawLine(10,360,970,360);
    painter.drawLine(14,130,250,130);
    painter.drawLine(490+14,130,490+250,130);
    painter.drawLine(14,360+130,250,360+130);
    painter.drawLine(490+14,360+130,490+250,360+130);
    for(int i = 0 ;i < 19; i ++)
    {
        painter.drawLine(1090,44+i*36,1260,44+i*36);
    }

}

QWidget* to_do_widget:: returnthis(void)
{
    return this;
}

to_do_widget::~to_do_widget()
{
    toDoList::save_static();
    //关闭页面时将时间轴的数据写入文件
    QFile timelineFile("./File/timeline.txt");
    if (!timelineFile.open(QIODevice::WriteOnly|QIODevice::Truncate))
    {
        qDebug()<<"文件打开失败";
    }
 //   QTextStream stream(&timelineFile);
    for (int i = 0 ; i < 19 ; i++)
    {
    //    qDebug()<<lineEdit[i]->text();
 //       stream <<lineEdit[i]->text();
 //       stream<<"起床";
  //      stream <<"\n";
        char *ch = lineEdit[i]->text().toUtf8().data();
        timelineFile.write(ch);
        timelineFile.write("\r\n");

    }
    timelineFile.close();
    qDebug()<<"析构函数调用";


    delete ui;
}
