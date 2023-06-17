
#include "boom.h"

Boom::Boom()
{
    BoomInit();
}

void Boom::BoomInit()
{
    m.clear();
    int arr[3][3] = {
        {7600,200,3},
        {7500,200,3},
        {7400,200,3}
    };

    for (int i = 0; i < 3; i++) {
        v.push_back(arr[i][0]);
        v.push_back(arr[i][1]);
        v.push_back(arr[i][2]);
        v2.push_back(v);
        v.clear();
    }
    m.insert(1, v2);
    v2.clear();
}

void Boom::BoomRelease(QVector<QVector < int>>::iterator it)
{
    if(*(it->begin() + 2) == 3)
    {
        *(it->begin() + 2) = 0;
    }
    else if (*(it->begin() + 2) == 2)
    {
        *(it->begin() + 2) = 0;
    }
    else if(*(it->begin() + 2) >=0)
    {
        (*(it->begin() + 2))++;
    }
}
