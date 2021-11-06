#include <stdio.h>

int main()
{
    double suma = 0;
    int n = 1;
    while(suma <= 10.0)//Niezmiennik tej petli to n >= 1 suma >= 0
    {
        suma += 1.0 / n;
        n++;
    }
    printf("najmniejsze n = %d\n", n);
}