
#ifndef PLAYWIDGET_H
#define PLAYWIDGET_H

#include <QMainWindow>
#include "mario.h"
#include <QTimer>
#include <pipe.h>
#include <hole.h>

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
    void restart();

    Mario *mario;
    Pipe *pipe;
    Hole *hole;

    int timer1;
    int timer2;
    int timer3;

    int xnow = 0;
signals:
    void MarioDie();
};

#endif // PLAYWIDGET_H
