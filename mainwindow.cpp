
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>
#include "assistant.h"
#include "tranwidget.h"
#include "playwidget.h"
#include "diewidget.h"
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1200,600);
    this->setWindowIcon(QPixmap(":/resources/image/entity/person/childright0.png"));
    this->setWindowTitle("Mario");

    //创建记录器
//    record = new Recorder(this);
//    record->setFixedSize(800,60);
//    record->move(200,0);
//    record->show();

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
            //record->setParent(tranwidget);
            tranwidget->setGeometry(this->geometry());
            tranwidget->show();
            this->hide();
        });
        //过渡界面切换完之后里面切换到playwidget
        QTimer::singleShot(1000,this,[=](){
            //record->setParent(playwidget);
            //record->mario = playwidget->mario;
            playwidget->setGeometry(tranwidget->geometry());
            playwidget->show();
            tranwidget->hide();
        });

        connect(playwidget,&PlayWidget::MarioDie,[=](){
            playwidget->mario->life--;
            if (playwidget->mario->life > 0)//马里奥生命值不为0 还能继续游戏
            {
                playwidget->mario->isdie = false;

                QTimer::singleShot(2000,this,[=](){
                    //record->setParent(tranwidget);
                    diewidget->setGeometry(playwidget->geometry());
                    diewidget->show();

                    playwidget->restart();

                    QTimer::singleShot(1000,this,[=](){
                        //record->setParent(playwidget);
                        //record->mario = playwidget->mario;
                        playwidget->setGeometry(tranwidget->geometry());
                        playwidget->show();
                        diewidget->hide();
                    });
                });
            }
            else if (playwidget->mario->life == 0)//结束游戏
            {
                //返回开始界面
                QTimer::singleShot(1000,this,[=](){
                    diewidget->show();
                    playwidget->hide();
                    QTimer::singleShot(1000,this,[=](){
                        this->setGeometry(playwidget->geometry());
                        this->show();
                        diewidget->hide();
                        delete playwidget;
                        delete tranwidget;
                        delete diewidget;
                    });
                });
            }
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


