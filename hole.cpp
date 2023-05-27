
#include "hole.h"

Hole::Hole()
{
    HoleInit();
}

void Hole::HoleInit()
{
    m.clear();
    int arr[3][2] = {
        {2485,2535},
        {3125,3220},
        {5825,5865}
    };

    for (int i = 0; i < 3; i++) {
        v.push_back(arr[i][0]);
        v.push_back(arr[i][1]);
        v2.push_back(v);
        v.clear();
    }
    m.insert(1, v2);
    v2.clear();
}

