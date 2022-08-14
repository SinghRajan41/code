#include<iostream>
using namespace std;

class stack_class
{
   int size,top,*s;
  public:
  stack_class()
  {top=-1;}
  stack_class(int x)
  {
     size=x;
     top=-1;
     s=new int[size];
  }
  void push(int value);
  int pop();
  int peek(int pos);
  int isEmpty();
  int isFull();
  void display();
  void displayr(int i=0);
};
//#######################################################################################
int main()
{
   int n;
   cout<<"Enter the size of stack=";
   cin>>n;
   
   stack_class obj(n);
   n+=2;
   for(int i=0;i<n;i++)
   {
      obj.push(i+1);
   }
   obj.displayr();

   return 0;
}

//######################################################################################
int stack_class::pop()
{
   if(top == -1)
   {
      cout<<"Stack is Empty \n";
      return -1;
   }
   else
   {
      int x=*(s + top--);
      return x;
   }
}
void stack_class::push(int value)
{
   if(top == size -1)
   {
      cout<<"Stack Overflow\n";
      return;
   }
   else
   {
      *(s + ++top) = value;
   }
}
void stack_class::display()
{
   if(top == -1)
   {
      cout<<"Stack is Empty\n";
      return;
   }
   for(int i=0;i<=top;i++)
   {
      cout<<*(s + i)<<" ";
   }
}
void stack_class::displayr(int i)
{
   if(i > top)
   {
      return;
   }
   cout<<*(s + i)<<" ";
   displayr(i+1);
 
}