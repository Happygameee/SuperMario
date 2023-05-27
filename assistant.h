
#ifndef ASSISTANT_H
#define ASSISTANT_H


#include <QMainWindow>


class Assistant : public QMainWindow
{
    Q_OBJECT
public:
    explicit Assistant(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent *ev);
    void paintEvent(QPaintEvent *);
signals:
    void back();
};

#endif // ASSISTANT_H
