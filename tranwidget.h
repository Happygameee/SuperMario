
#ifndef TRANWIDGET_H
#define TRANWIDGET_H


#include <QMainWindow>
#include "mario.h"

class Tranwidget : public QMainWindow
{
    Q_OBJECT
public:
    explicit Tranwidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);

    Mario *mario;
signals:

};

#endif // TRANWIDGET_H
