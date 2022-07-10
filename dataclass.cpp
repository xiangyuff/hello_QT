#include "dataclass.h"
#include "ui_dataclass.h"


DataClass::DataClass(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DataClass)
{
    ui->setupUi(this);
    this->setFixedSize(900,600);
    this->setWindowTitle(tr("统计与分析"));

    chart = new QChart();
    chart2 = new QChart();
    chartView = new QChartView(chart);
    chartView2 = new QChartView(chart2);

//    set0 = new QBarSet("Week");
//    serie = new QBarSeries();
    axisY = new QValueAxis();
    axisY->setRange(0,600);

    //获取数据
    //数据from YiTong
 //     QList<QString> FinishedName(toDoList::getFinishedName());  //最新的三个完成的变量名
//      QList<QString> UnfinishedName(toDoList::getUnfinishedName());  //最新的三个未完成的变量名
      QVector<int> YTNum(toDoList::getNum());     //一共两个数,第一个是未完成总数，第二个是已完成总数。
      int Score_bianPart=toDoList::getScore_bianPart();//返回积分

    //数据from Yu
//    QVector<int> FocusNum(xxxclassname::getFocusNum);//一共2个数,第一个是用户开始使用以来的总专注次数，第二个总的专注时间  单位min
     QVector<int> WeekNum(Interface::WeekNum());//一共7个数 表示本周周一到周日的专注时间（如果本周还是周五的话，周六周日就设为-1吧）
//    int Score_YUPart=xxxclassname::getScore_YUPart();//返回积分

    //以上注释符号一童记得取消

    //模拟数据
    QList<QString> FinishedName;
    FinishedName.resize(3);

    FinishedName[0]=tr("高数刷题");
    FinishedName[1]=tr("电路刷题");
    FinishedName[2]=tr("C++刷题");

    QList<QString> UnfinishedName;
    UnfinishedName.resize(3);

    UnfinishedName[0]=tr("QT学习");
    UnfinishedName[1]=tr("英语作文");
    UnfinishedName[2]=tr("学习Latex");

  /*  QVector<int> YTNum;
    YTNum.resize(2);
    YTNum[0]=4;
    YTNum[1]=8;*/

    QVector<int> FocusNum;//一共2个数,第一个是用户开始使用以来的总专注次数，第二个总的专注时间  单位min
    FocusNum.resize(2);
    FocusNum[0]=12;
    FocusNum[1]=100;

//    QVector<int> WeekNum;//一共7个数 表示本周周一到周日的专注时间（如果本周还是周五的话，周六周日就设为-1吧）
//    WeekNum.resize(7);
//    WeekNum[0]=25;
//    WeekNum[1]=425;
//    WeekNum[2]=350;
//    WeekNum[3]=425;
//    WeekNum[4]=180;
//    WeekNum[5]=233;
//    WeekNum[6]=332;
    //以上模拟数据一童记得删掉

    //开始作图
     QColor myGreen(131,175,155);
     QColor myYellow(255,252,153);
     QColor myPurple(151, 158, 199,200);
     QColor myBlue(207,220,236,200);
     QColor myTrans(207,220,236,250);

     QPainter painter(this);

 /*    QPixmap pix;
     pix.load(":/new/prefix1/img/bigbk.jpg");
     painter.drawPixmap(0,0,pix);//画背景*/

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
     QRect rectbk_2(40,330,280,250);
     painter.drawRoundedRect(rectbk_2,20,20);

     //写矩形框里的文字
     QFont font;

     font.setPointSize(15);
     font.setFamily("楷体");
     font.setBold(true);
     painter.setFont(font);

     pen.setColor(Qt::black);
     painter.setPen(pen);

     int cnt=60,dcnt=24;
     QString qstring;

     qstring="已完成任务 "+QString::number(YTNum[1])+" 个：";
     painter.drawText(530,cnt,qstring);

     font.setPointSize(12);
     font.setBold(false);
     painter.setFont(font);

     qstring="                  "+FinishedName[0];
     painter.drawText(530,cnt+=dcnt,qstring);
     qstring="                  "+FinishedName[1];
     painter.drawText(530,cnt+=dcnt,qstring);
     qstring="                  "+FinishedName[2];
     painter.drawText(530,cnt+=dcnt,qstring);

     font.setPointSize(15);
     font.setFamily("楷体");
     font.setBold(true);
     painter.setFont(font);

     qstring="未完成任务 "+QString::number(YTNum[0])+" 个：";
     painter.drawText(530,cnt+=dcnt*2,qstring);

     font.setPointSize(12);
     font.setBold(false);
     painter.setFont(font);

     qstring="                  "+UnfinishedName[0];
     painter.drawText(530,cnt+=dcnt,qstring);
     qstring="                  "+UnfinishedName[1];
     painter.drawText(530,cnt+=dcnt,qstring);
     qstring="                  "+UnfinishedName[2];
     painter.drawText(530,cnt+=dcnt,qstring);

     font.setPointSize(15);
     font.setFamily("楷体");
     font.setBold(true);
     painter.setFont(font);

     cnt=350;
     dcnt=35;
     qstring="已专注时间总计 "+QString::number(FocusNum[1])+" min";
     painter.drawText(60,cnt+=dcnt,qstring);
     qstring="已专注次数总计 "+QString::number(FocusNum[0])+" min";
     painter.drawText(60,cnt+=dcnt,qstring);
     qstring="平均每次 "+QString::number(FocusNum[1]/FocusNum[0])+" min";
     painter.drawText(60,cnt+=dcnt,qstring);
     qstring="本周专注数据：";
     painter.drawText(60,cnt+=dcnt,qstring);

     int sum=0,count=7;
     double fc=0;
     for(int i=0;i<7;i++) {
         if(WeekNum[i]==-1) {
             count=i;
             break;
         }
         sum+=WeekNum[i];
     }
     double ave=double(sum)/count;
     for(int i=0;i<count;i++) {
         fc+=(WeekNum[i]-ave)*(WeekNum[i]-ave);
     }
     fc=sqrt(fc);

     qstring="        均值："+QString::number(ave);
     painter.drawText(60,cnt+=dcnt,qstring);
     qstring="        方差："+QString::number(fc);
     painter.drawText(60,cnt+=dcnt,qstring);

     //画饼图
     QPieSeries *series = new QPieSeries();
     series->append("总计已完成任务", YTNum[1]);
     series->append("总计未完成任务", YTNum[0]);

     QPieSlice *slice = series->slices().at(0);
     slice->setExploded();
     slice->setLabelVisible();
     slice->setPen(QPen(Qt::darkGreen,2));
     slice->setBrush(myGreen);

     QPieSlice *slice2 = series->slices().at(1);
     slice2->setExploded();
     slice2->setLabelVisible();
     slice2->setPen(QPen(Qt::darkYellow, 2));
     slice2->setBrush(myYellow);

     chart->removeAllSeries();
     chart->addSeries(series);
     chart->setTitle("任务完成情况饼状图");

     brush.setColor(myBlue);
     chart->setBackgroundBrush(brush);
     pen.setColor(myPurple);
     chart->setBackgroundPen(pen);

 //    QChartView *chartView = new QChartView(chart);
     chartView->setChart(chart);

     brush.setColor(myTrans);
     chartView->setBackgroundBrush(brush);
     chartView->setRenderHint(QPainter::Antialiasing);

     ui->verticalLayout->removeWidget(chartView);
     ui->verticalLayout->addWidget(chartView);

     //画柱状图
     QBarSet *set0 = new QBarSet("Week");

     //set0->remove(0,7);
     for(int i=0;i<7;i++){
         if(WeekNum[i]==-1){
             *set0 << 0;
         }
         else {
             *set0 << WeekNum[i];
             qDebug()<<i<<"  "<<WeekNum[i];
         }
     }

     QBarSeries *serie = new QBarSeries();
   //  serie->remove(set0);
     serie->append(set0);

     chart2->removeAllSeries();
     chart2->addSeries(serie);

     chart2->setTitle("本周专注时间统计");
     chart2->setAnimationOptions(QChart::SeriesAnimations);

     static int cntPaint=0;
     cntPaint++;
    if(cntPaint==1) {

        QStringList categories;
        categories << "周一" << "周二" << "周三" << "周四" << "周五" << "周六" << "周日";
        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        chart2->addAxis(axisX, Qt::AlignBottom);
        serie->attachAxis(axisX);

        chart2->legend()->setVisible(true);
        chart2->legend()->setAlignment(Qt::AlignBottom);
    }

    chart2->removeAxis(axisY);
    chart2->addAxis(axisY, Qt::AlignLeft);
    serie->attachAxis(axisY);

  //   QChartView *chartView2 = new QChartView(chart2);
     chartView2->setChart(chart2);

     brush.setColor(myPurple);
     chart2->setBackgroundBrush(brush);
     pen.setColor(myBlue);
     chart2->setBackgroundPen(pen);

     brush.setColor(myTrans);
     chartView2->setBackgroundBrush(brush);
     chartView2->setRenderHint(QPainter::Antialiasing);
     ui->verticalLayout_2->removeWidget(chartView2);
     ui->verticalLayout_2->addWidget(chartView2);


}

