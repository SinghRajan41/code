#include <iostream>
using namespace std;
void printLongestSubarray(int arr[], int n, int k)
{
   // Finds the longest subarray having not more than k distinct elements
   int freq[100001] = {0};
   for (int i = 0; i < n; i++)
   {
      freq[arr[i]]++;
   }
   int l = 0;
   int h = n - 1;
   int cur = 0;
   for (int i = 0; i < 100001; i++)
   {
      if (freq[i])
      {
         cur++;
      }
   }
   while (cur > k)
   {
      if (freq[arr[l]] < freq[arr[h]])
      {
         freq[arr[l]]--;
         l++;
         if (freq[arr[l - 1]] == 0)
         {
            cur--;
         }
      }
      else
      {
         freq[arr[h]]--;
         h--;
         if (freq[arr[h + 1]] == 0)
         {
            cur--;
         }
      }
   }
   for (int i = l; i <= h; i++)
   {
      cout << arr[i] << " ";
   }
}
void method2(int arr[], int n, int k)
{
   int start = 0, end = n - 1, l = 0, nod = 0;
   int freq[100001] = {0};
   int x = 0;
   for (int i = 0; i < n; i++)
   {
      freq[arr[i]]++;
      if (freq[arr[i]] == 1)
      {
         nod++;
      }
      while (nod > k)
      {
         freq[arr[l]]--;
         l++;
         if (freq[arr[l - 1]] == 0)
         {
            nod--;
         }
      }
      if (i - l < end - start && nod <= k && nod > x)
      {
         end = i;
         start = l;
         x = nod;
      }
   }
   for (int i = start; i <= end; i++)
   {
      cout << arr[i] << " ";
   }
}
int main()
{
   int n, k;
   cin >> n >> k;
   int arr[] = {6,
                5,
                1,
                2,
                3,
                2,
                1,
                4,
                5};
   method2(arr, n, k);
   return 0;
}