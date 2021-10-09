//KOMPILUJ Z -lm
#include <stdio.h>
#include <math.h>

double readDouble(char* question)
{
    double result;

    printf("%s", question);

    while (scanf("%lf", &result) < 1)
    {
        while(getchar() != '\n');
        printf("%s", question);
    }

    while(getchar() != '\n');

    return result;
}

int main(void)
{
    double a, b, c;
    a = readDouble("a: ");
    b = readDouble("b: ");
    c = readDouble("c: ");

    if(a == 0.0f) // LINIOWA
    {
        if(b == 0.0f)
        {
            if(c != 0.0f)
            {
                printf("W zbiorze liczb rzeczywistych nie ma rozwiązania tego równania\n");
            }
            else
            {
                printf("Cały zbiór liczb rzeczywistych jest rozwiązaniem tego równania\n");
            }
        }
        else
        {
            printf("x = %lf\n", -c / b); //FIXME: SPYTAJ PANA CO TUTAJ
        }
    }
    else    //KWADRATOWA
    {
        double delta = (b * b) - (4 * a * c);

        if(delta > 0.0f)
        {
            printf("x1 = %lf\n", (-b - sqrt(delta)) / (2 * a));
            printf("x2 = %lf\n", (-b + sqrt(delta)) / (2 * a));
        }
        else if(delta < 0.0f)
        {
            printf("W zbiorze liczb rzeczywistych nie ma rozwiązania tego równania\n");
        }
        else
        {
            printf("x = %lf\n", -b / (2 * a));
        }
    }

    return 0;
}