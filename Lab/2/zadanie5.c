#include <stdio.h>

int NWD(int x, int y)
{
    while(y != 0)
    {
        int bufor = y;
        y = x % y;
        x = bufor;
    }

    return x;
}

int main()
{
    int tablicaTau[1000] = {1};

    for(int n = 2; n <= 1000; n++)
    {
        tablicaTau[n] += tablicaTau[n - 1];

        for(int i = 1; i < n; i++)
        {
            if(NWD(i, n) == 1) tablicaTau[n] += 2;
        }
    }

    for(int i = 1; i <= 1000; i++)
    {
        printf("%d;%lf\n", i, tablicaTau[i - 1] / (double)(i * i));
    }
}