#include<bits/stdc++.h>
using namespace std;
const int SIZE=15;
class setup
{
   int *arr=new int[SIZE];
   int top;

   public:
   setup(){top=0;}
   void push(int value)
   {
      if(top==SIZE)
      {
         cout<<"Stack Overflow\n";
         return;
      }
      else
      {
         arr[top++]=value;
      }
   }
   void pop()
   {
      if(top==0)
      {
         cout<<"Stack is empty\n";
         return;
      }
      else
      {
         top--;
      }
   }
   void show()
   {
      for(int i=0;i<top;i++)
      {
         cout<<arr[i]<<" ";
      }
   }
   int &operator[](int i)
   {
      return arr[i];
   }

   void operator+(int value)
   {
      if(top==SIZE)
      {
         cout<<"Stack OverFlow\n";
         return;
      }
      else
      {
         arr[top++]=value;
      }
   }
   void operator--()
   {
      if(top==0)
      {
         cout<<"Stack is Empty\n";
         return;
      }
      else
      {
         top-=1;
      }
   }
   void operator--(int x)
   {
      if(top==0)
      {
         cout<<"Stack is empty\n";
         return;
      }
      else
      {
         top-=1;
      }
   }

};

int main()
{
   setup s;
   for(int i=0;i<SIZE;i++)
   {
      s+(i+1);
   }
   int n=9;
   for(;n;n--)
   {
      s--;
   }
   s.show();
}