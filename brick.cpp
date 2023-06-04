
#include "brick.h"

Brick::Brick()
{
    BrickInit();
}

void Brick::BrickInit()
{
    m.clear();
    int arr[17][2] = {
        //第一块三角区域
        {5060,1},
        {5100,2},
        {5140,3},
        {5180,4},

        //第二块三角区域
        {5420,1},
        {5380,2},
        {5340,3},
        {5300,4},

        //第三块三角区域
        {5620,1},
        {5660,2},
        {5700,3},
        {5740,4},
        {5780,4},


        //第四块三角区域
        {5900,4},
        {5940,3},
        {5980,2},
        {6020,1}
    };

    for (int i = 0; i < 17; i++) {
        v.push_back(arr[i][0]);
        v.push_back(arr[i][1]);
        v2.push_back(v);
        v.clear();
    }
    m.insert(1, v2);
    v2.clear();
}

