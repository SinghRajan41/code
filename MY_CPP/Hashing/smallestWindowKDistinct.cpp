// Given an array of integers
// Fidnt the smallest window containing exactly K distinct elements
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;
void smallestWindow(int arr[], int n, int k)
{
   int start = 0, end = n;
   for (int i = 0; i < n; i++)
   {
      int j;
      unordered_set<int> s;
      for (j = i; j < n; j++)
      {
         s.insert(arr[j]);
         if (s.size() == k)
         {
            if (j - i < end - start)
            {
               start = i;
               end = j;
            }
            break;
         }
      }
   }
   if (start == 0 && end == n)
   {
      cout << "\nInvalid K";
   }
   else
   {
      for (int i = start; i <= end; i++)
      {
         cout << arr[i] << " ";
      }
   }
}
void smallestWindow2(int arr[], int n, int k)
{
   unordered_map<int, int> map;
   int j = 0, i = 0, start = 0, end = n;
   while (j < n)
   {
      map[arr[j]]++;
      j++;
      if (map.size() < k)
      {
         continue;
      }
      while (map.size() == k)
      {
         if (end - start + 1 > (j - 1) - i + 1)
         {
            start = i;
            end = j - 1;
         }
         if (map[arr[i]] == 1)
         {
            map.erase(arr[i]);
         }
         else
         {
            map[arr[i]]--;
         }
         i++;
      }
   }
   if (start == 0 && end == n)
   {
      cout << "\nInvalid K";
   }
   else
   {
      for (int i = start; i <= end; i++)
      {
         cout << arr[i] << " ";
      }
   }
}
void test(int arr[], int n)
{
   vector<int> a, b;
   unordered_map<int, int> map;
   for (int i = 0; i < n; i++)
   {
      map[arr[i]]++;
   }
   for (int i = 0; i < n; i++)
   {
      if (map[arr[i]] == 2)
      {
         a.push_back(arr[i]);
         b.push_back(arr[i]);
         map[arr[i]] = 0;
      }
      else if (map[arr[i]] == 1)
      {
         if (arr[i] > 0)
         {
            a.push_back(arr[i]);
         }
         else
         {
            b.push_back(arr[i]);
         }
         map[arr[i]] = 0;
      }
   }
   long long int asum = 0, bsum = 0;
   for (int i = 0; i < a.size(); i++)
   {
      asum += a[i];
   }
   cout << endl;
   for (int i = 0; i < b.size(); i++)
   {
      bsum += b[i];
   }
   cout << asum - bsum;
}
int main()
{
   int arr[] = {4, 2, -3, 3, -2, -2, 8};
   int n = sizeof(arr) / sizeof(arr[0]);
   test(arr, n);
   return 0;
}