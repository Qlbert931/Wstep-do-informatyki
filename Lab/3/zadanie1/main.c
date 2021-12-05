#include <stdio.h>
#include "palindrom.h"

int main()
{
    char wyrazenie[101];
    printf("wyrazenie: ");
    fgets(wyrazenie, sizeof(wyrazenie), stdin);
    if(palindrom(wyrazenie))
    {
        printf("Jest to palindrom\n");
    }
    else
    {
        printf("Nie jest to palindrom\n");
    }
}
