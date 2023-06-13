
#include "monster.h"

Monster::Monster()
{
    MonsterInit();
}

void Monster::MonsterInit()
{
    m.clear();
    //储存Monster信息的数组 前四个数据表示Monster的坐标以及移动范围
    //第五个数据表示Monster的方向 0表示向左 1表示向右
    //第六个数据用来制作Monster移动的动画
    int arr[1][6] = {
        {500,600,600,485,1,1},
    };

    for (int i = 0; i < 1; i++) {
        v.push_back(arr[i][0]);
        v.push_back(arr[i][1]);
        v.push_back(arr[i][2]);
        v.push_back(arr[i][3]);
        v.push_back(arr[i][4]);
        v.push_back(arr[i][5]);
        v2.push_back(v);
        v.clear();
    }
    m.insert(1, v2);
    v2.clear();
}

void Monster::MonsterMove()
{
    for (QVector < QVector < int >> ::iterator it = m.begin()->begin(); it != m.begin()->end();it++)
    {
        if (*(it->begin() + 5) == 2)
        {
            *(it->begin() + 5) = 1;
        }
        else if(*(it->begin() + 5) == 1)
        {
            *(it->begin() + 5) = 2;
        }
        if(*(it->begin() + 2) >*(it->begin()) && *(it->begin() + 2) <*(it->begin() + 1))
        {
            if (*(it->begin() + 4) == 0)
            {
                *(it->begin() + 2) -= 10;
            }
            else if(*(it->begin() + 4) == 1)
            {
                *(it->begin() + 2) += 10;
            }
        }
        else if(*(it->begin() + 2) == *(it->begin()) || *(it->begin() + 2) == *(it->begin() + 1))
        {
            if (*(it->begin() + 4) == 0)
            {
                *(it->begin() + 4) = 1;
                *(it->begin() + 2) += 10;
            }
            else if(*(it->begin() + 4) == 1)
            {
                *(it->begin() + 4) = 0;
                *(it->begin() + 2) -= 10;
            }
        }
    }
}


