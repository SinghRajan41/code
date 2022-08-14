/*#include <iostream>
using namespace std;
void countSort(int arr[], int n);
void countSort(int arr[], int n)
{
   int M = arr[0];
   for (int i = 0; i < n; i++)
   {
      M = M > arr[i] ? M : arr[i];
   }
   int freq[M + 1] = {0};
   for (int i = 0; i < n; i++)
   {
      freq[arr[i]] += 1;
   }
   int k = 0;
   for (int i = 0; i <= M; i++)
   {
      if (freq[i])
      {
         while (freq[i]--)
         {
            arr[k++] = i;
         }
      }
   }
}
int main()
{
   int arr[100], n;
   for (int i = 100; i >= 1; i--)
   {
      arr[i - 1] = 100 - i;
   }
   n = sizeof(arr) / sizeof(arr[0]);
   countSort(arr, n);
   for (int i = 0; i < n; i++)
   {
      cout << arr[i] << " ";
   }
   return 0;
}*/
#include <iostream>
#include <vector>
using namespace std;
void countSort(vector<int> arr, int n)
{
   int m = INT32_MIN, k = 0;
   for (int i = 0; i < n; i++)
   {
      m = m > arr[i] ? m : arr[i];
   }
   vector<int> freq(m + 1, 0);
   for (int i = 0; i < n; i++)
   {
      freq[arr[i]]++;
   }
   for (int i = 0; i <= m; i++)
   {
      if (freq[i])
      {
         while (freq[i]--)
         {
            arr[k++] = i;
         }
      }
   }
}
int main()
{
   vector<int> arr;
   for (int i = 100; i > 0; i--)
   {
      arr.push_back(i);
   }
   countSort(arr, arr.size());
   for (int i = 0; i < arr.size(); i++)
   {
      cout << arr[i] << " ";
   }
   return 0;
}