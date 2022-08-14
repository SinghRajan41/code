#include<iostream>
#include<stdlib.h>
using namespace std;
/*struct node
{
   int data;
   node *next;
};
node *first;
void create(int arr[],int n)
{
   node *temp=new node;
   first = temp;
   first->next=NULL;
   first->data=arr[0];
   node *last;
   last=first;
   for(int i=1;i<n;i++)
   {
    temp=new node;
    last->next=temp;
    temp->data=arr[i];
    temp->next=NULL;
    last=temp;
   }
}

void display(node *first)
{
   node *temp=first;
   while(temp!=NULL)
   {
      cout<<temp->data<<" ";
      temp=temp->next;
   }
}
int main()
{
  int arr[]={1,2,3,4,5,6,7,8,9,0,9,8,7,6,5,4,3,2,1,2,3};int n;
  n=sizeof(arr)/sizeof(arr[0]);
  
  create(arr,n);
  display(first);
  return 0;
}*/


struct node
{
   int data;
   node *next;
}*first;

void create(int arr[],int n)
{
   node *temp=new node;
   first=temp;
   first->data=arr[0];
   first->next=NULL;
   node *last=first;
   for(int i=1;i<n;i++)
   {
      temp = new node;
      last->next=temp;
      temp->data=arr[i];
      temp->next=NULL;
      last=temp;
   }
}
/*void display(node *first)
{  //Iterative Display
   node *temp=first;
   while(temp!=NULL)
   {
      cout<<temp->data<<" ";
      temp=temp->next;
   }
}*/

void display(node *temp)
{ 
   //Recrusive Display
   if(temp==NULL)
   {
      return;
   }
   else
   {
      cout<<temp->data<<" ";
      display(temp->next);
   }
}
void displayr(node *temp)
{
   if(temp==NULL)
   {
      return;
   }
   displayr(temp->next);
   cout<<temp->data<<" ";
}
int main()
{
   int arr[10]={1,2,3,4,5,6,7,8,9};
   int n=sizeof(arr)/sizeof(arr[0]);
   create(arr,n);
   display(first);
   cout<<endl;
   displayr(first);
   return 0;
}