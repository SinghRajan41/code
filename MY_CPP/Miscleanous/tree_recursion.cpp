#include<iostream>
using namespace std;
void f(int n)
{
   if(n>0)
   {
      cout<<n<<" ";
      
      
         f(n-1);f(n-1);
      
   }
}
int main()
{
   //Time Complexity  O(2^n) for this function
   //Space complexity depends on maximum height of the tree from top to bottom
   //Space required is the height of the tree
   //Space complexity is O(n)
   int n=3;
   f(4);
   return 0;
}