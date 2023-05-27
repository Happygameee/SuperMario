
#ifndef MARIO_H
#define MARIO_H

#include <QString>


class Mario
{
public:
    Mario();
    int x;//马里奥在屏幕中的x坐标
    int Map_x;//马里奥在地图中的x坐标
    int y;//马里奥的y坐标
    int life;//马里奥的剩余生命值
    int walkstate;
    int height;//马里奥的离地高度
    int distance;//马里奥所处平台离地面高度
    int upstate;//判断马里奥是在上升阶段还是下降阶段 0为在地面上 1为上升 2为下降
    QString direction;//马里奥移动方向
    bool isjump;
    bool canmove;//判断马里奥是否还能继续移动
    bool ismoving;//判断马里奥是否正在移动
    bool isdie;

    void walk();
    void jump_down();
    void Mario_Init();
    void Mario_Die();
};

#endif // MARIO_H
