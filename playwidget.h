
#ifndef PLAYWIDGET_H
#define PLAYWIDGET_H

#include <QMainWindow>
#include "mario.h"
#include <QTimer>
#include <QSound>
#include "pipe.h"
#include "hole.h"
#include "brick.h"
#include "unknown.h"
#include "musicplayer.h"

class PlayWidget : public QMainWindow
{
    Q_OBJECT
public:
    explicit PlayWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);

    void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *ev);
    void timerEvent(QTimerEvent *ev);

    void gameInit();
    void Jump_Collision();
    void Move_Collision();
    void Fall_Down(int &);
    void DieState();
    void restart();//重新开始游戏的初始化

    Mario *mario;
    Pipe *pipe;
    Hole *hole;
    Brick *brick;
    Unknown *unknown;
    MusicPlayer *musicplayer;

    int timer1;
    int timer2;
    int timer3;

    int xnow = 0;//用于画地图的表示当前的x值
    int xblock = 0;
signals:
    void MarioDie();
};

#endif // PLAYWIDGET_H
