#include "mypushbutton.h"

MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{
    this->setStyleSheet("QPushButton{background-color:rgb(151, 158, 199);color: rgb(238, 240, 244);   border-radius: 20px;  border: 5px groove gray;border-style: outset;}"

                                               "QPushButton:hover{background-color:rgb(151, 158, 199); color: rgb(151, 158, 199);}"

                                              "QPushButton:pressed{background-color:rgb(156, 193, 231);border-style: inset; }"

                                               );
    QFont font;
    font.setPointSize(14);
    font.setBold(true);
    font.setFamily("KaiTi");
    this->setFont(font);
}

void MyPushButton::cancelRound()
{
    this->setStyleSheet("QPushButton{background-color:rgb(151, 158, 199);color: rgb(238, 240, 244);  border: 5px groove gray;border-style: outset;}"

                                               "QPushButton:hover{background-color:rgb(151, 158, 199); color: rgb(151, 158, 199);}"

                                              "QPushButton:pressed{background-color:rgb(156, 193, 231);border-style: inset; }"

                                               );

}
