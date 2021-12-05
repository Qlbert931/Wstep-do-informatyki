#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool palindrom(char napis[])
{
    char sLP[101] = {}, *wsLP = sLP, sPL[101] = {}, *wsPL = sPL, *w = napis;
    while(*w != 0) // TWORZYMY OD LEWEJ DO PRAWEJ
    {
        if(isalnum(*w))
        {
            *wsLP = tolower(*w);
            wsLP++;
            w++;
        }
        else if(*w < 0) //POLSKIE LITERY KODOWANE NA PRZYKŁAD Ą = -60 -124 więc odrwacanie kolejności psuje ten znak
        {
            wsLP[0] = w[0];
            if(w[1] == -124 || w[1] == -102 || w[1] == -69 || w[1] == -71 || w[1] == -122 || w[1] == -127 || w[1] == -104 || w[1] == -125)
            {
                wsLP[1] = w[1] + 1;
            }
            else if(w[1] == -109) //Ó i ó nie różnią się o 1 :(
            {
                wsLP[1] = -77;
            }
            else 
            {
                wsLP[1] = w[1];
            }
            w += 2;
            wsLP += 2;
        }
        else
        {
            w++;
        }
    }

    while(napis <= w) // TWORZYMY OD PRAWEJ DO LEWEJ
    {
        if(isalnum(*w))
        {
            *wsPL = tolower(*w);
            wsPL++;
            w--;
        }
        else if(*w < 0) //POLSKIE LITERY KODOWANE NA PRZYKŁAD Ą = -60 -124 więc odrwacanie kolejności psuje ten znak
        {
            wsPL[0] = w[-1];
            if(w[0] == -124 || w[0] == -102 || w[0] == -69 || w[0] == -71 || w[0] == -122 || w[0] == -127 || w[0] == -104 || w[0] == -125)
            {
                wsPL[1] = w[0] + 1;
            }
            else if(w[0] == -109) //Ó i ó nie różnią się o 1 :(
            {
                wsPL[1] = -77;
            }
            else 
            {
                wsPL[1] = w[0];
            }
            w -= 2;
            wsPL += 2;
        }
        else
        {
            w--;
        }
    }

    if(!strcmp(sLP, sPL))
    {
        return true;
    }
    return false;
}