#include <iostream>
#include <algorithm>
using namespace std;
class minHeap
{
public:
   int *harr, n, size;
   minHeap()
   {
      size = 100001;
      n = -1;
      harr = new int[size];
   }
   minHeap(int x)
   {
      size = x;
      n = -1;
      harr = new int[size];
   }
   void passArray(int arr[], int n)
   {
      delete[] harr;
      harr = new int[n];
      size = n;
      this->n = -1;
      for (int i = 0; i < n; i++)
      {
         harr[i] = arr[i];
      }
   }
   void arrayToHeap()
   {
      // Converts the entire harr to minHeap
      int start = size / 2 - 1;
      n = size - 1;
      for (int idx = start; idx >= 0; idx--)
      {
         int i = idx;
         while (i <= n)
         {
            int j = 2 * i + 1;
            if (j + 1 <= n && harr[j + 1] < harr[j])
            {
               j++;
            }
            if (j <= n && harr[j] < harr[(j - 1) / 2])
            {
               // Child is smaller than parent
               swap(harr[j], harr[(j - 1) / 2]);
            }
            i = j;
         }
      }
   }
   int peekRoot()
   {
      if (n == -1)
      {
         return -1;
      }
      else
      {
         return harr[0];
      }
   }
   void deleteRoot()
   {
      if (n == -1)
      {
         return;
      }
      else if (n == 0)
      {
         n -= 1;
      }
      else
      {
         swap(harr[0], harr[n]);
         n--;
         int i = 0;
         while (i <= n)
         {
            int j = 2 * i + 1;
            if (j + 1 <= n && harr[j + 1] < harr[j])
            {
               j++;
            }
            if (j <= n && harr[j] < harr[(j - 1) / 2])
            {
               swap(harr[j], harr[(j - 1) / 2]);
            }
            i = j;
         }
      }
   }
   void insert(int value)
   {
      if (n == size - 1)
      {
         cout << "\nHeap is Full\n";
         return;
      }
      else
      {
         harr[++n] = value;
         int i = n;
         while (i > 0)
         {
            if (harr[i] < harr[(i - 1) / 2])
            {
               swap(harr[i], harr[(i - 1) / 2]);
            }
            i = (i - 1) / 2;
         }
      }
   }
   void sortKSorted(int arr[], int n, int k)
   {
      for (int i = 0; i <= k; i++)
      {
         insert(arr[i]);
      }
      for (int i = k + 1; i < n; i++)
      {
         cout << harr[0] << " ";
         deleteRoot();
         if (i < n)
         {
            insert(arr[i]);
         }
      }
      for (int i = 0; i <= k; i++)
      {
         cout << harr[0] << " ";
         deleteRoot();
      }
   }
   void showHeap()
   {
      for (int i = 0; i <= n; i++)
      {
         cout << harr[i] << " ";
      }
   }
};
long long int minCost(int arr[], int N)
{
   // Given an array containing length of N ropes
   // Find the minimum cost of joining the ropes
   // Where the cost of joining the ropes is equal to the sum of lenght of the ropes
   minHeap h;
   h.passArray(arr, N);
   h.arrayToHeap();
   long long int cost = 0;
   long long int b = 0;
   while (h.n != 0)
   {
      b = 0;
      b += h.harr[0];
      // Delete the root
      swap(h.harr[0], h.harr[h.n]);
      h.n--;
      // Push the root element down
      int i = 0;
      while (i <= h.n)
      {

         int j = 2 * i + 1;
         if (j + 1 <= h.n && h.harr[j + 1] < h.harr[j])
         {
            j++;
         }
         if (j <= h.n && h.harr[j] < h.harr[(j - 1) / 2])
         {
            swap(h.harr[j], h.harr[(j - 1) / 2]);
         }
         i = j;
      }
      b += h.harr[0];
      swap(h.harr[0], h.harr[h.n]);
      h.n--;
      i = 0;
      while (i <= h.n)
      {
         int j = 2 * i + 1;
         if (j + 1 <= h.n && h.harr[j + 1] < h.harr[j])
         {
            j++;
         }
         if (j <= h.n && h.harr[j] < h.harr[(j - 1) / 2])
         {
            swap(h.harr[j], h.harr[(j - 1) / 2]);
         }
         i = j;
      }
      cost += b;
      h.harr[++h.n] = b;
      i = h.n;
      while (i > 0)
      {
         if (h.harr[i] < h.harr[(i - 1) / 2])
         {
            swap(h.harr[i], h.harr[(i - 1) / 2]);
         }
         i = (i - 1) / 2;
      }
   }
   return cost;
}
int main()
{
   int arr[] = {3, 15, 5, 2, 16, 20};
   cout << minCost(arr, 6);
   return 0;
}