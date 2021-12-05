#include <stdio.h>
#include <math.h>
#include "f.h"

double rozwiazanie(double a, double b, double eps)
{
    while(b - a > eps)
    {
        double p = (b - a) / 2 + a;
        if(f(p) * f(a) < 0)
        {
            b = p;
        }
        else
        {
            a = p;
        }
    }
    return a;
}