
#include "gameover.h"
#include <QPainter>
#include <QPixmap>

GameOver::GameOver(QWidget *parent)
    : QMainWindow{parent}
{
    this->setFixedSize(1200,600);
    this->setWindowIcon(QPixmap(":/resources/image/entity/person/childright0.png"));
    this->setWindowTitle("DieWidget");
}

void GameOver::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    QPixmap pix;
    pix.load(":/resources/image/black.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    QPixmap GameOver;
    GameOver.load(":/resources/image/gameover.png");
    painter.drawPixmap(0,0,GameOver.width(),GameOver.height(),GameOver);
}
