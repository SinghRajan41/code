#include<iostream>
using namespace std;
struct node
{
   int data;
   node *prev,*next;
};
class cdll
{
  node *first,*last,*temp,*a,*b,*c;
  public:
  cdll()
  {
     cout<<"Welcome to Circular Linked List Class\n";
     first=NULL;
  }
  void create_from_array(int *arr,int n);
  void display();
  void remove(int value);
  void dlt(int pos);
  int max();
  void reverse();
};
int main()
{
   cdll c;
   int arr[]={1,2,3,4,5,6};
   int n=sizeof(arr)/sizeof(arr[0]);
   c.create_from_array(arr,n);
   c.display();
   c.reverse();
   c.display();
   return 0;
}
void cdll::create_from_array(int *arr,int n)
{
   first=new node;
   first->prev=NULL;
   first->next=NULL;
   first->data = arr[0];
   last=first;
   if(n==1)
   {return;}
   for(int i=1;i<n;i++)
   {
      a=new node;
      a->next=NULL;
      a->data = arr[i];
      a->prev=last;
      last->next = a;
      last=a;
   }
   last->next = first;
   first->prev=last;
}

void cdll::display()
{
   a=first;
   do
   {
      cout<<a->data<<" ";
      a=a->next;
   } while (a != first);
   cout<<endl;
}

void cdll::remove(int value)
{
   if(first == NULL)
   {
      cout<<"Empty Linked List\n";
      return;
   }
   if(first->data == value)
   {
      if(first->next == first)
      {
         delete first;
         first=NULL;
         return;
      }
      else
      {
         a=first;
         first=first->next;
         first->prev=a->prev;
         a->prev->next = first;
         delete a;
         return;

      }
   }
   else
   {
      a=first;
      do
      {
         a=a->next;
      } while (a->data != value && a!=first);
      //Terminates when either a reaches first or data is found
      if(a!=first)
      {
      //Code for data found in between
      a->prev->next = a->next;
      a->next->prev = a->prev;
      delete a;
      return;
      }
   }
}
void cdll::dlt(int pos)
{
   if(first == NULL)
   {
      cout<<"Empty Circular Doubly Linked List\n";
      return;
   }
   if(pos == 0)
   {
      //Element Right at the first position
      if(first->next == first)
      {
         delete first;
         first=NULL;
      }
      else
      {
         a=first;
         first=first->next;
         first->prev = a->prev;
         a->prev->next = first;
         delete a;
         a=NULL;
         return;
      }
   }
   else
   {
      a=first;
      do
      {
         a=a->next;
      } while (a != first && pos--);
      if(a== first)
      {
         return;
      }
      else
      {
         a->prev->next = a->next;
         a->next->prev = a->prev;
         delete a;
         return;
      }
   }
}

int cdll::max()
{
   int m=-1111111;
   if(first == NULL)
   {
     cout<<"Empty";
     return -1;
   }
   a=first;
   do
   {
      m=m>a->data ? m:a->data;
      a=a->next;
   } while (a!=first);
   return m;
}

void cdll::reverse()
{
   a=first;
   do
   {
      c=a->next;
      b=a->prev;
      a->next=b;
      a->prev = c;
      a=a->next;
   } while (a != first);
   first=first->next;
}

