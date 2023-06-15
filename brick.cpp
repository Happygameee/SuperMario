
#include "brick.h"

Brick::Brick()
{
    BrickInit();
}

void Brick::BrickInit()
{
    m.clear();
    int arr[24][3] = {
        //第一块三角区域
        {5050,5090,1},
        {5090,5130,2},
        {5130,5170,3},
        {5170,5210,4},

        //第二块三角区域
        {5290,5330,4},
        {5330,5370,3},
        {5370,5410,2},
        {5410,5450,1},

        //第三块三角区域
        {5610,5650,1},
        {5650,5690,2},
        {5690,5730,3},
        {5730,5810,4},

        //第四块三角区域
        {5900,5940,4},
        {5940,5980,3},
        {5980,6020,2},
        {6020,6060,1},

        //第五块三角区域
        {6940,6980,1},
        {6980,7020,2},
        {7020,7060,3},
        {7060,7100,4},
        {7100,7140,5},
        {7140,7180,6},
        {7180,7220,7},
        {7220,7300,8}
    };

    for (int i = 0; i < 24; i++) {
        v.push_back(arr[i][0]);
        v.push_back(arr[i][1]);
        v.push_back(arr[i][2]);
        v2.push_back(v);
        v.clear();
    }
    m.insert(1, v2);
    v2.clear();
}

