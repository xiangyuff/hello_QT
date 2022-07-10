#include "encouragement.h"

Encouragement::Encouragement(QWidget * widget,QObject *parent)
    : QObject{parent}
{
    init_statement();
    m_widget = widget;
    set_encouragement();

}

void Encouragement :: init_statement(void)
{
    statements<<"读万卷书，行万里路。" ;
    statements<<"长风破浪会有时,直挂云帆济沧海。" ;
    statements<<"宁可枝头抱香死，何曾吹落北风中。" ;
    statements<<"臣心一片磁针石,不指南方不肯休。" ;
    statements<<"老骥伏枥，志在千里。烈士暮年，壮心不已。" ;
    statements<<"少壮不努力，老大徒伤悲。" ;
    statements<<"黑发不知勤学早，白首方悔读书迟。" ;
    statements<<"江山代有才人出，各领风骚数百年。" ;
    statements<<"千磨万击还坚劲，任尔东西南北风。" ;
    statements<<"劝君莫惜金缕衣，劝君惜取少年时。" ;
}

void Encouragement::set_encouragement()
{
    QTextEdit *textedit = new QTextEdit(m_widget) ;

    //生成随机数
    srand(time(NULL));
    int n = rand()%10 ;
    //设置文本框位置、背景透明，字体信息
    textedit->setGeometry(690,84,422,170);
    textedit->setStyleSheet("background:transparent;border-width:0;border-style:outset");
    QFont font_one("华文楷体",36,QFont::Bold);
    textedit->setFont(font_one);
 //   textedit->setTextColor(QColor(117,154,217));
    textedit->setTextColor(QColor(238,240,244));

    textedit->setText(statements[n]);
    textedit->setReadOnly(true);

}




