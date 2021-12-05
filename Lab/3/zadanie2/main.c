#include <stdio.h>
#include <math.h>
#include "rozwiazanie.h"

int main()
{
    const double a = 2, b = 4;
    for(int i = 1; i <= 8; i++)
    {
        printf("rozwiazanie(%.0lf, %.0lf, %.8lf) = %.10lf\n", a, b, pow(10, -i), rozwiazanie(a, b, pow(10, -i)) );
    }
}