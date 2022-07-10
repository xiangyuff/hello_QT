#include "todolist.h"

QList <QString>toDoList::finishedName;
QList <QString>toDoList::unfinishedName;
QFile toDoList ::record_File("./File/staticRecord.txt");

int toDoList ::flag_one = 0 ;
int toDoList ::flag_two = 0 ;
int toDoList :: score = 0;

QVector<int>toDoList::num;


toDoList::toDoList(QWidget *parent)
    : QWidget{parent}
{

}

toDoList::toDoList(int x, int y , int type ,QString path ,QWidget *parent)
{
    start_x = x;
    start_y = y;
    filePath = path;
    m_parent = parent;
    filePath = path;
    scoreRule.push_back(50);
    scoreRule.push_back(30);
    scoreRule.push_back(20);
    scoreRule.push_back(5);

    //显示在父类widget上
    this->setParent(parent);
    setWindowFlags(this->windowFlags()|Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);
    setAttribute(Qt::WA_TranslucentBackground);//设置背景透明
  //  setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    hide();



 //   QList<QLineEdit*> lineedit_list;

    //实现添加功能
    QLineEdit*lineedit_one = new QLineEdit(this);
    QPalette pal_one;
    pal_one = lineedit_one->palette();
    pal_one.setColor(QPalette::Text,QColor(117,154,217));
    lineedit_one->setPalette(pal_one);
    lineedit_one->setGeometry(start_x+15,start_y+60,290,100);
    lineedit_one->setStyleSheet("background:transparent;border-width:0;border-style:outset");
    QFont font_one("华文楷体",24,QFont::Bold);
    lineedit_one->setFont(font_one);
    //lineedit_one->setText("哈哈");

    MyPushButton *btn_one = new MyPushButton(this);
    //btn_one->resize(100,100);
    btn_one->setGeometry(start_x+264,start_y+90,100,40);
    btn_one->setText("添加");
    // btn_one->setStyleSheet("color: rgb(238, 240, 244); ");
    //初始标记五个位置都可添加
    //打开文件
    QFile file_one(path);
    file_one.open(QIODevice::ReadOnly|QIODevice::Text);

    for (int i = 0 ; i < 5; i ++)
    {
        valid.push_back(true);

        lineedit_list.push_back(new QLineEdit(this));
        lineedit_list[i]->setGeometry(start_x+15,start_y+140+i*42,240,38);
        QPalette pal;
        pal = lineedit_list[i]->palette();
        pal.setColor(QPalette::Text,QColor(117,154,217));
        lineedit_list[i]->setPalette(pal_one);
        lineedit_list[i]->setStyleSheet("background:transparent;border-width:0;border-style:outset");
        QFont font("华文楷体",24,QFont::Bold);
        lineedit_list[i]->setFont(font);
        lineedit_list[i]->setReadOnly(true);
        //lineedit_list[i]->setEchoMode(QLineEdit::Password);
        //设置对应的完成按钮
        btn_vec_one.push_back(new MyPushButton(this));
        btn_vec_one[i]->setGeometry(start_x+264,start_y+140+i*42,100,40);
        btn_vec_one[i]->setText("完成");
        btn_vec_one[i]->hide();

        btn_vec_two.push_back(new MyPushButton(this));
        btn_vec_two[i]->setGeometry(start_x+384,start_y+140+i*42,100,40);
        btn_vec_two[i]->setText("删除");
        btn_vec_two[i]->hide();

        //读取文件内上次使用的数据
        QByteArray array = file_one.readLine();
        array.chop(1);
        if (array!="")
            {
             btn_vec_one[i]->show();
             btn_vec_two[i]->show();
             lineedit_list[i]->setText(array);
             valid[i] = false;
            }//把文末的换行符删了！！非常重要！！！！！


    }

    file_one.close();


     //int validpos = isvalid();
    //实现按添加按钮完成添加
     connect(btn_one,&MyPushButton::clicked,this,[=]()
     {
         int validpos = isvalid();
         QString temp = lineedit_one->text();
         if (validpos == -1 || temp == "")
         {
             return ;
         }
         qDebug()<< temp;
         lineedit_list[validpos]->setText(temp);
         btn_vec_one[validpos]->show();
         btn_vec_two[validpos]->show();
         valid[validpos] = false;

           unfinishedName[flag_one] = lineedit_one->text();
      //     qDebug()<<unfinishedName.size();
           flag_one++;
           flag_one%=3;
           lineedit_one->setText("");
      //     qDebug()<<unfinishedName[flag_one];
           num[0]++;

     });

     //用信号和槽实现两个按钮的功能
     for (int i = 0 ; i < 5; i ++)
     {

             connect(btn_vec_one[i],&MyPushButton::clicked,this,[=](){
             QPalette pal;
             pal = lineedit_list[i]->palette();
             pal.setColor(QPalette::Text,QColor(116,120,123));
             lineedit_list[i]->setPalette(pal);
//             lineedit_list[i]->setText("已完成");
             finishedName[flag_two] = lineedit_list[i]->text();
             flag_two++;
             flag_two%=3;
             score+= scoreRule[type];
             num[1]++;
             num[0]--;
         });
             connect(btn_vec_two[i],&MyPushButton::clicked,this,[=](){
             lineedit_list[i]->setText("");
             valid[i] =true;
             btn_vec_one[i]->hide();
             btn_vec_two[i]->hide();
             QPalette pal;
             pal = lineedit_list[i]->palette();
             pal.setColor(QPalette::Text,QColor(117,154,217));
             lineedit_list[i]->setPalette(pal);
         });
     }




}

