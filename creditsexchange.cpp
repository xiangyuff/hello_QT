#include "creditsexchange.h"
#include "mypushbutton.h"
#include<QString>
#include<QPainter>
#include<QColor>
#include <ctime>
#include<QDebug>

QFile CreditsExchange ::usedCredit_File(".usedCredit.txt");

CreditsExchange::CreditsExchange(QWidget *parent)
    : QWidget(parent)
{

 //   QTextCodec *codec = QTextCodec::codecForName("UTF-8-BOM");
  //  QTextCodec::setCodecForLocale(codec);

//        QSoundEffect * startSound;
//        startSound = new QSoundEffect(this);
//        startSound->setSource(QUrl::fromLocalFile(":/new/prefix1/music/1.wav"));
//        startSound->play();

        this->setFixedSize(900,600);
        this->move(200,10);

        this->setWindowTitle(tr("积分与兑换"));

        srand(time(NULL));
         initpic();

        //兑换解锁按钮
        MyPushButton* bn2=new MyPushButton(this);//按钮父窗口
        bn2->setText(tr("点击兑换"));//按钮文本
        bn2->move(570,350);//按钮位置
        bn2->setFixedSize(200,50);//按钮大小
        bn2->show();//按钮出现
        connect(bn2,&MyPushButton::clicked,this,&CreditsExchange::exchange_click);

        MyPushButton* bn3=new MyPushButton(this);//按钮父窗口
        bn3->setText(tr("停止音乐播放"));//按钮文本
        bn3->move(570,430);//按钮位置
        bn3->setFixedSize(200,50);//按钮大小
        bn3->show();//按钮出现
        connect(bn3,&MyPushButton::clicked,this,&CreditsExchange::CreditsExchange::stopmusic);

        startSound = new QSoundEffect(this);
}

CreditsExchange::~CreditsExchange()
{
}
void CreditsExchange::paintEvent(QPaintEvent *)
{
   Interface i;
   int totalCredit=toDoList::getScore_bianPart()+i.getScore_YUPart();


  // int totalCredit=300+400;
   //

   //读出 已兑换积分
   int usedCredit;
   usedCredit_File.open(QIODevice::ReadWrite);
   QByteArray array = usedCredit_File.readAll();
   if(array.size()==0) { //如果还没有usedCredit 文件 说明已兑换积分为0
       usedCredit=0;
   }
   else {
       char *p=array.data();
       usedCredit=atoi(p);
       qDebug()<< "读出已兑换积分  "<<usedCredit;
   }
   usedCredit_File.close();

   //计算出剩余积分
   int remain_credit=totalCredit-usedCredit;
   //now got totalCredit usedCredit remain_credit,so start painting!

   //开始作图
    QColor myPurple(151, 158, 199,200);
    QColor myBlue(207,220,236,200);

    QPainter painter(this);

    QPixmap pix;
  //  pix.load(":/image/sky_image_two.jpg");
  //  painter.drawPixmap(0,0,pix);//画背景

    painter.setRenderHint(QPainter::Antialiasing); //设置抗锯齿

    //画两个圆角矩形框
    QPen pen(myBlue);
    pen.setWidthF(10);
    painter.setPen(pen);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);

    brush.setColor(myPurple);
    painter.setBrush(brush);
    QRect rectbk_1(500,20,350,250);
    painter.drawRoundedRect(rectbk_1,30,30);

    pen.setColor(myPurple);
    painter.setPen(pen);
    brush.setColor(myBlue);
    painter.setBrush(brush);
    QRect rectbk_2(40,30,400,450);
    painter.drawRoundedRect(rectbk_2,20,20);

    //写矩形框里的文字
    QFont font;

    //font.setPointSize(22);
    font.setPointSize(15);
    font.setFamily("楷体");
    font.setBold(true);
    painter.setFont(font);

    pen.setColor(Qt::black);
    painter.setPen(pen);

    int cnt=100,dcnt=50;
    QString qstring;

    qstring="积分累计： "+QString::number(totalCredit)+" 分";
    painter.drawText(530,cnt,qstring);
    qstring="已兑换积分： "+QString::number(usedCredit)+" 分";
    painter.drawText(530,cnt+=dcnt,qstring);
    qstring="剩余积分： "+QString::number(remain_credit)+" 分";
    painter.drawText(530,cnt+=dcnt,qstring);
    if(remain_credit<100) {
        //font.setPointSize(15);
        font.setPointSize(10);
        painter.setFont(font);
        qstring="        (积分余额不足)";
        painter.drawText(530,cnt+=30,qstring);
    }


    //font.setPointSize(20);
    font.setPointSize(15);

    font.setFamily("楷体");
    font.setBold(true);
    painter.setFont(font);

    cnt=70;
    dcnt=35;
    qstring="        积分奖励";
    painter.drawText(60,cnt,qstring);

    //font.setPointSize(15);
    font.setPointSize(10);
    painter.setFont(font);

    qstring="积分规则： ";
    painter.drawText(60,cnt+=dcnt,qstring);

    qstring="任务完成积分：";
    painter.drawText(60,cnt+=dcnt,qstring);
    qstring="重要紧急50分/个";
    painter.drawText(60,cnt+=dcnt,qstring);
    qstring="重要不紧急30分/个";
    painter.drawText(60,cnt+=dcnt,qstring);
    qstring="不重要紧急20分/个";
    painter.drawText(60,cnt+=dcnt,qstring);
    qstring="不重要不紧急5分/个";
    painter.drawText(60,cnt+=dcnt,qstring);

    qstring="专注学习时间积分：";
    painter.drawText(60,cnt+=dcnt,qstring);
    qstring="每专注25分钟获得10分";
    painter.drawText(60,cnt+=dcnt,qstring);
    qstring="每合格打卡一次5分";
    painter.drawText(60,cnt+=dcnt,qstring);

   // font.setPointSize(20);
    font.setPointSize(15);

    painter.setFont(font);
    qstring="   积分兑换规则：";
    painter.drawText(60,cnt+=dcnt,qstring);

    //font.setPointSize(15);
    font.setPointSize(10);

    painter.setFont(font);
    qstring="每100分可兑换1份精美音乐图卡";
    painter.drawText(60,cnt+=dcnt,qstring);

}

