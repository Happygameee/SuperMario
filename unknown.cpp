
#include "unknown.h"

Unknown::Unknown()
{
    UnknownInit();
}

void Unknown::UnknownInit()
{
    m.clear();
    int arr[1][2] = {
        {600,405}
    };

    for (int i = 0; i < 1; i++) {
        v.push_back(arr[i][0]);
        v.push_back(arr[i][1]);
        v2.push_back(v);
        v.clear();
    }
    m.insert(1, v2);
    v2.clear();
}

