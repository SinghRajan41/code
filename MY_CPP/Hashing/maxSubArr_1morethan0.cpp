// Given an array of zeros and ones
// Find the lenght of the largest subarray having more than ones than 0s
#include <iostream>
#include <unordered_map>
using namespace std;
int findLargest(int arr[], int n)
{
   for (int i = 0; i < n; i++)
   {
      if (arr[i] == 0)
      {
         arr[i] = -1;
      }
   }
   unordered_map<int, int> map;
   int curSum = 0;
   int Max = 0;
   for (int i = 0; i < n; i++)
   {
      curSum += arr[i];
      if (curSum == 1)
      {
         Max = Max > i + 1 ? Max : i + 1;
      }
      if (map.find(curSum) == map.end())
      {
         map[curSum] = i;
      }
      if (map.find(curSum - 1) != map.end())
      {
         Max = Max > map[curSum - 1] ? Max : map[curSum - 1];
      }
      }
   return Max;
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
   cout << findLargest(arr, n);
   return 0;
}