// Given an array of 0s and 1s
// Find the length of the largest subarray containing equal number of zeroes and ones
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
void printLargest(int arr[], int n)
{
   int start = 0, end = 0;
   for (int i = 0; i < n; i++)
   {
      int zero = 0, one = 0;
      for (int j = i; j < n; j++)
      {
         if (arr[j] == 0)
         {
            zero++;
         }
         else
         {
            one++;
         }
         if (zero == one)
         {
            if (j - i > end - start)
            {
               start = i;
               end = j;
            }
         }
      }
   }
   cout << start << " " << end << endl;
   for (int i = start; i <= end; i++)
   {
      cout << arr[i] << " ";
   }
}
int lenLargest(int arr[], int n)
{
   vector<pair<int, int>> res;
   unordered_map<int, vector<int>> map;
   int curSum = 0;
   for (int i = 0; i < n; i++)
   {
      if (arr[i] == 0)
      {
         arr[i] = -1;
      }
   }
   for (int i = 0; i < n; i++)
   {
      curSum += arr[i];
      if (curSum == 0)
      {
         res.push_back(make_pair(0, i));
      }
      if (map.find(curSum) != map.end())
      {
         vector<int> temp = map[curSum];
         for (int j = 0; j < temp.size(); j++)
         {
            res.push_back(make_pair(temp[j] + 1, i));
         }
      }
      map[curSum].push_back(i);
   }
   int Max = -1;
   for (int i = 0; i < res.size(); i++)
   {
      int a = res[i].first;
      int b = res[i].second;
      Max = Max > b - a + 1 ? Max : b - a + 1;
   }
   return Max;
}
int countTotal(int arr[], int n)
{
   // Counts the total number of subarrays having equal number of 0s and 1s
   int count = 0, curSum = 0;
   unordered_map<int, int> map;
   for (int i = 0; i < n; i++)
   {
      if (arr[i] == 0)
      {
         arr[i] = -1;
      }
   }
   for (int i = 0; i < n; i++)
   {
      curSum += arr[i];
      if (curSum == 0)
      {
         count++;
      }
      if (map.find(curSum) != map.end())
      {
         count += map[curSum];
      }
      map[curSum]++;
   }
   return count;
}
int main()
{
   int n;
   cin >> n;
   int arr[n];
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }
   cout << countTotal(arr, n);
   return 0;
}