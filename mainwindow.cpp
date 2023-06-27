
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>
#include "mypushbutton.h"
#include "assistant.h"
#include "tranwidget.h"
#include "playwidget.h"
#include "diewidget.h"
#include "global.h"
#include "gameover.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1200,600);
    this->setWindowIcon(QPixmap(":/resources/image/entity/person/childright0.png"));
    this->setWindowTitle("Mario");

    MusicPlayer *musicplayer = new MusicPlayer;
    musicplayer->backMusicPlay(BackMusic1);

    MyPushButton *startBtn = new MyPushButton(":/resources/image/end.png");
    MyPushButton *assistBtn = new MyPushButton(":/resources/image/help.png");

    startBtn->setParent(this);
    assistBtn->setParent(this);
    startBtn->move(376,330);
    assistBtn->move(374,450);

    connect(assistBtn,&QPushButton::clicked,[=](){
        assistBtn->zoom1();
        assistBtn->zoom2();
        QTimer::singleShot(100,this,[=](){
        emit pressa();
        });
    });

    connect(startBtn,&QPushButton::clicked,[=](){
        startBtn->zoom1();
        startBtn->zoom2();
        QTimer::singleShot(100,this,[=](){
            emit presss();
        });
    });

    //跳转至帮助页面
    Assistant *assistantwidget = new Assistant;
    //监听帮助页面
    connect(assistantwidget,&Assistant::back,[=](){
        QTimer::singleShot(100,this,[=](){
            this->setGeometry(assistantwidget->geometry());
            this->show();
            assistantwidget->hide();
        });
    });
    connect(this,&MainWindow::pressa,[=](){
        QTimer::singleShot(100,this,[=](){
            assistantwidget->setGeometry(this->geometry());
            assistantwidget->show();
            this->hide();
        });//延时进行页面切换 让切换动画变得流畅一点
    });

    //跳转至过渡界面
    connect(this,&MainWindow::presss,[=](){
        Tranwidget *tranwidget = new Tranwidget;
        PlayWidget *playwidget = new PlayWidget;
        DieWidget *diewidget = new DieWidget;
        QTimer::singleShot(100,this,[=](){
            musicplayer->backMusicclose();
            tranwidget->setGeometry(this->geometry());
            tranwidget->show();
            this->hide();
            //过渡界面切换完之后里面切换到playwidget
            QTimer::singleShot(2000,this,[=](){
                playwidget->setGeometry(tranwidget->geometry());
                playwidget->show();
                tranwidget->hide();
            });
        });

        connect(playwidget,&PlayWidget::MarioDie,[=](){
            playwidget->mario->life--;
            if (playwidget->mario->life > 0)//马里奥生命值不为0 还能继续游戏
            {
                QTimer::singleShot(2500,this,[=](){
                    playwidget->mario->isdie = false;

                    //record->setParent(tranwidget);
                    playwidget->musicplayer->backMusicclose();
                    diewidget->setGeometry(playwidget->geometry());
                    diewidget->MarioLife = playwidget->mario->life;
                    diewidget->Refresh();
                    diewidget->show();

                    playwidget->restart();

                    QTimer::singleShot(1000,this,[=](){
                        //record->setParent(playwidget);
                        //record->mario = playwidget->mario;
                        playwidget->musicplayer->backMusicPlay(BackMusic1);
                        playwidget->setGeometry(tranwidget->geometry());
                        playwidget->show();
                        diewidget->hide();
                    });
                });
            }
            else if (playwidget->mario->life == 0)//结束游戏
            {
                GameOver *gameover = new GameOver;
                //返回开始界面
                QTimer::singleShot(2500,this,[=](){
                    playwidget->musicplayer->backMusicclose();
                    musicplayer->backMusicPlay(Game_Over);
                    gameover->show();
                    playwidget->hide();
                    QTimer::singleShot(4000,this,[=](){
                        musicplayer->backMusicclose();
                        musicplayer->backMusicPlay(BackMusic1);
                        this->setGeometry(playwidget->geometry());
                        this->show();
                        diewidget->hide();
                        delete playwidget;
                        delete tranwidget;
                        delete diewidget;
                        delete gameover;
                    });
                });
            }
        });

        connect(playwidget,&PlayWidget::PressB,[=](){
            QTimer::singleShot(1000,this,[=](){
                this->setGeometry(playwidget->geometry());
                this->show();
                playwidget->musicplayer->backMusicclose();
                musicplayer->backMusicPlay(Game_Over);
                playwidget->hide();
                delete tranwidget;
                delete playwidget;
                delete diewidget;
            });
        });

        //游戏胜利返回主场景
        connect(playwidget,&PlayWidget::Win,[=](){
            QTimer::singleShot(1000,this,[=](){
                this->setGeometry(playwidget->geometry());
                this->show();
                playwidget->musicplayer->backMusicclose();
                //musicplayer->backMusicPlay();
                playwidget->hide();
                delete tranwidget;
                delete playwidget;
                delete diewidget;
            });
        });
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)//重写绘图事件
{
    QPainter painter(this);

    QPixmap pix;

    pix.load(":/resources/image/mainscene.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    switch (ev->key()) {
    case Qt::Key_S:
        emit presss();
        break;
    case Qt::Key_A:
        emit pressa();
        break;
    default:
        break;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *ev)
{
    switch (ev->key()) {
    default:
        break;
    }
}


