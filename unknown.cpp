
#include "unknown.h"

Unknown::Unknown()
{
    UnknownInit();
}

void Unknown::UnknownInit()
{
    m.clear();
    int arr[1][3] = {
        {300,405,1}
    };

    for (int i = 0; i < 1; i++) {
        v.push_back(arr[i][0]);
        v.push_back(arr[i][1]);
        v.push_back(arr[i][2]);
        v2.push_back(v);
        v.clear();
    }
    m.insert(1, v2);
    v2.clear();
}

void Unknown::Unknown_crash(QVector<QVector < int>>::iterator it)
{
    if (coin == 0)
    {
        coin = 1;
        coin_state = 1;
        coinheight = 0;
        coin_y = *(it->begin() + 1);
    }
}

void Unknown::CoinAppear()
{
    if(coin_state == 1)
    {
        if (coinheight == -50)
        {
            coin_state = 2;
        }
        else
        {
            coinheight -= 10;
        }
    }
    else if(coin_state == 2)
    {
        if (coinheight == 0)
        {
            coin_state = 0;
        }
        else
        {
            coinheight += 10;
        }
    }
    else if (coin_state == 0)
    {

    }
}

