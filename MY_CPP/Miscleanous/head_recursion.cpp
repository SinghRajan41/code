#include<iostream>
using namespace std;
void f(int n)
{
if(n>0)
{
   f(n-1);
   cout<<n<<" ";
}
}
int main()
{
   //In head recursion, Function call is made right at the beginning of the 
   //the function
   //Head recursion cannot be simply converted into a loop like tail recursion
   //All loops can be converted into tail recursion
   int n=5;
   f(n);
   return 0;
}