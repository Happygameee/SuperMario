
#include "pipe.h"

Pipe::Pipe()
{
    PipeInit();
}

void Pipe::PipeInit()
{
    m_short.clear();
    m_mid.clear();
    m_long.clear();
    int arr_short[3][2] = {{780,445},
                           {6220,445},
                           {6860,445}
                      };
    int arr_mid[1][2] = {{1190,405}//80
    };
    int arr_long[2][2] = {{1510,365},
                         {1950,365}
    };

    for (int i = 0; i < 3; i++) {
        v.push_back(arr_short[i][0]);
        v.push_back(arr_short[i][1]);
        v2.push_back(v);
        v.clear();
    }
    m_short.insert(1, v2);
    v2.clear();
    for (int i = 0; i < 1; i++) {
        v.push_back(arr_mid[i][0]);
        v.push_back(arr_mid[i][1]);
        v2.push_back(v);
        v.clear();
    }
    m_mid.insert(1, v2);
    v2.clear();
    for (int i = 0; i < 2; i++) {
        v.push_back(arr_long[i][0]);
        v.push_back(arr_long[i][1]);
        v2.push_back(v);
        v.clear();
    }
    m_long.insert(1, v2);
    v2.clear();
}

