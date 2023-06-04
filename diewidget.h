
#ifndef DIEWIDGET_H
#define DIEWIDGET_H


#include <QMainWindow>


class DieWidget : public QMainWindow
{
    Q_OBJECT
public:
    explicit DieWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);

signals:

};

#endif // DIEWIDGET_H
