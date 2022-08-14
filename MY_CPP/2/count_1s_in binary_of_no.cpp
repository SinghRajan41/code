#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n=19;
   int count=0;
   cout<<count;
   while(n)
   {
    count++;
    n=n&(n-1);
   }
   cout<<count;
   return 0;
}