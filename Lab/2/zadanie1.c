#include <stdio.h>
#define zl *100
#define gr *1
#define ILOSC_BANKNOTOW 5
#define ILOSC_MONET 9


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

void wypiszNominal(int nominal)
{
    if(nominal >= 1 zl)
    {
        printf("%d zl\n", nominal / (1 zl));
    }
    else
    {
        printf("%d gr\n", nominal);
    }
}

int main()
{
    int cena = wczytajInt("podaj liczbe zlotych: ")zl + wczytajInt("podaj liczbe groszy: ")gr;

    int tablicaNominalow[ILOSC_BANKNOTOW + ILOSC_MONET] = {200 zl, 100 zl, 50 zl, 20 zl, 10 zl, 5 zl, 2 zl, 1 zl, 50 gr, 20 gr, 10 gr, 5 gr, 2 gr, 1 gr};
    
    printf("\tbanknoty:\n");
    for(int i = 0; i < ILOSC_BANKNOTOW; i++) //Niezmiennik to tablicaNominalow oraz cena >= 1 zl
    {
        if(cena / tablicaNominalow[i] > 0)
        {
            printf("\t\t%d x ", cena / tablicaNominalow[i]);
            wypiszNominal(tablicaNominalow[i]);
            cena %= tablicaNominalow[i];
        }
    }

    printf("\tmonety:\n");
    for(int i = ILOSC_BANKNOTOW; i < ILOSC_MONET + ILOSC_BANKNOTOW; i++)//Niezmiennik to tablicaNominalow oraz cena >= 0
    {
        if(cena / tablicaNominalow[i] > 0)
        {
            printf("\t\t%d x ", cena / tablicaNominalow[i]);
            wypiszNominal(tablicaNominalow[i]);
            cena %= tablicaNominalow[i];
        }
    }
}