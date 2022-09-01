#include <iostream>
using namespace std;
void swap(int &x, int &y);
void printArray(int arr[], int n);
void bubbleSort(int arr[], int n);
void mergeArrays(int A[], int B[], int aSize, int bSize, int C[]);
int linearSearch(int arr[], int key, int size);
void solve(int arr[], int n, int k)
{
   int aSize, bSize;
   if (n % 2 == 1)
   {
      aSize = (n / 2) + 1;
      bSize = (n / 2);
   }
   else
   {
      aSize = bSize = n / 2;
   }
   int A[aSize];
   int B[bSize];
   int C[n];
   for (int i = 0; i < aSize; i++)
   {
      A[i] = arr[i];
   }
   for (int i = aSize; i < n; i++)
   {
      B[i - aSize] = arr[i];
   }
   bubbleSort(A, aSize);
   bubbleSort(B, bSize);
   mergeArrays(A, B, aSize, bSize, C);
   int x, y, z;
   x = linearSearch(A, k, aSize);
   y = linearSearch(B, k, bSize);
   z = linearSearch(C, k, n);
   if (x == -1 && y == -1)
   {
      cout << x << endl;
      cout << linearSearch(C, k, n);
   }
   else
   {
      if (x == -1)
      {
         cout << y << endl;
         printArray(B, bSize);
      }
      else
      {
         cout << x << endl;
         printArray(A, aSize);
      }
   }
   cout << z;
}
int main()
{
   int n, k;
   cin >> n;
   int arr[n];
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }
   cin >> k;
   solve(arr, n, k);
   return 0;
}
int linearSearch(int arr[], int key, int size)
{
   for (int i = 0; i < size; i++)
   {
      if (arr[i] == key)
      {
         return i;
      }
   }
   return -1;
}
void mergeArrays(int A[], int B[], int aSize, int bSize, int C[])
{
   int i, j, k;
   i = j = k = 0;
   while (i < aSize && j < bSize)
   {
      if (A[i] < B[j])
      {
         C[k++] = A[i++];
      }
      else
      {
         C[k++] = B[j++];
      }
   }
   while (i < aSize)
   {
      C[k++] = A[i++];
   }
   while (j < bSize)
   {
      C[k++] = B[j++];
   }
}
void printArray(int arr[], int n)
{
   for (int i = 0; i < n; i++)
   {
      cout << arr[i] << " ";
   }
   cout << endl;
}
void bubbleSort(int arr[], int n)
{
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n - 1 - i; j++)
      {
         if (arr[j] > arr[j + 1])
         {
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
         }
      }
   }
}
void swap(int &x, int &y)
{
   int temp = x;
   x = y;
   y = temp;
}