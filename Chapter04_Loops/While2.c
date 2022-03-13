#include <stdio.h>

int main()
{
   int num_iteration = 3;
   int i = 0;

   while(1)
   {
       printf("Hello World!\n");
       i++;

       if(i >= num_iteration)
       {
           break;
       }
   }

   return 0;
}
