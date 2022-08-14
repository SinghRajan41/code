#include<iostream>
#include<string>
#define ANS &&
using namespace std;
struct node
{
   int data;
   node *prev,*next;
};
class dll
{
   node *first,*last,*a,*b,*c,*temp;
   public:
   dll()
   {cout<<"Welcome to Doubly Linked List Class\n";
      first=NULL;last=NULL;
   }
   void create_from_array(int arr[],int n);
   void display();
   void insert(int pos,int val);
   void dlt(int pos);
   void remove(int value);
   void reverse();
};
void dll::reverse()
{
   if(first == NULL)
   {
      return;
   }
   else if(first->next == NULL)
   {
      return;
   }
   else
   {
      a=first;
      while(a!=NULL)
      {
         b=a->next;
         a->next=a->prev;
         a->prev=b;
         first=a;
         a=b;
      }
   }
}


int main()
{
   dll d;
   int arr[10]={1,2,3,4,5,6,7,8,9};
   d.create_from_array(arr,9);
   d.display();
   //d.insert(12,10);
   d.reverse();
   d.display();
   

   return 0;
}

void dll::remove(int value)
{
   if(first==NULL)
   {
      cout<<"Empty Doubly Linked List";
      return;
   }
   //Present at first
   if(first->data == value)
   {
      //1 size
      if(first->next == NULL)
      {
         delete first;
         first=NULL;a=NULL;
         return;
      }
      else
      {
         a=first;
         first=first->next;
         first->prev=NULL;
         delete a;a=NULL;return;
      }
   }
   else
   {
      a=first;
      while(a->data != value && a)
      {
         a=a->next;
      }
      if(a)
      {
      //If element in between and the last node
      a->prev->next = a->next;
      if(a->next)
      {a->next->prev = a->prev;}
      delete a;
      }
   }
}
void dll::create_from_array(int arr[],int n)
{
   first=new node;
   first->next=NULL;
   first->prev=NULL;
   first->data=arr[0];
   last=first;
   for(int i=1;i<n;i++)
   {
      a=new node;
      a->next=NULL;
      a->data=arr[i];
      a->prev=last;
      last->next=a;
      last=a;
   }
}
void dll::display()
{
   a=first;
   if(a==NULL){return;}
   a=first;
   while(a!=NULL)
   {
      cout<<a->data<<" ";
      a=a->next;
   }
   cout<<endl;
}
void dll::insert(int pos,int val)
{
   if(pos==0)
   {
      a=new node;
      a->prev=NULL;
      a->data=val;
      a->next=first;
      first->prev=a;
      first=a;
      return;
   }
   else
   {
      
      a=first;
      c=first;
      while(a && pos--)
      {
         c=a;
         a=a->next;
      }
      b=new node;
      b->data=val;
      if(a)
      {
      b->prev=a->prev;
      b->next=a;
      a->prev->next = b;
      a->prev=b;
      }
      else
      {
        b->next=NULL;
        b->prev=c;
        c->next=b;
      }
   }
}
void dll::dlt(int pos)
{
   if(first==NULL)
   {
      cout<<"Empty Doubly Linked List";
      return;
   }
   if(pos==0 && first->next==NULL)
   {
      delete first;
      first=NULL;
   }
  if(pos == 0)
  {
     a=first;
     first=first->next;
     first->prev=NULL;
     delete a;
     return;
  }
  a=first;
  b=first;
  while(pos-- ANS a)
  {
   b=a;
   a=a->next;
  }
  if(!a)
  {return;}
  else
  {
     if(a->next)
     {
        b->next=a->next;
        a->next->prev=b;
        delete a;
     }
     else
     {
        b->next=NULL;
        delete a;
     }
  }
  
}