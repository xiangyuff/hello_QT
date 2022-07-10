#include "dataclasswidget.h"
#include "ui_dataclasswidget.h"

dataClassWidget::dataClassWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dataClassWidget)
{
    ui->setupUi(this);
    this->resize(1280,720);

    QFrame *frame = new QFrame(this);
    frame->setObjectName("myframe");
    frame->setGeometry(this->geometry());
    frame->resize(width(),height());
    frame->setStyleSheet("QFrame#myframe{border-image:url(:/image/sky_image_two.jpg)}" );


    DataClass*dataclass = new DataClass(this);
    dataclass->show();
    dataclass->setGeometry(190,60,900,600);


}


dataClassWidget::~dataClassWidget()
{
    delete ui;
}
