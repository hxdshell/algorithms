#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef uint8_t Byte;
int min(int a, int b, int c);

int main()
{
   char str1[51];
   char str2[51];

   str1[0] = str2[0] = '0';

   printf("Enter the start string: ");
   fgets(str1 + 1, sizeof(str1) - 1, stdin);
   str1[strcspn(str1, "\n")] = '\0';

   printf("Enter the start string: ");
   fgets(str2 + 1, sizeof(str2) - 1, stdin);
   str2[strcspn(str2, "\n")] = '\0';

   int len1 = strlen(str1);
   int len2 = strlen(str2);
   int distance[len1][len2];

   // Initialization
   for (int i = 0; i < len1; i++)
   {
      distance[i][0] = i;
   }
   for (int i = 0; i < len2; i++)
   {
      distance[0][i] = i;
   }

   int del, ins, sub;
   for (int i = 1; i < len1; i++)
   {
      for (int j = 1; j < len2; j++)
      {
         del = distance[i - 1][j] + 1;
         ins = distance[i][j - 1] + 1;
         sub = str1[i] == str2[j] ? 0 : 2;
         sub += distance[i - 1][j - 1];

         distance[i][j] = min(del, ins, sub);
         // printf("%d ", distance[i][j]);
      }
      // printf("\n");
   }
   printf("\nEdit Distance : %d", distance[len1 - 1][len2 - 1]);
   return 0;
}

int min(int del, int ins, int sub)
{
   if (del < ins && del < sub)
      return del;
   else if (ins < del && ins < sub)
      return ins;
   else
      return sub;
}