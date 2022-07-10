#include "picwid.h"
#include<QPainter>
#include<QColor>
PicWid::PicWid(const QString picAddress,QWidget *parent) : QWidget(parent),picAd(picAddress)
{
    this->setFixedSize(900,600);
    this->move(200,10);
    this->setWindowTitle(tr("Congratulations!"));

}

PicWid::PicWid(QWidget *parent): QWidget(parent)
{

}

void PicWid::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    QPixmap pix;
    pix.load(picAd);
    painter.drawPixmap(0,0,pix);//画背景

    painter.setRenderHint(QPainter::Antialiasing); //设置抗锯齿
}
