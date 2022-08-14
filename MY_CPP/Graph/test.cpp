#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> *adj;
int v, e;
void addNode(int x, int y);
bool s[10001];
void initialise();
void fillPrimes(vector<int> &primes);
bool compare(int a, int b);
void insertNode(int x, int y);
vector<int> primes;
int BFS(int x, int y)
{
   if (x == y)
   {
      return 0;
   }
   int visited[primes.size()] = {0};
   visited[x] = 1;
   queue<int> q;
   q.push(x);
   while (!q.empty())
   {
      int cur = q.front();
      q.pop();
      for (int i = 0; i < adj[cur].size(); i++)
      {
         if (visited[adj[cur][i]] == 0)
         {
            visited[adj[cur][i]] = visited[cur] + 1;
            q.push(adj[cur][i]);
         }
         if (adj[cur][i] == y)
         {
            return visited[adj[cur][i]] - 1;
         }
      }
   }
}
void bfs(int root)
{
   queue<int> q;
   bool visited[primes.size() + 1] = {0};
   q.push(root);
   while (!q.empty())
   {
      root = q.front();
      q.pop();
      if (visited[root] == 0)
      {
         cout << primes[root] << " ";
         visited[root] = 1;
      }
      for (int i = 0; i < adj[root].size(); i++)
      {
         if (visited[adj[root][i]] == 0)
         {
            q.push(adj[root][i]);
         }
      }
   }
}
int shortestPath(int a, int b)
{
   fillPrimes(primes);
   adj = new vector<int>[primes.size() + 1];
   for (int i = 0; i < primes.size(); i++)
   {
      for (int j = i + 1; j < primes.size(); j++)
      {
         if (compare(primes[i], primes[j]))
            insertNode(i, j);
      }
   }
   int x, y;
   for (int i = 0; i < primes.size(); i++)
   {
      if (primes[i] == a)
      {
         x = i;
         break;
      }
   }
   for (int i = 0; i < primes.size(); i++)
   {
      if (primes[i] == b)
      {
         y = i;
         break;
      }
   }
   // bfs(0);
   return BFS(x, y);
}
int main()
{
   initialise();
   int a, b;
   cin >> a >> b;
   cout << shortestPath(a, b);
   return 0;
}
void insertNode(int x, int y)
{
   adj[x].push_back(y);
   adj[y].push_back(x);
}
inline bool compare(int a, int b)
{
   int count = 0;
   while (a)
   {
      int x, y;
      x = a % 10;
      y = b % 10;
      count = (x != y) ? count + 1 : count;
      a /= 10;
      b /= 10;
   }
   return count == 1 ? true : false;
}
void fillPrimes(vector<int> &primes)
{
   for (int i = 1000; i < 10001; i++)
   {
      if (s[i] == 1)
      {
         primes.push_back(i);
      }
   }
}
void initialise()
{
   for (int i = 0; i < 10001; i++)
   {
      s[i] = 1;
   }
   for (int i = 2; i < 10001; i++)
   {
      if (s[i] == 1)
      {
         for (int j = i * i; j < 10001; j += i)
         {
            s[j] = 0;
         }
      }
   }
}