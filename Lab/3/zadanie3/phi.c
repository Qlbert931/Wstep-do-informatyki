#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct faktorNode
{
    long int p;
    int k;
    struct faktorNode *next;
};

int phi(long int x)
{
    if(x == 1)
    {
        return 1;
    }
   struct faktorNode *pFakt = malloc(sizeof(struct faktorNode)), *wFakt = pFakt;
   wFakt -> next = NULL;

   if(!(x % 2))
   {
       x /= 2;
       wFakt -> p = 2;
       wFakt -> k = 1;
       wFakt -> next = malloc(sizeof(struct faktorNode));
       while(!(x % 2))
       {
           x /= 2;
           wFakt -> k++;
       }
       wFakt = wFakt -> next;
       wFakt -> next = NULL;
   }
   
   int t = 3;
   while(x > 2)
   {
        if(!(x % t))
        {
            x /= t;
            wFakt -> p = t;
            wFakt -> k = 1;
            wFakt -> next = malloc(sizeof(struct faktorNode));
            while(!(x % t))
            {
                x /= t;
                wFakt -> k++;
            }
            wFakt = wFakt -> next;
            wFakt -> next = NULL;
        }
        t += 2;
   }

   wFakt = pFakt; 
   int wynik = 1;
   while(wFakt -> next)
   {
       //printf("node p = %ld k = %d\n", wFakt -> p, wFakt -> k);
       wynik *= pow(wFakt -> p, wFakt -> k - 1) * (wFakt -> p - 1);
       struct faktorNode *wBufor = wFakt -> next;
       free(wFakt);
       wFakt = wBufor;
   }
   free(wFakt);

   return wynik;
}