//Write a recursive function to find the number of paths in maze board game of size n
#include<iostream>
#include<string>
using namespace std;
int board(int n,int i,int j)
{
   if(i==n-1 && j==n-1)
   {
      return 1;
   }
   if(i>=n || j>=n)
   {
      return 0;
   }
   return board(n,i+1,j)+board(n,i,j+1);
}
int main()
{
   cout<<board(3,0,0);
   return 0;
}