
#include "diewidget.h"
#include <QPainter>

DieWidget::DieWidget(QWidget *parent)
    : QMainWindow{parent}
{
    this->setFixedSize(1200,600);
    this->setWindowIcon(QPixmap(":/resources/image/entity/person/childright0.png"));
    this->setWindowTitle("DieWidget");
}

void DieWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    QPixmap pix;

    pix.load(":/resources/image/black.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
