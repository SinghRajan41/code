#include <iostream>
#include <vector>
using namespace std;
int hashfunction(int &x)
{
   return x % 10;
}
int main()
{
   vector<int> keys;
   for (int i = 1; i < 10; i++)
   {
      keys.push_back(i);
   }
   vector<int> hash_table(10, -1);
   for (int i = 0; i < keys.size(); i++)
   {
      hash_table[hashfunction(keys[i])] = keys[i];
   }
   for (int i = 0; i < keys.size(); i++)
   {
      cout << hash_table[hashfunction(keys[i])] << " ";
   }
   return 0;
}
