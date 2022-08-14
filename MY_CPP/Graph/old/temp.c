#include <stdio.h>
int main()
{
   int row, col;
   printf("Enter the number of rows=");
   scanf("%d", &row);
   printf("Enter the number of columsn=");
   scanf("%d", &col);

   int arr[row][col];
   for (int i = 0; i < row; i++)
   {
      for (int j = 0; j < col; j++)
      {
         scanf("%d", &arr[i][j]);
      }
   }

   // Displaying elements of 2Darray
   for (int i = 0; i < row; i++)
   {
      for (int j = 0; j < col; j++)
      {
         printf("%d  ", arr[i][j]);
      }
      printf("\n");
   }
   return 0;
}