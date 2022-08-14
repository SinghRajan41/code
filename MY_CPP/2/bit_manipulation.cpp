#include<iostream>
using namespace std;


int getBit(int n, int pos)
{
   if((n & (1<<pos))==0)
   {
      return 0;
   }
   else
   {
      return 1;
   }
}

int setBit(int n, int pos)
{
  return (n | (1<<pos));
}

int clearBit(int n,int pos)
{
   return n & (~(1<<pos));
}
/*int updateBit(int n, int pos,int value)
{
   int mask=~(1<<pos);
   n=n&mask;
   return (n|(value<<pos));
}*/
int updateBit(int n, int pos,int value)
{
   return n | (value<<pos);
}
int main()
{
   //Get Bit  n=0101
   int n=10;   //1010
   cout<<getBit(10,4);
   //cout<<setBit(8,1);
   //cout<<clearBit(10,3);


   //Update bit
   
   //cout<<updateBit(30,0,0);
    
   return 0;
}