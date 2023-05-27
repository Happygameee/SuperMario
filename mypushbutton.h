
#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H


#include <QPushButton>


class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    MyPushButton(QString BtnImg);

    QString BtnImgPath;//传入按钮的图片

    //按下按钮的特效显示
    void zoom1();
    void zoom2();

signals:

};

#endif // MYPUSHBUTTON_H
