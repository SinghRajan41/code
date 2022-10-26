/*
Suppose you are given a number n, which represents the length of a road. The road has n plots on each side.
The road is to be so planned that there should not be consecutive buildings on either side of the road.
You are required to find and print the number of ways in which the buildings can be built on both sides of roads.
*/
#include <iostream>
using namespace std;
long long int count(int n);
int main()
{
   int n;
   cin >> n;
   cout << count(n);
   return 0;
}
long long int count(int n)
{
   long long int build[n + 1];
   long long int space[n + 1];
   build[1] = space[1] = 1;
   for (int i = 2; i <= n; i++)
   {
      build[i] = space[i - 1];
      space[i] = build[i - 1] + space[i - 1];
   }
   return (space[n] + build[n]) * (space[n] + build[n]);
}