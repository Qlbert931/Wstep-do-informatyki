#include <stdio.h>
#include <math.h>
#include "agents.h"

double distance(struct agent a1, struct agent a2)
{
    int rx = a1.x - a2.x, ry = a1.y - a2.y;
    return sqrt(rx * rx + ry * ry);
}