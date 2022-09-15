#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int lowerBound(vector<int> &arr, int key)
{
   int low = 0;
   int high = arr.size() - 1;
   int res = -1;
   while (low <= high)
   {
      int mid = (low + high) / 2;
      if (arr[mid] <= key && arr[mid] > res)
      {
         res = arr[mid];
         low = mid + 1;
      }
      else
      {
         if (key > arr[mid])
         {
            low = mid + 1;
         }
         else
         {
            high = mid - 1;
         }
      }
   }
   return res;
}
int upperBound(vector<int> &arr, int key)
{
   int res = -1;
   int low = 0;
   int high = arr.size() - 1;
   while (low <= high)
   {
      int mid = (low + high) / 2;
      if (arr[mid] >= key && arr[mid] < res)
      {
         res = arr[mid];
         high = mid - 1;
      }
      else
      {
         if (key > arr[mid])
         {
            low = mid + 1;
         }
         else
         {
            high = mid - 1;
         }
      }
   }
   return res;
}
int main()
{
   int n;
   cin >> n;
   vector<int> arr;
   for (int i = 0; i < n; i++)
   {
      int temp;
      cin >> temp;
      arr.push_back(temp);
   }
   sort(arr.begin(), arr.end());
   int key;
   cin >> key;
   cout << lowerBound(arr, key);
   return 0;
}
/*int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n, m;
      cin >> n >> m;
      int arr[n + 1], dest[m];
      for (int i = 1; i <= n; i++)
      {
         cin >> arr[i];
      }
      for (int i = 0; i < m; i++)
      {
         cin >> dest[i];
      }
      vector<int> ones, twos;
      sort(ones.begin(), ones.end());
      sort(twos.begin(), twos.end());
      for (int i = 1; i <= n; i++)
      {
         if (arr[i] == 1)
         {
            ones.push_back(i);
         }
         if (arr[i] == 2)
         {
            twos.push_back(i);
         }
      }
      for (int i = 0; i < m; i++)
      {
         if (dest[i] == 1 || arr[dest[i]] != 0)
         {
            cout << 0 << "a ";
         }
         else
         {
            int lb, ub;
            lb = lowerBound(ones, dest[i]);
            ub = upperBound(twos, dest[i]);
            if (ub == -1 && lb == -1)
            {
               cout << -1 << "b ";
            }
            else if (ub == -1 || lb == -1)
            {
               if (ub == -1)
               {
                  cout << dest[i] - lb << "c ";
               }
               else
               {
                  cout << ub - dest[i] << "d ";
               }
            }
            else
            {
               cout << min(dest[i] - lb, ub - dest[i]) << " ";
            }
         }
      }
      cout << endl;
   }
   return 0;
}*/