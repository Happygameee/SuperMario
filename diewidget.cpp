
#include "diewidget.h"
#include <QPainter>
#include <QLabel>
#include <QDebug>

DieWidget::DieWidget(QWidget *parent)
    : QMainWindow{parent}
{
    this->setFixedSize(1200,600);
    this->setWindowIcon(QPixmap(":/resources/image/entity/person/childright0.png"));
    this->setWindowTitle("DieWidget");

    QString str;
    //设置字体
    QFont font;
    font.setFamily("STCaiyun");
    font.setPointSize(100);

    QLabel *Mario = new QLabel(this);
    Mario->setFixedSize(200,120);
    Mario->setParent(this);
    Mario->move(500,240);
    str = QString("×");
    Mario->setText(str);
    Mario->setAlignment(Qt::AlignHCenter);
    Mario->setFont(font);
    Mario->setStyleSheet("color:white;");
    Mario->show();
}

void DieWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    QPixmap pix;
    pix.load(":/resources/image/black.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    QPixmap life;
    life.load(":/resources/image/life.png");
    painter.drawPixmap(300,240,120,120,life);
}

void DieWidget::Refresh()
{
    QString str;
    //设置字体
    QFont font;
    font.setFamily("STCaiyun");
    font.setPointSize(100);

    QLabel *Life = new QLabel(this);
    Life->setFixedSize(200,120);
    Life->setParent(this);
    Life->move(600,240);
    str = QString::number(MarioLife);
    Life->setText(str);
    Life->setAlignment(Qt::AlignHCenter);
    Life->setFont(font);
    Life->setStyleSheet("color:white;");
    Life->show();
}
