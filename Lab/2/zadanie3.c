#include <stdio.h>

int main()
{
    double suma = 0;
    int n = 0;
    while(suma <= 10.0)//Niezmiennik tej petli to n >= 0 suma >= 0
    {
        n++;
        suma += 1.0 / n;
    }
    printf("najmniejsze n = %d\n", n);
}