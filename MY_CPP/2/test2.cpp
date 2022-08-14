#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main()
{
   unordered_map<int, int> h;
   for (int i = 0; i < 11; i++)
   {
      cout << h[i] << endl;
   }
   return 0;
}