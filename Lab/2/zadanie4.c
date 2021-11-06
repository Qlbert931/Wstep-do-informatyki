#include <stdio.h>
#include <math.h>

int main()
{
    double wynik = 1;
    for(int i = 1; i <= 1000; i++)
    {
        wynik *= pow(i, 0.001);
    }
    printf("przyblizenie to wynosi %lf\n", wynik);
}