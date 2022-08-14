#include <bits/stdc++.h>
using namespace std;
int *merge(int[], int[], int, int);
void merge_array(int arr[], int n);
int *merge(int a[], int b[], int m, int n)
{
   int *arr = new int[m + n];
   int i, j, k;
   i = j = k = 0;
   while (i < m && j < n)
   {
      if (a[i] < b[j])
      {
         arr[k++] = a[i++];
      }
      else
      {
         arr[k++] = b[j++];
      }
   }
   while (i < m)
   {
      arr[k++] = a[i++];
   }
   while (j < n)
   {
      arr[k++] = b[j++];
   }
   return arr;
}
int main()
{
   /*int a[15], b[15];
   for (int i = 9; i < 24; i++)
   {
      a[i - 9] = i;
   }
   for (int j = 2; j < 17; j++)
   {
      b[j - 2] = j;
   }
   int *arr = merge(a, b, 15, 15);
   for (int i = 0; i < 15; i++)
   {
      // cout << a[i] << " ";
   }
   for (int i = 0; i < 15 + 15; i++)
   {
      cout << arr[i] << " ";
   }*/
   // Mergin if two sorted arrays are in the same array
   int arr[30];
   for (int i = 0; i < 15; i++)
   {
      arr[i] = 2 * i;
   }
   for (int i = 15; i < 30; i++)
   {
      arr[i] = i;
   }
   merge_array(arr, 30);
   for (int i = 0; i < 30; i++)
   {
      cout << arr[i] << " ";
   }
   return 0;
}
void merge_array(int arr[], int n)
{
   int k;
   for (int i = 0; i < n - 1; i++)
   {
      if (arr[i] != arr[i + 1])
      {
         k = i + 1;
         break;
      }
   }
   int pos = k, low, high;
   low = 0;
   high = k;
   while (low < pos && high < n)
   {
      if (arr[low] < arr[high])
      {
         low++;
      }
      else
      {
         int key = arr[high];
         for (int z = high; z > low; z--)
         {
            arr[z] = arr[z - 1];
         }
         arr[low++] = key;
      }
   }
}