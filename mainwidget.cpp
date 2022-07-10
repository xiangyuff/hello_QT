#include "mainwidget.h"
#include "ui_mainwidget.h"


mainWidget::mainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainWidget)
{
    ui->setupUi(this);
    this->setFixedSize(1380,720);
    this->setWindowTitle("万水千山");
    this->setStyleSheet("background-color:rgb(207,220,236);");
    this->setWindowIcon(QIcon(":/image/icon.ico"));

    MyPushButton *btn_one = new MyPushButton (this);
    MyPushButton *btn_two = new MyPushButton(this);
    MyPushButton *btn_three = new MyPushButton(this);
    MyPushButton *btn_four = new MyPushButton(this);
    MyPushButton *btn_five = new MyPushButton(this);
    MyPushButton *btn_six = new MyPushButton(this);
    MyPushButton *btn_seven = new MyPushButton(this);
    btn_one->setGeometry(0,0,100,80);
    btn_one->setText("欢迎");
    btn_one->cancelRound();
    btn_two->setGeometry(0,80,100,80);
    btn_two->setText("toDo 列表");
    btn_two->cancelRound();
    btn_three->setGeometry(0,160,100,80);
    btn_three->setText("番茄钟");
    btn_three->cancelRound();
    btn_four->setGeometry(0,320,100,80);
    btn_four->setText("统计");
    btn_four->cancelRound();
    btn_five->setGeometry(0,400,100,80);
    btn_five->setText("奖励");
    btn_five->cancelRound();
    btn_six->setGeometry(0,480,100,240);
    btn_six->setText("");
    btn_six->cancelRound();
    btn_seven->setGeometry(0,240,100,80);
    btn_seven->setText("打卡");
    btn_seven->cancelRound();

  //  ui->stackedWidget->setGeometry(100,0,1280,720);

    ui->stackedWidget->setCurrentIndex(0);

    TomatoClock *tomatoclock =new TomatoClock(this,this->width(),this->height());//番茄钟类
    DayClockin* dayclockin =new DayClockin(this,this->width(),this->height());

    ui->stackedWidget->insertWidget(4,tomatoclock);
    ui->stackedWidget->insertWidget(5,dayclockin);


    connect (btn_one,&MyPushButton::clicked,this,[=](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect (btn_two,&MyPushButton::clicked,this,[=](){
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect (btn_four,&MyPushButton::clicked,this,[=](){

        ui->stackedWidget->setCurrentIndex(2);
    });
    connect (btn_five,&MyPushButton::clicked,this,[=](){

        ui->stackedWidget->setCurrentIndex(3);
    });
    connect (btn_three,&MyPushButton::clicked,this,[=](){

        ui->stackedWidget->setCurrentIndex(4);
    });
    connect (btn_seven,&MyPushButton::clicked,this,[=](){

        ui->stackedWidget->setCurrentIndex(5);
    });
    //ui->stackedWidget->currentWidget()->setGeometry(80,0,1280,720);
    connect (btn_six,&MyPushButton::clicked,this,[=](){
     //   dcw->update();
        if (eggFlag == 0)
        {
            eggFlag =1;
            btn_six->setText("制作人员\n 于洋淼\n 缪潍姿\n 卞一童");
        }
        else
        {
            eggFlag = 0;
            btn_six->setText("");
        }

    });
}


mainWidget::~mainWidget()
{
    qDebug()<<"主界面析构函数调用";


    delete ui;

}
