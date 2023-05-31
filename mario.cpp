
#include "mario.h"
#include <QDebug>

Mario::Mario()
{
    Mario_Init();
}

void Mario::Mario_Init()
{
    x = 0;
    y = 485;
    Map_x = 0;
    life = 1;
    height = 0;
    distance = 0;
    upstate = 0;
    direction = "right";
    canmove = true;
    ismoving = false;
    isjump = false;
    walkstate = 0;
    isdie = false;
}

void Mario::walk()
{
    if (direction == "right" && ismoving == true && canmove == true && x < 600)
    {
        x += 10;
        Map_x += 10;
        if (walkstate < 3)
        {
            walkstate += 1;
        }
        else
        {
            walkstate = 1;
        }
    }
    else if (direction == "right" && ismoving == true && canmove == true && x >= 600)
    {
        Map_x += 10;
        if (walkstate < 3)
        {
            walkstate += 1;
        }
        else
        {
            walkstate = 1;
        }
    }
    if (direction == "right" && ismoving == true && canmove == false)
    {
        if (walkstate < 3)
        {
            walkstate += 1;
        }
        else
        {
            walkstate = 1;
        }
    }
    if (direction == "left" && ismoving == true && canmove == true && x <= 600)
    {
        x -= 10;
        Map_x -= 10;
        if (walkstate < 3)
        {
            walkstate += 1;
        }
        else
        {
            walkstate = 1;
        }
    }
    if (direction == "left" && ismoving == true && canmove == false)
    {
        if (walkstate < 3)
        {
            walkstate += 1;
        }
        else
        {
            walkstate = 1;
        }
    }
    if (ismoving == false)
    {
        walkstate = 0;
    }
    //qDebug() << Map_x;
}

void Mario::jump_down()
{
    if (isjump)
    {
        switch(upstate)
        {
        case 1:
            if (height == -180)
            {
                height -= 5;
                upstate = 2;
                break;
            }
            else{
                height -= 20;
                break;
            }
        case 2:
            if (height == 0 && distance == 0)
            {
                isjump = false;//结束不在地面的跳跃状态
                upstate = 0;
                break;
            }
            else
            {
                if (height == -185)
                {
                    height += 5;
                    break;
                }
                else{
                    if (height < 0)
                    {
                        height += 20;
                    }
                    else
                    {
                        distance -= 20;
                    }
                    break;
                }
            }
        default:
            break;
        }
    }
    else
    {
        upstate = 0;
    }
}

void Mario::Mario_Die()
{
    if(isdie && life >0)
    {

    }
    else if(life == 0)
    {

    }
}