void toDoList::init_static()
{
    num.resize(2);
    finishedName.resize(3);
    unfinishedName.resize(3);
    record_File.open(QIODevice::ReadOnly|QIODevice::Text);

    for (int i = 0 ; i < 9 ;i++)
    {

        if (i <3)
        {
            QByteArray temp = record_File.readLine();
            temp.chop(1);
            finishedName[i] = temp;
        }
        if (i >=3 && i <6)
        {
            QByteArray temp = record_File.readLine();
            temp.chop(1);
            unfinishedName[i%3] = temp;
        }
        if (i == 6 )
        {
            QByteArray temp = record_File.readLine();
            temp.chop(1);
            num[0] = temp.toInt();
        }
        if (i == 7 )
        {
            QByteArray temp = record_File.readLine();
            temp.chop(1);
            num[1] = temp.toInt();
        }
        if (i == 8 )
        {
            QByteArray temp = record_File.readLine();
            temp.chop(1);
            score= temp.toInt();
        }
    //    finishedName.push_back(record_File.readLine());
    }
    record_File.close();
}

void toDoList::save_static()
{

    for (int i = 0 ; i < 9 ;i++)
    {
        record_File.open(QIODevice::WriteOnly|QIODevice::Truncate);

        if (i <3)
        {
            char*ch = finishedName[i].toUtf8().data();
            record_File.write(ch);
            record_File.write("\r\n");
       //     qDebug()<< i <<" " <<finishedName[i] <<" " <<ch;
        }
        if (i >=3&&i <6)
        {
            char*ch = unfinishedName[i%3].toUtf8().data();
            record_File.write(ch);
            record_File.write("\r\n");
     //       qDebug()<<ch;
       //     qDebug()<< i <<" " <<unfinishedName[i%3] << " " << ch;

        }
        if (i ==6)
        {
            char*ch = QString::number(num[0]).toUtf8().data();
            record_File.write(ch);
            record_File.write("\r\n");
        }
        if (i ==7)
        {
            char*ch = QString::number(num[1]).toUtf8().data();
            record_File.write(ch);
            record_File.write("\r\n");
        }
        if (i ==8)
        {
            char*ch = QString::number(score).toUtf8().data();
            record_File.write(ch);
            record_File.write("\r\n");
        }
    //    finishedName.push_back(record_File.readLine());
    }
}

QList<QString> toDoList::getFinishedName(void)
{
    return finishedName;
}

QList<QString> toDoList::getUnfinishedName(void)
{
    return unfinishedName;
}

QVector<int> toDoList::getNum(void)
{
    return num;
}

int toDoList::getScore_bianPart(void)
{
    return score;
}

int toDoList::isvalid()
{
    for (int i = 0 ; i < 5; i ++)
    {
        if (valid[i] == true)
        {
            return i;
        }
    }

    return -1;
}

toDoList::~toDoList()
{
    QFile file(filePath);
    file.open(QIODevice::WriteOnly|QIODevice::Truncate);
    for(int i = 0 ; i <5; i++)
    {
        char*ch = lineedit_list[i]->text().toUtf8().data();
        file.write(ch);
        file.write("\r\n");

    }
    file.close();
}