void CreditsExchange::showPicMusic()
{
//随机在10组图卡中抽取一组
   //生成随机数
   int ran=rand()%10;
   qDebug()<< "随机数  "<<ran;
   //窗口展示
   playsound(ran);
   WidgetsPointer[ran]->show();

}

void CreditsExchange::initpic()
{

   WidgetsPointer[0]=new PicWid(":/image/000.png",0);
   WidgetsPointer[1]=new PicWid(":/image/001.png",0);
   WidgetsPointer[2]=new PicWid(":/image/002.png",0);
   WidgetsPointer[3]=new PicWid(":/image/003.png",0);
   WidgetsPointer[4]=new PicWid(":/image/004.png",0);
   WidgetsPointer[5]=new PicWid(":/image/005.png",0);
   WidgetsPointer[6]=new PicWid(":/image/006.png",0);
   WidgetsPointer[7]=new PicWid(":/image/007.png",0);
   WidgetsPointer[8]=new PicWid(":/image/008.png",0);
   WidgetsPointer[9]=new PicWid(":/image/009.png",0);


}

void CreditsExchange::playsound(int ran)
{
    if(ran%2==1) {
         startSound->setSource(QUrl::fromLocalFile(":/music/1.wav"));
    }
    else {
        startSound->setSource(QUrl::fromLocalFile(":/music/0.wav"));
    }
    QFile file("./File/Musicplay.txt");
    file.open(QIODevice::ReadOnly);
    QByteArray array = file.readAll();
    qDebug()<<array.size();
    qDebug() <<array.toInt();
    qDebug()<<ran%2+1;

    if (array.size()<2 &&array.toInt()!= (ran%2+1))
    {
        file.close();
        file.open(QIODevice::WriteOnly|QIODevice::Append);
        qDebug()<<"运行";
        qDebug()<<ran%2+1;
        int temp = ran%2 +1;

        QString s ;
        s = QString::number(temp);
        qDebug()<<s;
        char*ch = s.toUtf8().data();
        qDebug()<<ch;
        file.write(ch);
        file.close();

    }
   startSound->play();
}

void CreditsExchange::exchange_click()
{
   //获取来自YT YU的积分总量，记得取消注释符号
    Interface i ;
   int totalCredit=toDoList::getScore_bianPart()+i.getScore_YUPart();
   //模拟数据，记得删
   //int totalCredit=30000;
   //

   //读出 已兑换积分
   int usedCredit;
   usedCredit_File.open(QIODevice::ReadWrite);
   QByteArray array = usedCredit_File.readAll();
   if(array.size()==0) { //如果还没有usedCredit 文件 说明已兑换积分为0
       usedCredit=0;
   }
   else {
       char *p=array.data();
       usedCredit=atoi(p);
       qDebug()<< "读出已兑换积分  "<<usedCredit;
   }
   usedCredit_File.close();

   //计算出剩余积分   如果>100 则已兑换积分+=100 随机显示图卡和音乐
   int remain_credit=totalCredit-usedCredit;

   qDebug()<< "剩余积分 "<<remain_credit;

   if(remain_credit>=100) {
       usedCredit+=100;
       qDebug()<< "兑换成功 更新usedCredit数值 "<<usedCredit;
       qDebug()<< "随机显示图卡和音乐 "<<usedCredit;
       showPicMusic();
       update();
   }
  else {
       qDebug()<< "积分余额不足";
   }
   //将usedCredit写入文件
   char buff[20];
   _itoa_s(usedCredit,buff,10);

   usedCredit_File.open(QIODevice::WriteOnly);
   usedCredit_File.write(buff);
   usedCredit_File.close();
}

void CreditsExchange::stopmusic()
{
    startSound->stop();
}

