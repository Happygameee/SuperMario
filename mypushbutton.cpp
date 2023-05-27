
#include "mypushbutton.h"
#include <QPropertyAnimation>

MyPushButton::MyPushButton(QString BtnImg)
{
    BtnImgPath = BtnImg;
    QPixmap pix;
    pix.load(BtnImgPath);
    this->setFixedSize(pix.size());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));//让按钮大小跟图片保持一致
}

void MyPushButton::zoom1()
{
    //创建动态对象 并设置动画间隔
    QPropertyAnimation *Animation = new QPropertyAnimation(this,"geometry");
    Animation->setDuration(200);

    //设置动画的起始位置跟终止位置
    Animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    Animation->setEndValue(QRect(this->x(),this->y()+5,this->width(),this->height()));

    //设置动画效果
    Animation->setEasingCurve(QEasingCurve::OutBounce);

    Animation->start();
}

void MyPushButton::zoom2()
{
    //创建动态对象 并设置动画间隔
    QPropertyAnimation *Animation = new QPropertyAnimation(this,"geometry");
    Animation->setDuration(200);

    //设置动画的起始位置跟终止位置
    Animation->setStartValue(QRect(this->x(),this->y()+5,this->width(),this->height()));
    Animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));

    //设置动画效果
    Animation->setEasingCurve(QEasingCurve::OutBounce);

    Animation->start();
}

