#include<iostream>
#include<iomanip>
using namespace std;
template<class X> class node
{
   public:
   X data;
   node *next;
};
template<class Y> class queue
{
  node<Y> *first,*head,*last,*a,*b;
  public:
  queue()
  {
     first=NULL;
     last=NULL;
  }
  void nq(Y value);
  void dq();
  void display();
};
template<class Y> void queue<Y>::nq(Y value)
{
 a=new node<Y>;
 a->data=value;
 if(first==NULL)
 {
    first=a;
    last=a;
    return;
 } 
 else
 {
  last->next=a;
  last=a;
 } 
}
template<class Y> void queue<Y>::dq()
{
   if(first==NULL)
   {
      cout<<"\nQueue is already empty\nReturning from DQ function\n";
      return;
   }
   else if(first!=NULL && first==last)
   {
      delete first;
      first=NULL;
      last=NULL;
   }
   else
   {
     a=first;
     first=first->next;
     delete a;
   }
}
template<class Y> void queue<Y>::display()
{
   if(first==NULL){
      cout<<"\nQueue is empty\nReturning from display function\n";
      return;
   }
   else
   {
      a=first;
      cout<<a->data<<" ";
      a=a->next;
      while(a!=NULL)
      {
         cout<<a->data<<" ";
         a=a->next;
      }
   }
}

int main()
{
   queue<int> q;
   for(int i=0;i<100;i++)
   {
      q.nq(i+1);
   }
   for(int i=0;i<33;i++)
   {
      q.dq();
   }
   q.display();
   return 0;
}