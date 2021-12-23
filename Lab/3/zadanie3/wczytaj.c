#include <stdio.h>

long int wczytajLongInt(char* pytanie)
{
    long int wynik;

    printf("%s", pytanie);

    while (scanf("%ld", &wynik) < 1 || wynik < 1)
    {
        while(getchar() != '\n');
        printf("%s", pytanie);
    }

    while(getchar() != '\n');

    return wynik;
}