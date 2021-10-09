#include <stdio.h>

double readInt(char* question)
{
    int result;

    printf("%s", question);

    while (scanf("%d", &result) < 1)
    {
        while(getchar() != '\n');
        printf("%s", question);
    }

    while(getchar() != '\n');

    return result;
}

int main(void)
{
    int n = readInt("n: ");

    for(int i = 0; i < n; i++)
    {
        for(int k = i + 1; k < n; k++)
        {
            printf(" ");
        }

        for(int k = 0; k < (i * 2 + 1); k++)
        {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}