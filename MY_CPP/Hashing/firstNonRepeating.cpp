// Given an array of integers
// Find the first non repeating element in the array
#include <iostream>
#include <unordered_map>
using namespace std;
int firstNonRept(int arr[], int n)
{
   unordered_map<int, int> mp;
   for (int i = 0; i < n; i++)
   {
      mp[arr[i]]++;
   }
   for (int i = 0; i < n; i++)
   {
      if (mp[arr[i]] == 1)
      {
         return arr[i];
      }
   }
   return -1;
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
   cout << firstNonRept(arr, n);
   return 0;
}