
#ifndef DIEWIDGET_H
#define DIEWIDGET_H


#include <QMainWindow>


class DieWidget : public QMainWindow
{
    Q_OBJECT
public:
    explicit DieWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void Refresh();

    int MarioLife;
signals:

};

#endif // DIEWIDGET_H
