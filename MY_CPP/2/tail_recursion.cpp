#include<iostream>
using namespace std;
int tail(int n)
{
   if(n>0)
   {
    cout<<n<<" ";
    tail(n-1);  
   }

}
int main()
{
   //In tail recursion function call is made only at the end of the function after doing all the processing
   //While the function starts returning or starts coming back like a stretched rubber band, it doesn't have to perform any operation
   //the function simply keeps returning one by one 
   //Tail recursion can be converted easily into loops  
   //recursion time complexity O(n)  space complexity O(n)
   //Loop time complexity   O(n) space complexity O(1)

   int n=5;
   tail(n);
   while(n)
   {
      cout<<n--<<" ";
   }
   return 0;
}