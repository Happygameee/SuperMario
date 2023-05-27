
#include "recorder.h"
#include <QLabel>
#include <QFont>

Recorder::Recorder(QWidget *parent)
    : QFrame{parent}
{
    QString str;
    //设置字体
    QFont font;
    font.setFamily("STCaiyun");
    font.setPointSize(20);

    //创建4个小Label 便于分开管理信息
    QLabel *Mario = new QLabel(this);
    Mario->setFixedSize(200,60);
    Mario->setParent(this);
    Mario->move(0,0);
    str = QString("MARIO\n%1").arg(MarioNumber);
    Mario->setText(str);
    Mario->setAlignment(Qt::AlignHCenter);
    Mario->setFont(font);
    Mario->setStyleSheet("color:white;");
    Mario->show();

    QLabel *Coins = new QLabel(this);
    Coins->setParent(this);
    Coins->setFixedSize(200,60);
    Coins->move(200,0);
    str = QString("COINS\n×%1").arg(CoinsNumber);
    Coins->setText(str);
    Coins->setAlignment(Qt::AlignHCenter);
    Coins->setFont(font);
    Coins->setStyleSheet("color:white;");
    Coins->show();

    QLabel *World = new QLabel(this);
    World->setParent(this);
    World->setFixedSize(200,60);
    World->move(400,0);
    str = QString("WORLD\n%1").arg(WorldLevel);
    World->setText(str);
    World->setAlignment(Qt::AlignHCenter);
    World->setFont(font);
    World->setStyleSheet("color:white;");
    World->show();

    QLabel *Pass = new QLabel(this);
    Pass->setParent(this);
    Pass->setFixedSize(200,60);
    Pass->move(600,0);
    str = QString("TIME\n%1").arg(PassTime);
    Pass->setText(str);
    Pass->setAlignment(Qt::AlignHCenter);
    Pass->setFont(font);
    Pass->setStyleSheet("color:white;");
    Pass->show();

}

void Recorder::ChangeMN()
{
    MarioNumber += 1;
}
void Recorder::ChangeCN()
{
    CoinsNumber += 1;
}
void Recorder::ChangeWl(QString level)
{
    WorldLevel = level;
}
void Recorder::ChangePT()
{
    PassTime += 1;
}

