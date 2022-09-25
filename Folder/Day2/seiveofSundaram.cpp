#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
   int n;
   cin >> n;
   // Generating seive of sundaram for printing prime numbers upto n
   int nNew = (n - 1) / 2;
   bool seive[nNew + 1];
   memset(seive, 0, sizeof(seive));
   for (int i = 1; i <= nNew; i++)
   {
      for (int j = i; i + j + 2 * i * j <= nNew; j++)
      {
         seive[i + j + 2 * i * j] = true;
      }
   }
   if (n > 2)
   {
      cout << 2 << " ";
   }
   for (int i = 1; i <= nNew; i++)
   {
      if (!seive[i])
      {
         cout << 2 * i + 1 << " ";
      }
   }
   return 0;
}