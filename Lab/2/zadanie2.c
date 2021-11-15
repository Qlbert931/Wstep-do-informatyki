#include <stdio.h>
#include <assert.h>

int wczytajInt(char* pytanie)
{
    int wynik;

    printf("%s", pytanie);

    while (scanf("%d", &wynik) < 1)
    {
        while(getchar() != '\n');
        printf("%s", pytanie);
    }

    while(getchar() != '\n');

    return wynik;
}

double wczytajDouble(char* pytanie)
{
    double wynik;

    printf("%s", pytanie);

    while (scanf("%lf", &wynik) < 1)
    {
        while(getchar() != '\n');
        printf("%s", pytanie);
    }

    while(getchar() != '\n');

    return wynik;
}

int main()
{
    int n = wczytajInt("n: ");
    assert(n > 0);

    double suma = 0;
    for(int i = 0; i < n; i++)//Niezmiennik petli to n oraz suma >= 0
    {
        printf("\tx%d", i + 1);
        suma += wczytajDouble(": ");
    }

    printf("srednia arytmetyczna = %lf\n", suma / n);

}