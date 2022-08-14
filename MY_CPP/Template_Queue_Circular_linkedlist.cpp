#include<iostream>
#include<iomanip>
using namespace std;
template<class X>class node
{
   public:
   X data;
   node *next;
};
template<class Y>class queue
{
   int size;
   node<Y> *head,*first,*last,*a,*b;
   public:
   queue()
   {
      first=NULL;last=NULL;
      //cout<<"Enter the size of the queue=";
      size=100;
      head=new node<Y>;
      head->data = 0;
      head->next=NULL;
      a=head;
      size-=1;
      for(int i=0;i<size;i++)
      {
      b=new node<Y>;
      b->next=NULL;
      a->next=b;
      a=b;
      }
      a->next=head;
   }
   int iscircular()
   {
      a=head;b=head;
      do
      {
         a=a->next;
         b=b->next;
         b=b->next;
      } while (a!=NULL && b!=NULL && a!=b);
      if(a==b && a!=NULL)
      {
         cout<<"\nCircular";
      }
      else
      {
         cout<<"\nLinear";
      }
   }
   void enqueue(int value)
   {
      if(first ==NULL)
      {
         first=head;
         last=head;
         first->data=value;
      }
      else if(last->next == first)
      {
         cout<<"Queue is full\n";
         return;
      }
      else
      {
         last=last->next;
         last->data=value;
      }
   }
   void dequeue()
   {
      if(first==NULL)
      {
         cout<<"\nQueue is already empty\n";
         return;
      }
      else if(first!=NULL && first==last)
      {
         first=NULL;last=NULL;
      }
      else
      {
         first=first->next;
      }
   }
   void display()
   {
      if(first==NULL)
      {
         cout<<"\nQueue is already empty\n";
         return;
      }
      else if(first==last)
      {
         cout<<first->data;return;
      }
      else
      {
         a=first;
         cout<<a->data<<" ";
         do
         {
            a=a->next;
            cout<<setprecision(5)<<a->data<<" ";
         } while (a!= last);
      }
   }
};

int main()
{
   queue<double> q;
   for(int i=0;i<10;i++)
   {
      q.enqueue(21.23);
   }
   q.display();
   for(int i=0;i<10;i++)
   {
      q.dequeue();
   }
   return 0;
}







