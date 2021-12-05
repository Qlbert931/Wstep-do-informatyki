#include <stdio.h>
#include "agents.h"

struct agent newagent(int x, int y)
{
    struct agent wynik; 
    wynik.x = x;
    wynik.y = y;
    return wynik;
}