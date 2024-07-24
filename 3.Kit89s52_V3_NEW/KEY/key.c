#include "key.h"
unsigned int get_key(void)
{
    KEY0=KEY1=KEY2=KEY3=1;
    if(!KEY0)
    {
        delay_ms(10);
        if(!KEY0)
        return 1;
    }
    if(!KEY1)
    {
        delay_ms(10);
        if(!KEY1)
        return 2;
    }
    if(!KEY2)
    {
        delay_ms(10);
        if(!KEY2)
        return 3;
    }
    if(!KEY3)
    {
        delay_ms(10);
        if(!KEY3)
        return 4;
    }
    return 0;
}