DataClass::~DataClass()
{
    delete ui;
}

void DataClass::paintEvent(QPaintEvent *)
{
    qDebug()<<"painting once!";


    //获取数据
    //数据from YiTong
    QList<QString> FinishedName(toDoList::getFinishedName());  //最新的三个完成的变量名
    QList<QString> UnfinishedName(toDoList::getUnfinishedName());  //最新的三个未完成的变量名
    QVector<int> YTNum(toDoList::getNum());     //一共两个数,第一个是未完成总数，第二个是已完成总数。
    int Score_bianPart=toDoList::getScore_bianPart();//返回积分

    //数据from Yu


    QVector<int> FocusNum(Interface::FocusNum());//一共2个数,第一个是用户开始使用以来的总专注次数，第二个总的专注时间  单位min
    QVector<int> WeekNum(Interface::WeekNum());//一共7个数 表示本周周一到周日的专注时间（如果本周还是周五的话，周六周日就设为-1吧）
 //   int Score_YUPart=i.getScore_YUPart();//返回积分



    //以上注释符号一童记得取消

    //模拟数据
  /*  QList<QString> FinishedName;
    FinishedName.resize(3);

    FinishedName[0]=tr("高数刷题");
    FinishedName[1]=tr("电路刷题");
    FinishedName[2]=tr("C++刷题");

    QList<QString> UnfinishedName;
    UnfinishedName.resize(3);

    UnfinishedName[0]=tr("QT学习");
    UnfinishedName[1]=tr("英语作文");
    UnfinishedName[2]=tr("学习Latex");

    QVector<int> YTNum;
    YTNum.resize(2);
    YTNum[0]=4;
    YTNum[1]=8;*/

//    QVector<int> FocusNum;//一共2个数,第一个是用户开始使用以来的总专注次数，第二个总的专注时间  单位min
//    FocusNum.resize(2);
//    FocusNum[0]=12;
//    FocusNum[1]=100;

//   QVector<int> WeekNum;//一共7个数 表示本周周一到周日的专注时间（如果本周还是周五的话，周六周日就设为-1吧）
//    WeekNum.resize(7);
//    WeekNum[0]=25;
//    WeekNum[1]=425;
//    WeekNum[2]=350;
//    WeekNum[3]=425;
//    WeekNum[4]=180;
//    WeekNum[5]=233;
//    WeekNum[6]=332;
    //以上模拟数据一童记得删掉

    //开始作图
     QColor myGreen(131,175,155);
     QColor myYellow(255,252,153);
     QColor myPurple(151, 158, 199,200);
     QColor myBlue(207,220,236,200);
     QColor myTrans(207,220,236,250);

     QPainter painter(this);

 /*    QPixmap pix;
     pix.load(":/new/prefix1/img/bigbk.jpg");
     painter.drawPixmap(0,0,pix);//画背景*/

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
     QRect rectbk_2(40,330,280,250);
     painter.drawRoundedRect(rectbk_2,20,20);

     //写矩形框里的文字
     QFont font;

     font.setPointSize(15);
     font.setFamily("楷体");
     font.setBold(true);
     painter.setFont(font);

     pen.setColor(Qt::black);
     painter.setPen(pen);

     int cnt=60,dcnt=24;
     QString qstring;

     qstring="已完成任务 "+QString::number(YTNum[1])+" 个：";
     painter.drawText(530,cnt,qstring);

     font.setPointSize(12);
     font.setBold(false);
     painter.setFont(font);

     qstring="                  "+FinishedName[0];
     painter.drawText(530,cnt+=dcnt,qstring);
     qstring="                  "+FinishedName[1];
     painter.drawText(530,cnt+=dcnt,qstring);
     qstring="                  "+FinishedName[2];
     painter.drawText(530,cnt+=dcnt,qstring);

     font.setPointSize(15);
     font.setFamily("楷体");
     font.setBold(true);
     painter.setFont(font);

     qstring="未完成任务 "+QString::number(YTNum[0])+" 个：";
     painter.drawText(530,cnt+=dcnt*2,qstring);

     font.setPointSize(12);
     font.setBold(false);
     painter.setFont(font);

     qstring="                  "+UnfinishedName[0];
     painter.drawText(530,cnt+=dcnt,qstring);
     qstring="                  "+UnfinishedName[1];
     painter.drawText(530,cnt+=dcnt,qstring);
     qstring="                  "+UnfinishedName[2];
     painter.drawText(530,cnt+=dcnt,qstring);

     font.setPointSize(15);
     font.setFamily("楷体");
     font.setBold(true);
     painter.setFont(font);

     cnt=350;
     dcnt=35;
     qstring="已专注时间总计 "+QString::number(FocusNum[1])+" min";
     painter.drawText(60,cnt+=dcnt,qstring);
     qstring="已专注次数总计 "+QString::number(FocusNum[0])+" min";
     painter.drawText(60,cnt+=dcnt,qstring);
     qstring="平均每次 "+QString::number(FocusNum[1]/FocusNum[0])+" min";
     painter.drawText(60,cnt+=dcnt,qstring);
     qstring="本周专注数据：";
     painter.drawText(60,cnt+=dcnt,qstring);

     int sum=0,count=7;
     double fc=0;
     for(int i=0;i<7;i++) {
         if(WeekNum[i]==-1) {
             count=i;
             break;
         }
         sum+=WeekNum[i];
     }
     double ave=double(sum)/count;
     for(int i=0;i<count;i++) {
         fc+=(WeekNum[i]-ave)*(WeekNum[i]-ave);
     }
     fc=sqrt(fc);

     qstring="        均值："+QString::number(ave);
     painter.drawText(60,cnt+=dcnt,qstring);
     qstring="        方差："+QString::number(fc);
     painter.drawText(60,cnt+=dcnt,qstring);



}

