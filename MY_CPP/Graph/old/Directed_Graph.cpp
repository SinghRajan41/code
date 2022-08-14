#include <iostream>
using namespace std;
class dgraph
{
   bool **g = NULL;
   int size;

public:
   dgraph(int n)
   {
      size = n;
      g = new bool *[n + 1];
      for (int i = 0; i <= n; i++)
      {
         g[i] = new bool[n + 1];
         for (int j = 0; j <= n; j++)
         {
            g[i][j] = 0;
         }
      }
   }
   void graphInput();
   void inwardDisplay();
   void outwardDisplay();
};
void dgraph::outwardDisplay()
{
   for (int i = 1; i <= size; i++)
   {
      cout << i << "-> ";
      for (int j = 1; j <= size; j++)
      {
         if (g[i][j] == 1)
         {
            cout << j << " ";
         }
      }
      cout << endl;
   }
}
void dgraph::inwardDisplay()
{
   for (int i = 1; i <= size; i++)
   {
      cout << i << "-> ";
      for (int j = 1; j <= size; j++)
      {
         if (g[j][i] == 1)
         {
            cout << j << " ";
         }
      }
      cout << endl;
   }
}
void dgraph::graphInput()
{
   int temp;
   for (int i = 1; i <= size; i++)
   {
      cin >> temp;
      while (temp != -1)
      {
         g[i][temp] = 1;
         cin >> temp;
      }
   }
}
int main()
{
   int n;
   cin >> n;
   dgraph g(n);
   g.graphInput();
   g.inwardDisplay();
   g.outwardDisplay();
   return 0;
}