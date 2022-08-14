#include <iostream>
using namespace std;
struct node
{
   int
} class graph
{
   int **g, size;
   bool *visited;

public:
   graph(int n)
   {
      this->size = n;
      g = new int *[n + 1];
      for (int i = 0; i <= n; i++)
      {
         g[i] = new int[n + 1];
      }
      for (int i = 0; i <= n; i++)
      {
         for (int j = 0; j <= n; j++)
         {
            g[i][j] = 0;
         }
      }
      visited = new bool[n + 1];
      for (int i = 0; i <= n; i++)
      {
         visited[i] = 0;
      }
   }
   void graphInput(int n, int m);
   void graphDisplay();
};
int main()
{
   cout << "rajan";
   return 0;
}
