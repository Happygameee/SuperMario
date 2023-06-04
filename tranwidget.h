
#ifndef TRANWIDGET_H
#define TRANWIDGET_H


#include <QMainWindow>

class Tranwidget : public QMainWindow
{
    Q_OBJECT
public:
    explicit Tranwidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);

signals:

};

#endif // TRANWIDGET_H
