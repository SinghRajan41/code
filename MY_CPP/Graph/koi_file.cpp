#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
int main()
{
   vector<int> arr(10, 0);
   for (int i = 0; i < 10; i++)
   {
      arr[i] = i + 21;
   }
   arr.erase(arr.begin());
   cout << arr[0] << " ";
   return 0;
}