#include <stdio.h>

int sumaDzielnikow(int x)
{
    int suma = 0;

    for(int i = 1; i < x; i++)
    {
        if(x % i == 0)
        {
            suma += i;
        }
    }
    return suma;
}

int main()
{
    int tablicaSumDzielnikow[1000];

    for(int i = 1; i < 1000; i++)
    {
        tablicaSumDzielnikow[i] = sumaDzielnikow(i);
    }

    printf("Liczby doskonale:\n");
    for(int i = 1; i < 1000; i++)
    {
        if(i == tablicaSumDzielnikow[i])
        {
            printf("\t%d\n", i);
        }
    }

    printf("Pary liczb zaprzyjaznionych:\n");
    for(int i = 1; i < 1000; i++)
    {
        if(i == sumaDzielnikow(tablicaSumDzielnikow[i]) && i < tablicaSumDzielnikow[i])
        {
            printf("\t(%d, %d)\n", i, tablicaSumDzielnikow[i]);
        }
    }
    
}