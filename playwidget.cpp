
#include "playwidget.h"
#include <QPainter>
#include <QTimer>
#include <QDebug>
#include <QKeyEvent>
#include <QPropertyAnimation>

PlayWidget::PlayWidget(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(1200,600);
    this->setWindowIcon(QPixmap(":/resources/image/entity/person/childright0.png"));
    this->setWindowTitle("PlayWidget");
    gameInit();

    QTimer::singleShot(1000, this, [=]() {
        timer1 = startTimer(15);
    });
    this->setFocusPolicy(Qt::StrongFocus);
}

void PlayWidget::gameInit()
{
    mario = new Mario;
    pipe = new Pipe;
    hole = new Hole;
    brick = new Brick;
    unknown = new Unknown;
    musicplayer = new MusicPlayer;
    monster = new Monster;
    flag = new Flag;
    score = 0;
    xnow = 0;
}

void PlayWidget::timerEvent(QTimerEvent *ev)
{
    if (ev->timerId()==timer1)
    {
        mario->walk();
        mario->jump_down();
        mario->Mario_Die();
        mario->Mario_Climb();
        Fall_Down(mario->y);
        Move_Collision();
        Jump_Collision();
        unknown->CoinAppear();
        monster->MonsterMove();
        DieState();
        Game_Win();
        update();

        if (mario->isWin == true)
        {
            flag->FlagLower();
        }
    }
}

void PlayWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    if (mario->x==600 && mario->direction == "right" && mario->ismoving ==true && mario->canmove == true)
    {
        xnow = 600 - mario->Map_x - 10;
    }

    //绘画背景
    QPixmap back;
    back.load(":/resources/image/level/1-1.png");
    painter.drawPixmap(xnow,0,8800,600,back);

    //绘画questionblock和金币
    QPixmap qblock;
    qblock.load(":/resources/image/wall/block/ground/questionblock0.png");

    //画金币coin
    QPixmap coin;
    coin.load(":/resources/image/coin/flycoin"+ QString::number(unknown->upstate) +".png");
    for (QVector < QVector < int >> ::iterator it = unknown->m.begin()->begin(); it !=unknown->m.begin()->end();it++)
    {
        painter.drawPixmap(*it->begin() + xnow,*(it->begin() + 1),40,40,qblock);

        if (*(it->begin()+2) == 0)
        {
            painter.drawPixmap(*it->begin() + xnow,unknown->coin_y + unknown->coinheight - 40,40,40,coin);
            qDebug() << "1";
        }
    }

    //绘画Monster
    QPixmap mon3ter;
    for (QVector < QVector < int >> ::iterator it = monster->m.begin()->begin(); it !=monster->m.begin()->end();it++)
    {
        mon3ter.load(":/resources/image/entity/monster/ground/Monster" + QString::number(*(it->begin() + 5)) +".png");
        //mon3ter.load(":/resources/image/entity/monster/ground/Monster1.png");
        painter.drawPixmap(*(it->begin() + 2) + xnow,*(it->begin() + 3),40,40,mon3ter);
        //qDebug() << *(it->begin() + 2) + xnow << *(it->begin() + 3);
    }

    //画旗子
    QPixmap FlaG;
    FlaG.load(":/resources/image/flag/flag.png");
    painter.drawPixmap(flag->Flag_x + xnow,flag->Flag_y,FlaG.width(),FlaG.height(),FlaG);

    //绘画马里奥
    QPixmap person;
    if (!mario->isdie)
    {
        if (mario->isClimb)
        {
            person.load(":/resources/image/entity/person/childclimb" +
                        QString::number(mario->climbstate) + ".png");
        }
        else
        {
            if (!mario->isjump)
            {
                person.load(":/resources/image/entity/person/child" + mario->direction +
                            QString::number(mario->walkstate) + ".png");
            }
            else
            {
                person.load(":/resources/image/entity/person/childjump" + mario->direction +".png");
            }
        }
    }
    else
    {
        person.load(":/resources/image/entity/person/childDie.png");
    }
    painter.drawPixmap(mario->x,mario->y + mario->height - mario->distance,40,40,person);
}

void PlayWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Right:
        mario->direction = "right";
        mario->ismoving = true;
        break;
    case Qt::Key_Left:
        mario->direction = "left";
        mario->ismoving = true;
        break;
    case Qt::Key_Space:
        if (mario->upstate == 0)
        {
            mario->isjump = true;
            mario->upstate = 1;
        }
        break;
    case Qt::Key_B:
        emit PressB();
        break;
    default:
        break;
    }
}

void PlayWidget::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Right:
        mario->ismoving = false;
        break;
    case Qt::Key_Left:
        mario->ismoving = false;
        break;
    default:
        break;
    }
}

