#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
// Given an unsorted array
// Find the minimum number of swaps needed to swap the array
int minSwap(vector<pair<int, int>> &arr, int n);
void dfs(vector<pair<int, int>> &arr, int i, int &x, bool visited[]);
bool cmp(pair<int, int> a, pair<int, int> b)
{
   return a.first < b.first;
}
int main()
{
   int n;
   cin >> n;
   vector<pair<int, int>> arr;
   for (int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      arr.push_back(make_pair(x, i));
   }
   cout << minSwap(arr, n);
   return 0;
}
int minSwap(vector<pair<int, int>> &arr, int n)
{
   bool visited[n];
   memset(visited, false, n);
   sort(arr.begin(), arr.end(), cmp);
   int count = 0;
   for (int i = 0; i < n; i++)
   {
      if (arr[i].second != i && !visited[i])
      {
         int x = 0;
         dfs(arr, i, x, visited);
         count += (x - 1);
      }
   }
   return count;
}
void dfs(vector<pair<int, int>> &arr, int i, int &x, bool visited[])
{
   if (!visited[i])
   {
      visited[i] = true;
      x++;
      dfs(arr, arr[i].second, x, visited);
   }
}