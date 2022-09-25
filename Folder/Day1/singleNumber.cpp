// Given an array of integers
//  there is one number which ocuurs once in the array
//  rest of the numbers occur three times
//  find that number
#include <iostream>
using namespace std;
int singleNumber(int arr[], int n);
int main()
{
   int n;
   cin >> n;
   int arr[n];
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }
   cout << singleNumber(arr, n);
   return 0;
}
int power(int a, int b)
{
   if (b == 0)
   {
      return 1;
   }

   else
   {
      int res = 1;
      for (int i = 0; i < b; i++)
      {
         res *= a;
      }
      return res;
   }
}
int singleNumber(int arr[], int n)
{
   int count[32];
   for (int i = 0; i < 32; i++)
   {
      count[i] = 0;
   }
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < 32; j++)
      {
         if (arr[i] & (1 << j))
         {
            count[j]++;
         }
      }
   }
   for (int i = 0; i < 32; i++)
   {
      count[i] = count[i] % 3;
      cout << count[i] << " ";
   }
   cout << endl;
   int res = 0;
   for (int i = 0; i < 32; i++)
   {
      if (count[i])
         res += power(2, i);
   }
   return res;
}