
#include "flag.h"

Flag::Flag()
{
    FlagInit();
}

void Flag::FlagInit()
{
    Flag_x = 7650;
    Flag_y = 120;
}

void Flag::FlagLower()
{
    if (Flag_y != 440)
    {
        Flag_y += 10;
    }
}
