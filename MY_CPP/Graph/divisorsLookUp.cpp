// Create a lookup table that gives sum of divisors of a numbers
// Create a lookup table that gives count of divisors of a number
// Create a lookup table that gives all the divisors of a number
#include <iostream>
#include <vector>
using namespace std;
void initCount(int count[], int n);
void initSum(int sum[], int n);
void initDiv(vector<int> div[], int n);
int main()
{
   const int n = 1e5 + 10;
   int count[n];
   int sum[n];
   vector<int> div[n];
   initCount(count, n);
   initSum(sum, n);
   initDiv(div, n);
   for (int z = 1; z < 1000; z++)
   {
      for (int i = 0; i < div[z].size(); i++)
      {
         cout << z << "\t";
         cout << div[z][i] << " ";
      }
      cout << endl;
   }
   int x;
   cin >> x;
   return 0;
}
void initSum(int sum[], int n)
{
   for (int i = 0; i < n; i++)
   {
      sum[i] = 0;
   }
   for (int i = 1; i < n; i++)
   {
      for (int j = i; j < n; j += i)
      {
         sum[j] += i;
      }
   }
}
void initDiv(vector<int> div[], int n)
{
   for (int i = 1; i < n; i++)
   {
      for (int j = i; j < n; j += i)
      {
         div[j].push_back(i);
      }
   }
}
void initCount(int count[], int n)
{
   for (int i = 0; i < n; i++)
   {
      count[i] = 0;
   }
   for (int i = 1; i < n; i++)
   {
      for (int j = i; j < n; j += i)
      {
         count[j]++;
      }
   }
}