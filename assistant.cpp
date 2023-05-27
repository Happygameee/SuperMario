
#include "assistant.h"
#include <QKeyEvent>
#include <QPainter>

Assistant::Assistant(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(1200,600);
    this->setWindowIcon(QPixmap(":/resources/image/entity/mario/0/child0.png"));
    this->setWindowTitle("Assistant");
}

void Assistant::keyPressEvent(QKeyEvent *ev)
{
    if (ev->key() == Qt::Key_B)
    {
        emit back();
    }
}

void Assistant::paintEvent(QPaintEvent *)//重写绘图事件
{
    QPainter painter(this);

    QPixmap pix;

    pix.load(":/resources/image/assistant.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
