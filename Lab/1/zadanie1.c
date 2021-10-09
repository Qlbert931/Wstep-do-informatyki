#include <stdio.h>
#include <string.h>

int main(void)
{
    char text[] = "ABRAKADABRA";
    int lenght = strlen(text);
    
    for(int i = 0; i < lenght; i++)
    {
        for(int k = 0; k < i; k++)
        {
            printf(" ");
        }

        for(int k = 0; k  + i < lenght; k++)
        {
            printf("%c ", text[k]);
        }
        printf("\n");
    }

    return 0;
}