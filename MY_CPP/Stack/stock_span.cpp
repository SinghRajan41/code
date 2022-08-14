#include <iostream>
#include <stack>
#include <vector>
using namespace std;
void stockSpan(int arr[], int n)
{
   stack<int> s;
   s.push(0);
   vector<int> res;
   res.push_back(1);
   for (int i = 1; i < n; i++)
   {
      while (!s.empty() && (arr[i] >= arr[s.top()]))
      {
         s.pop();
      }
      res.push_back(s.empty() ? (i + 1) : (i - s.top()));
      s.push(i);
   }
   for (vector<int>::iterator i = res.begin(); i != res.end(); i++)
   {
      cout << *i << " ";
   }
}
int main()
{
   int arr[8] = {11, 23, 54, 12, 65, 87, 45, 33};
   stockSpan(arr, 8);
   return 0;
}