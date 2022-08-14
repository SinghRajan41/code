#include <iostream>
#include <vector>
using namespace std;
int **g;
void initialise(int n)
{
   g = new int *[n + 1];
   for (int i = 0; i <= n; i++)
   {
      g[i] = new int[n + 1];
   }
   for (int i = 0; i <= n; i++)
   {
      for (int j = 0; j <= n; j++)
      {
         g[i][j] = -1;
      }
   }
}
void displayGraph(int n)
{
   for (int i = 1; i <= n; i++)
   {
      for (int j = 1; j <= n; j++)
      {
         cout << g[i][j] << " ";
      }
      cout << endl;
   }
}
void inputGraph(int n)
{
   int a, b;
   for (int i = 1; i <= n; i++)
   {
      vector<int> q, w;
      cin >> a >> b;
      while (a != -1)
      {
         q.push_back(a);
         w.push_back(b);
         cin >> a >> b;
      }
      for (int j = 0; j <= q.size(); j++)
      {
         g[i][q[j]] = w[j];
      }
   }
}
int main()
{
   int n;
   cin >> n;
   initialise(n);
   inputGraph(n);
   displayGraph(n);
   return 0;
}