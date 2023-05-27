
#ifndef RECORDER_H
#define RECORDER_H


#include <QFrame>
#include "mario.h"

class Recorder : public QFrame
{
    Q_OBJECT
public:
    Recorder(QWidget *parent);

    int MarioNumber = 0;//马里奥编号
    int CoinsNumber = 0;//拾取金币数量
    int PassTime = 0;//闯关时间
    QString WorldLevel = "0 - 0";//关卡编号

    //Mario *mario;

    //三个槽函数 用于改变记录器里面存储的记录
    void ChangeMN();
    void ChangeCN();
    void ChangePT();
    void ChangeWl(QString level);
signals:

};

#endif // RECORDER_H
