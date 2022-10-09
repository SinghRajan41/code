/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

*/
#include <iostream>
#include <vector>
using namespace std;
int minCost(vector<int> cost);
int _minCost(vector<int> &cost, int mem[], int src, int dest);
int main()
{
   int n;
   cin >> n;
   vector<int> cost(n, 0);
   for (int i = 0; i < n; i++)
   {
      cin >> cost[i];
   }
   cout << minCost(cost);
   return 0;
}
int _minCost(vector<int> &cost, int mem[], int src, int dest)
{
   if (src >= dest)
   {
      return 0;
   }
   else
   {
      if (mem[src] == -1)
      {
         int a = _minCost(cost, mem, src + 1, dest);
         int b = _minCost(cost, mem, src + 2, dest);
         mem[src] = min(a, b) + cost[src];
      }
      return mem[src];
   }
}
int minCost(vector<int> cost)
{
   int dest = cost.size();
   int mem[dest];
   for (int i = 0; i < dest; i++)
   {
      mem[i] = -1;
   }
   int a = _minCost(cost, mem, 0, dest);
   for (int i = 0; i < dest; i++)
   {
      mem[i] = -1;
   }
   int b = _minCost(cost, mem, 1, dest);
   return min(a, b);
}