void PlayWidget::Jump_Collision()
{
    for (QVector < QVector < int >> ::iterator it = unknown->m.begin()->begin(); it != unknown->m.begin()->end();it++)
    {
        if (mario->Map_x - (*it->begin()) <= 30 && mario->Map_x - (*it->begin()) >= -30 &&
            *(it->begin() + 1) == mario->y + mario->height -mario->distance - 40
            && mario->upstate == 1
            )
        {
            mario->isjump = true;
            mario->upstate = 2;
            ScoreAdd();

            //分类unknown效果
            if (*(it->begin() + 2) == 1)
            {
                unknown->Unknown_crash(it);
            }
        }
    }
}

void PlayWidget::Move_Collision()
{
    //和管道的碰撞
    for (QVector < QVector < int >> ::iterator it = pipe->m_short.begin()->begin(); it != pipe->m_short.begin()->end();
         it++)
    {
        if (mario->Map_x - (*it->begin())==-30
            && mario->direction == "right"
            &&mario->height>=-80) {
            mario->canmove = false;
        } else if(mario->Map_x - (*it->begin())==-30
            && mario->direction == "left"
            &&mario->height==0)
        {
            mario->canmove = true;
        }
        else if(mario->Map_x - (*it->begin())==-30
                 && mario->direction == "right"
                 &&mario->height<-80)
        {
            mario->canmove = true;
        }
        if (mario->Map_x - (*it->begin())==80
            && mario->direction == "left"
            &&mario->height>=-80) {
            mario->canmove = false;
        } else if(mario->Map_x - (*it->begin())==80
                   && mario->direction == "right"
                   &&mario->height==0)
        {
            mario->canmove = true;
        }
        else if(mario->Map_x - (*it->begin())==80
                 && mario->direction == "left"
                 &&mario->height<-80)
        {
            mario->canmove = true;
        }
    }
    for (QVector < QVector < int >> ::iterator it = pipe->m_mid.begin()->begin(); it != pipe->m_mid.begin()->end();
         it++)
    {
        if (mario->Map_x - (*it->begin())==-40
            && mario->direction == "right"
            &&mario->height>=-120) {
            mario->canmove = false;
        } else if(mario->Map_x - (*it->begin())==-40
                   && mario->direction == "left"
                   &&mario->height==0)
        {
            mario->canmove = true;
        }
        else if(mario->Map_x - (*it->begin())==-40
                 && mario->direction == "right"
                 &&mario->height<-120)
        {
            mario->canmove = true;
        }
        if (mario->Map_x - (*it->begin())==80
            && mario->direction == "left"
            &&mario->height>=-120) {
            mario->canmove = false;
        } else if(mario->Map_x - (*it->begin())==80
                   && mario->direction == "right"
                   &&mario->height==0)
        {
            mario->canmove = true;
        }
        else if(mario->Map_x - (*it->begin())==80
                 && mario->direction == "left"
                 &&mario->height<-120)
        {
            mario->canmove = true;
        }
    }
    for (QVector < QVector < int >> ::iterator it = pipe->m_long.begin()->begin(); it != pipe->m_long.begin()->end();
         it++)
    {
        if (mario->Map_x - (*it->begin())==-40
            && mario->direction == "right"
            &&mario->height>=-160) {
            mario->canmove = false;
        } else if(mario->Map_x - (*it->begin())==-40
                   && mario->direction == "left"
                   &&mario->height==0)
        {
            mario->canmove = true;
        }
        else if(mario->Map_x - (*it->begin())==-40
                 && mario->direction == "right"
                 &&mario->height<-160)
        {
            mario->canmove = true;
        }
        if (mario->Map_x - (*it->begin())==80
            && mario->direction == "left"
            &&mario->height>=-160) {
            mario->canmove = false;
        } else if(mario->Map_x - (*it->begin())==80
                   && mario->direction == "right"
                   &&mario->height==0)
        {
            mario->canmove = true;
        }
        else if(mario->Map_x - (*it->begin())==80
                 && mario->direction == "left"
                 &&mario->height<-160)
        {
            mario->canmove = true;
        }
    }

    //掉入洞后的情况 马里奥不能再动了
    for (QVector < QVector < int >> ::iterator it = hole->m.begin()->begin(); it !=hole->m.begin()->end();it++)
    {
        if(mario->Map_x >(*it->begin())-10 && mario->Map_x < *(it->begin() + 1) - 10
            &&mario->y == 645
            )
        {
            mario->canmove = false;
        }
    }

    //砖台阶
    for (QVector < QVector < int >> ::iterator it = brick->m.begin()->begin(); it !=brick->m.begin()->end();it++)
    {
        if(mario->Map_x == (*it->begin())-30//左
            &&mario->distance - mario->height < (*(it->begin() + 2)) * 40
            &&mario->direction == "right"
            )
        {
            mario->canmove = false;
        }
        else if(mario->Map_x == (*(it->begin() + 1))//右
                &&mario->distance - mario->height < (*(it->begin() + 2)) * 40
                &&mario->direction == "left"
                )
        {
            mario->canmove = false;
        }
        else if(mario->Map_x == (*it->begin()) - 30//左
                 &&mario->distance - mario->height < (*(it->begin() + 2)) * 40
                 &&mario->direction == "left"
                 )
        {
            mario->canmove = true;
        }
        else if(mario->Map_x == (*(it->begin() + 1))//右
                 &&mario->distance - mario->height < (*(it->begin() + 2)) * 40
                 &&mario->direction == "right"
                 )
        {
            mario->canmove = true;
        }
        else if((mario->Map_x == (*it->begin()) - 30||mario->Map_x == (*(it->begin() + 1)))
                 &&mario->distance - mario->height > (*(it->begin() + 2)) * 40
                 )
        {
            mario->canmove = true;
        }
    }

    //unKnown
    for (QVector < QVector < int >> ::iterator it = unknown->m.begin()->begin(); it != unknown->m.begin()->end();it++)
    {
        //和unKnown的碰撞
        if((mario->Map_x == *it->begin() - 40 ||mario->Map_x == *it->begin() + 40)
            && mario->y + mario->height - mario->distance < *(it->begin() + 1) + 40
            && mario->y + mario->height - mario->distance > *(it->begin() + 1) - 40
            )
        {
            mario->canmove = false;
        }
        else if((mario->Map_x == *it->begin() - 40||mario->Map_x == *it->begin() + 40)
                 && (mario->y + mario->height - mario->distance > *(it->begin() + 1)
                     || mario->y + mario->height - mario->distance < *(it->begin() + 1)-40))
        {
            mario->canmove= true;
        }

        //捡取金币的情况
        if (mario->Map_x - (*it->begin()) < 40 && mario->Map_x - (*it->begin()) >= -30
            &&*(it->begin() + 1) <= mario->y + mario->height -mario->distance + 40
            &&*(it->begin() + 1)+40 >= mario->y + mario->height -mario->distance + 40
            )
        {
            *(it->begin()+2) = 2;
            ScoreAdd();//拾取金币得一分
        }
    }

    //Monster
    for (QVector < QVector < int >> ::iterator it = monster->m.begin()->begin(); it != monster->m.begin()->end();it++)
    {
        if (*(it->begin() + 5) != 3)
        {
            if((mario->Map_x >= *(it->begin() + 2) - 30 && mario->Map_x <= *(it->begin() + 2) + 40)
                &&mario->y + mario->height - mario->distance >= *(it->begin() + 3)
                &&mario->y + mario->height - mario->distance <= *(it->begin() + 3) + 30
                )
            {
                mario->isdie = true;
                mario->canmove = false;
            }
        }
    }
}

