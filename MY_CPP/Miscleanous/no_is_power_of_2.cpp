#include<iostream>
using namespace std;


int ispower2(int n)
{
   return (n && (!(n & (n-1))));
}
int main()
{
   int n=16;
   cout<<ispower2(n);
   return 0;
}