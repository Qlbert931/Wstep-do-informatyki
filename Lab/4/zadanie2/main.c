#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int KodToHash(char *kod);
void HashToKod(int Hash, char *out);
bool SprawdzamCzyKodPasujeDoPropozycjiIOdpowiedzi(char *kod, char *propozycja, int red, int white);
int wczytajInt(char* pytanie);

int main()
{

    //TEST - 1
    // printf("%d \n", KodToHash("1111"));
    // printf("%d \n", KodToHash("1112"));
    // printf("%d \n", KodToHash("4532"));
    // printf("%d \n", KodToHash("6666"));

    //TEST - 2
    // char output[5];
    // HashToKod(0, output);
    // printf("%s \n", output);
    // HashToKod(1, output);
    // printf("%s \n", output);
    // HashToKod(805, output);
    // printf("%s \n", output);
    // HashToKod(1295, output);
    // printf("%s \n", output);

    // TEST - 3
    // printf(SprawdzamCzyKodPasujeDoPropozycjiIOdpowiedzi("1111", "1222", 1, 0) ? "true \n" : "false \n");
    // printf(SprawdzamCzyKodPasujeDoPropozycjiIOdpowiedzi("1222", "3133", 0, 1) ? "true \n" : "false \n");
    // printf(SprawdzamCzyKodPasujeDoPropozycjiIOdpowiedzi("3133", "3414", 1, 1) ? "true \n" : "false \n");
    // printf(SprawdzamCzyKodPasujeDoPropozycjiIOdpowiedzi("3414", "3441", 2, 2) ? "true \n" : "false \n");
    // printf(SprawdzamCzyKodPasujeDoPropozycjiIOdpowiedzi("3414", "3441", 1, 2) ? "true \n" : "false \n");
    // printf(SprawdzamCzyKodPasujeDoPropozycjiIOdpowiedzi("3414", "3441", 2, 1) ? "true \n" : "false \n");
    // printf(SprawdzamCzyKodPasujeDoPropozycjiIOdpowiedzi("3414", "3441", 1, 1) ? "true \n" : "false \n");

    bool tablicaPytan[1296] = {}; //0 - potencjalne, 1 - na pewno nie
    char propozycja[5] = "1122"; 
    char bufor[5] = {};

    while(true)
    {
        printf("%s\n", propozycja);
        int red, white;
        red = wczytajInt("red: ");
        white = wczytajInt("white: ");

        if(red + white > 4)
        {
            printf("Oszukales!\n");
            return 1;
        }
        if(red == 4)
        {
            printf("Wygralem!\n");
            return 0;
        }
        
        tablicaPytan[KodToHash(propozycja)] = true;
        for(int i = 0; i < 1296; i++)
        {
            if(!tablicaPytan[i])
            {
                HashToKod(i, bufor);
                tablicaPytan[i] = SprawdzamCzyKodPasujeDoPropozycjiIOdpowiedzi(bufor, propozycja, red, white);
            }
        }

        int i = 0;
        while(tablicaPytan[i])
        {
            i++;
            if(i >= 1296)
            {
                printf("Oszukales!\n");
                return 1;
            }
        }
        
        HashToKod(i, propozycja);
    }

}

int KodToHash(char *kod)
{
    int wynik = 0;
    while(*kod != '\0')
    {
        wynik = wynik * 6 + (*kod - '1');
        ++kod;
    }
    return wynik;
}

void HashToKod(int Hash, char *out) //out ma 4 znaki
{
    for(int i = 3; i >=0; i--)
    {
        out[i] = (Hash % 6) + '1';
        Hash /= 6;
    }
}

bool SprawdzamCzyKodPasujeDoPropozycjiIOdpowiedzi(char *kod, char *propozycja, int red, int white)
{
    char kKod[5], kPropozycja[5];
    strcpy(kKod, kod);
    strcpy(kPropozycja, propozycja);

    for(int i = 0; i <= 3; i++)
    {
        if(kKod[i] == kPropozycja[i])
        {
            red--;
            kPropozycja[i] = '0';
            kKod[i] = '0';
        }
    }

    for(int i = 0; i <= 3; i++)
    {
        if(kPropozycja[i] != '0')
        {
            for(int k = 0; k <= 3; k++)
            {
                if(kPropozycja[i] == kKod[k])
                {
                    white--;
                    kPropozycja[i] = '0';
                    kKod[k] = '0';
                    break;
                }
            }
        }
    }

    if(red == 0 && white == 0)
    {
        return false;
    }
    return true;
}

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
