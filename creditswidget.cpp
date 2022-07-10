#include "creditswidget.h"

creditsWidget::creditsWidget(QWidget *parent)
    : QWidget{parent}
{
    this->resize(1280,720);

    QFrame *frame = new QFrame(this);
    frame->setObjectName("myframe");
    frame->setGeometry(this->geometry());
    frame->resize(width(),height());
    frame->setStyleSheet("QFrame#myframe{border-image:url(:/image/sky_image_two.jpg)}" );


    CreditsExchange *cE = new CreditsExchange(this);
    cE->show();
    cE->setGeometry(190,60,900,600);
}
