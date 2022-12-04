#include <stdio.h>
void main() {
   int i, space, rows, stars = 0;
   printf("Enter the number of rows: ");
   scanf("%d", &rows);
   for (i = 1; i <= rows; ++i, stars = 0) {
      for (space = 1; space <= rows - i; ++space) {
         printf("  ");
      }
      while (stars != 2 * i - 1) {
         printf("* ");
         ++stars;
      }
      printf("\n");
   }
   
}