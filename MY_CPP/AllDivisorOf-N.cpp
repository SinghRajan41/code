#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
   long long int n;
   cin >> n;
   int x = sqrt(n);
   vector<int> f;
   for (int i = 1; i <= x; i++)
   {
      if (n % i == 0)
      {
         f.push_back(i);
      }
   }
   // Factors upto sqrt(n) are stored in a vector
   for (int i = 0; i < f.size(); i++)
   {
      // cout << f[i] << " ";
   }
   vector<int> temp;
   for (int i = f.size() - 1; i > -1; --i)
   {
      if (n / f[i] == f[i])
      {
         continue;
      }
      else
      {
         temp.push_back(n / f[i]);
      }
   }
   cout << temp[31];

   return 0;
}
