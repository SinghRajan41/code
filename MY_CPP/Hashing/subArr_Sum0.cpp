// Find a subarray with sum 0
// Lenght 1 valid
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
int a, b;
bool sub0Exists(int arr[], int n)
{
   for (int i = 0; i < n - 1; i++)
   {
      long long int sum = 0;
      for (int j = i; j < n; j++)
      {
         sum += arr[j];
         if (sum == 0)
         {
            a = i;
            b = j;
            return true;
         }
      }
   }
   return false;
}
void printSubArr0(int arr[], int n)
{
   for (int i = 0; i < n; i++)
   {
      int sum = 0;
      for (int j = i; j < n; j++)
      {
         sum += arr[j];
         if (sum == 0)
         {
            for (int k = i; k <= j; k++)
            {
               cout << arr[k] << " ";
            }
            cout << endl;
         }
      }
   }
}
void test(int arr[], int n)
{
   int sum = 0;
   vector<pair<int, int>> res;
   unordered_map<int, vector<int>> map;
   for (int i = 0; i < n; i++)
   {
      sum += arr[i];
      if (sum == 0)
      {
         res.push_back(make_pair(0, i));
      }
      if (map.find(sum) != map.end())
      {
         vector<int> temp = map[sum];
         for (int j = 0; j < temp.size(); j++)
         {
            res.push_back(make_pair(temp[j] + 1, i));
         }
      }
      map[sum].push_back(i);
   }
   for (int i = 0; i < res.size(); i++)
   {
      int a = res[i].first;
      int b = res[i].second;
      while (a <= b)
      {
         cout << arr[a++] << " ";
      }
      cout << endl;
   }
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
   test(arr, n);
   return 0;
}