#include<iostream>
using namespace std;
struct node
{
   int data;
   node *next;
};
class circular
{
   node *head,*a,*b,*c,*temp;
   public:
   circular()
   {
      head=NULL;
      cout<<"Welcome to Circular Linked List Class!\n";
   }
   void create();
   void display();
   void create_from_array(int *arr,int n);
   void insert(int pos,int value);
   void dlt(int key);
   int max();
};


//######################################################
int main()
{
circular c;
int arr[]={1,2,3,4,5};
c.create_from_array(arr,5);
cout<<endl;
cout<<c.max()<<endl;
cout<<"End";
return 0;
}
//######################################################

int circular::max()
{
   if(head == NULL)
   {
      cout<<"Circular Linked List is Empty\nReturning -1";
      return -1;
   }
   int m=head->data;
   a=head;
   do
   {
      m= m> a->data ? m:a->data;
      a=a->next;
   } while (a!= head);
   
   return m;
}
void circular::dlt(int key)
{
   if(!head){cout<<"Empty Linked List\n";return;}
   a=head;
   //Single Length
   if(head->next == head)
   {
      if(head->data == key)
      {
         delete head;
         head=NULL;
         return;
      }
      return;
   }
   //Taking a pointer to the end
   b=head;
   while(b->next != head)
   {
      b=b->next;
   }
   int flag=0;

   //Checking if element is present at the head node 
   if(head->data == key)
   {
      b->next=head->next;
      c=head;
      head=head->next;
      delete c;
      return;
   }

   while(a->next != head)
   {  if(a->data == key)break;
      b=a;
      a=a->next;
   }
   if(a->data == key)
   {
      b->next=a->next;
      delete a;
      return;
      //Write Code to delete
   }
   else
   {
      return;
   }
}
void circular::create()
{
   cout<<"Enter the number of elements=";
   int n,data;
   cin>>n;
   if(n>=1)
   {
      a=new node;cout<<"Enter data=";
      cin>>data;
      a->data=data;
      a->next=a;
      head=a;
      if(n==1)
      {return;}
      else
      {n--;}
   }
   for(int i=0;i<n;i++)
   {
      cout<<"Enter data= ";
      cin>>data;
      a=head;
      while(a->next != head)
      {
         a=a->next;
      }
      b=new node;
      b->data=data;
      a->next=b;
      b->next=head;
   }

}

void circular::display()
{
   a=head;
   do
   {
      cout<<a->data<<" ";
      a=a->next;
   } while(a!=head);
   
}

void circular::create_from_array(int *arr,int n)
{
   int data;
 if(n>=1)
 {
  data=*(arr +0);
  a=new node;
  a->data=data;
  head = a;
  a->next=head;
  n--;
  if(n==0)
  {
     return;
  }
 }
 


 for(int i=0;i<n;i++)
 {
    temp=new node;
    temp->data = *(arr + i +1);
    a=head;
    while(a->next!=head)
    {
       a=a->next;
    }
    a->next=temp;
    temp->next=head;
 }
}

void circular::insert(int pos,int value)
{
   if(pos==0)
   {
      temp=new node;
      a=head;
      while(a->next != head)
      {
         a=a->next;
      }
      a->next=temp;
      temp->data=value;
      temp->next=head;
      return;
   }
   else
   {
     a=head;
     b=head;
     while(pos--)
     {
        b=a;
        a=a->next;
     }
     c=new node;
     c->data=value;
     b->next=c;
     c->next=a;
   }
   
}