void PlayWidget::Fall_Down(int &y)
{
    //管道
    //short
    for (QVector < QVector < int >> ::iterator it = pipe->m_short.begin()->begin(); it !=pipe->m_short.begin()->end();it++)
    {
        if (mario->Map_x - (*it->begin()) <= 70 && mario->Map_x - (*it->begin()) >= -30
            &&*(it->begin() + 1) == y + mario->height -mario->distance +20
            && mario->upstate == 2)
        {
            mario->height = 0;
            mario->distance = 80;
            mario->isjump = false;
            return;
        }
        if((mario->Map_x - (*it->begin()) == -30 || mario->Map_x - (*it->begin())==80)
            && mario->distance == 80 && mario->height == 0)
        {
            mario->isjump = true;
            mario->upstate = 2;
        }
    }
    //mid
    for (QVector < QVector < int >> ::iterator it = pipe->m_mid.begin()->begin(); it !=pipe->m_mid.begin()->end();it++)
    {
        if (mario->Map_x - (*it->begin()) <= 70 && mario->Map_x - (*it->begin()) >= -30
            &&*(it->begin() + 1) == y + mario->height -mario->distance +20
            && mario->upstate == 2)
        {
            mario->height = 0;
            mario->distance = 120;
            mario->isjump = false;
            return;
        }
        if((mario->Map_x - (*it->begin()) == -30 || mario->Map_x - (*it->begin())==80)
            && mario->distance == 120 && mario->height == 0)
        {
            mario->isjump = true;
            mario->upstate = 2;
        }
    }
    //long
    for (QVector < QVector < int >> ::iterator it = pipe->m_long.begin()->begin(); it !=pipe->m_long.begin()->end();it++)
    {
        if (mario->Map_x - (*it->begin()) <= 70 && mario->Map_x - (*it->begin()) >= -30
            &&*(it->begin() + 1) == y + mario->height -mario->distance +20
            && mario->upstate == 2)
        {
            mario->height = 0;
            mario->distance = 160;
            mario->isjump = false;
            return;
        }
        if((mario->Map_x - (*it->begin()) == -30 || mario->Map_x - (*it->begin())==80)
            && mario->distance == 160 && mario->height == 0)
        {
            mario->isjump = true;
            mario->upstate = 2;
        }
    }

    //坑
    for (QVector < QVector < int >> ::iterator it = hole->m.begin()->begin(); it !=hole->m.begin()->end();it++)
    {
        if(mario->Map_x >(*it->begin())-10 && mario->Map_x < *(it->begin() + 1)-10
                &&mario->height == 0 && mario->distance == 0
            )
        {
            mario->y = 645;
            mario->height = -160;
            mario->isjump = true;
            mario->upstate = 2;
        }
        else if(mario->Map_x >(*it->begin())-10 && mario->Map_x < *(it->begin() + 1)-10
                 &&mario->height == -80 && mario->y == 645
            )
        {
            mario->isjump = false;
            mario->isdie = true;
        }
    }

    //三角砖
    for (QVector < QVector < int >> ::iterator it = brick->m.begin()->begin(); it !=brick->m.begin()->end();it++)
    {
        if(mario->Map_x > (*it->begin()) - 40 && mario->Map_x < (*(it->begin() + 1))
            &&mario->distance - mario->height == (*(it->begin() + 2)) * 40
            && mario->upstate == 2
            )
        {
            mario->height = 0;
            mario->distance = (*(it->begin() + 2)) * 40;
            mario->isjump = false;
            return;
        }
        if((mario->Map_x == (*it->begin()) - 40 ||mario->Map_x == (*(it->begin() + 1)))
            && mario->distance == (*(it->begin() + 2)) * 40
            && mario->height == 0
            )
        {
            mario->isjump = true;
            mario->upstate = 2;
        }
    }

    //unKnown
    for (QVector < QVector < int >> ::iterator it = unknown->m.begin()->begin(); it !=unknown->m.begin()->end();it++)
    {
        if (mario->Map_x - (*it->begin()) < 40 && mario->Map_x - (*it->begin()) >= -30
            &&*(it->begin() + 1) == y + mario->height -mario->distance + 40
            && mario->upstate == 2)
        {
            mario->height = 0;
            mario->distance = y - *(it->begin() + 1) + 40;
            mario->isjump = false;
            return;
        }
        if((mario->Map_x - (*it->begin()) == -40 || mario->Map_x - (*it->begin())==40)&&
            mario->distance == y - *(it->begin() + 1) + 40 && mario->height == 0)
        {
            mario->isjump = true;
            mario->upstate = 2;
        }
    }

    //Monster
    for (QVector < QVector < int >> ::iterator it = monster->m.begin()->begin(); it != monster->m.begin()->end();it++)
    {
        if (*(it->begin() + 5) == 3)
        {
            if((mario->Map_x >= *(it->begin() + 2) - 30 && mario->Map_x <= *(it->begin() + 2) + 40)
                &&y + mario->height - mario->distance == *(it->begin() + 3) - 20
                )
            {
                *(it->begin() + 5) = 3;
                mario->upstate = 1;
                ScoreAdd();
            }
        }
        else
        {
            if((mario->Map_x >= *(it->begin() + 2) - 30 && mario->Map_x <= *(it->begin() + 2) + 40)
                &&y + mario->height - mario->distance == *(it->begin() + 3) - 40
                )
            {
                *(it->begin() + 5) = 3;
                mario->upstate = 1;
                ScoreAdd();
            }
        }
    }
}

void PlayWidget::DieState()
{
    if(mario->isdie)
    {
        qDebug() << mario->life;
        killTimer(timer1);//结束计时器
        emit MarioDie();
    }
}

void PlayWidget::restart()
{
    //此函数用于马里奥生命值不为0的时候游戏的重置

    //重新初始化游戏数据
    mario->isdie = false;
    xnow = 0;
    mario->x = 0;
    mario->y = 485;
    mario->height = 0;
    mario->Map_x = 0;
    mario->canmove = true;

    //重启计时器
    QTimer::singleShot(1000, this, [=]() {
        timer1 = startTimer(15);
    });
    this->setFocusPolicy(Qt::StrongFocus);
}

void PlayWidget::ScoreAdd()
{
    //得分函数
    score++;
}

void PlayWidget::Game_Win()
{
    if(mario->Map_x == 7620 && mario->isWin == false)
    {
        mario->isWin = true;
    }
}



