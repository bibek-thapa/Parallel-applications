// vAdd.c
//
// Program to add two vectors using a GPU

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_SIZE 900000000

int dotProduct (int *a, int *b, int *c)
{
    for (int x = 0; x < ARRAY_SIZE; x++){
      if (x >= ARRAY_SIZE/2) {
         a[x] = x - ((x - (ARRAY_SIZE/2)) * 2);
      }
      else {
         a[x] = x + 1;
      }

      b[x] = (x % 10) + 1;
      c[x] = a[x] * b[x];

    }
 }

int main (int argc, char *argv[])
{
   int *a = (int *) malloc(ARRAY_SIZE * sizeof(int));
   int *b = (int *) malloc(ARRAY_SIZE * sizeof(int));
   int *c = (int *) malloc(ARRAY_SIZE * sizeof(int));
   int i;
   unsigned int r = 0;

   for (i=0; i < ARRAY_SIZE; i++) {
      a[i] = 0;
	   b[i] = 0;
	   c[i] = 0;
   }

//   for (i=0; i < ARRAY_SIZE; i++)
//      c[i] = a[i] + b[i];
	clock_t start, stop;
   start = clock();
   dotProduct (a, b, c);

   for (i=0; i < ARRAY_SIZE; i++) {
      r += c[i];
   }
   stop = clock();

   printf ("Sequential : ");
   printf ("%d\n", ARRAY_SIZE);
   printf ("Dot Product: ");
   printf ("%d\n ", r);
   printf ("TIME : %ld\n", stop - start);

   free (a);
   free (b);
   free (c);

   return 0;
}
