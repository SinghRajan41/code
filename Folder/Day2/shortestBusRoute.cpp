#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
int shortestRoute(vector<int> busCity[], int b, int c, int src, int dest);
struct item
{
   int bus;
   int level;
};
int main()
{
   int b, c;
   cin >> b >> c;
   vector<int> busCity[b];
   for (int i = 0; i < b; i++)
   {
      int n;
      cin >> n;
      for (int j = 0; j < n; j++)
      {
         int temp;
         cin >> temp;
         busCity[i].push_back(temp);
      }
   }
   int src, dest;
   cin >> src >> dest;
   cout << shortestRoute(busCity, b, c, src, dest);
   return 0;
}
int shortestRoute(vector<int> busCity[], int b, int c, int src, int dest)
{
   queue<item> q;
   vector<int> cityBus[c + 1];

   for (int i = 0; i < b; i++)
   {
      for (int j = 0; j < busCity[i].size(); j++)
      {
         // city is busCity[i][j]
         cityBus[busCity[i][j]].push_back(i);
      }
      cout << endl;
   }
   /*for (int i = 1; i <= c; i++)
   {
      cout << i << " -> ";
      for (auto a : cityBus[i])
      {
         cout << a << " ";
      }
      cout << endl;
   }*/
   unordered_map<int, bool> boarded;
   for (int i = 0; i < b; i++)
   {
      boarded[i] = false;
   }

   for (int i = 0; i < cityBus[src].size(); i++)
   {
      item temp = {cityBus[src][i], 0};
      q.push(temp);
      boarded[cityBus[src][i]] = true;
   }

   while (!q.empty())
   {
      item cur = q.front();
      q.pop();
      int bus = cur.bus;
      for (int i = 0; i < busCity[bus].size(); i++)
      {
         if (busCity[bus][i] == dest)
         {
            return cur.level + 1;
         }
         else
         {
            int city = busCity[bus][i];
            // Find all the unboarded buses and board them
            for (int j = 0; j < cityBus[city].size(); j++)
            {
               if (!boarded[cityBus[city][j]])
               {
                  item temp = {cityBus[city][j], cur.level + 1};
                  q.push(temp);
                  boarded[temp.bus] = true;
               }
            }
         }
      }
   }
   cout << "\nLol";
   return -1;
}