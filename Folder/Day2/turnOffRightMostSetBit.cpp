// Given an integer number as input
// Turn off the right most set bit
#include <iostream>
using namespace std;
int main()
{
   int n;
   cin >> n;
   cout << (n & (n - 1));
   return 0;
}