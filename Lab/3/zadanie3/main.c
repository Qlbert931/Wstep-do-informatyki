#include <stdio.h>
#include <math.h>
#include "phi.h"
#include "wczytaj.h"

int main()
{
    long int x = wczytajLongInt("x: ");
    printf("phi( %ld ) = %d\n", x, phi(x));
}