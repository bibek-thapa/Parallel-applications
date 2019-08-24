

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_SIZE 900000000

extern void gpu_dot_product(int *a, int *b, int *c, int size);

int main (int argc, char *argv[])
{
   int *a = (int *) malloc(ARRAY_SIZE * sizeof(int));
   int *b = (int *) malloc(ARRAY_SIZE * sizeof(int));
   int *c = (int *) malloc(ARRAY_SIZE * sizeof(int));
   int i;
   long dot = 0;
   
   


   clock_t start, stop;
	start = clock();
   gpu_dot_product (a, b, c, ARRAY_SIZE);
   stop = clock();
   printf ("TIME : %ld\n", stop - start);
   printf ("Array c:\n");
   for (i=0; i < ARRAY_SIZE; i++)
	{
		 dot += c[i];
     }

      printf ("%ld ", dot);
  
   
   free (a);
   free (b);
   free (c);
   
   return 0;
}