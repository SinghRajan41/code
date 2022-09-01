#include<iostream>
using namespace std;
struct tnode
{
   tnode *left,*right;
   float data;
}*root;
struct qnode
{
   qnode *next;
   tnode *data;
};
class stack
{
   qnode *top,*a,*b;
   public:
   stack()
   {
      top=NULL;
   }
   void push(tnode *n);
   tnode * pop();
   int isempty();
   tnode * peektop();
};
void stack::push(tnode *n)
{
   a=new qnode;
   a->data = n;
   if(top == NULL)
   {
      top=a;
      top->next = NULL;
      return;
   }
   else
   {
      a->next = top;
      top =a;
   }
}
tnode * stack::pop()
{
    tnode *a;
   if(top ==NULL)
   {
      cout<<"\nThe stack is Empty\nReturning from pop function\n";
      return NULL;
   }
   else if(top ->next == NULL)
   {
     a=top->data;
     delete top;
     top=NULL;
     return a;
   }
   else
   {
      a=top->data;
      b=top;
      top=top->next;
      delete b;
      return a;
   }
}
int stack::isempty()
{
   if(top == NULL)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}
tnode * stack::peektop()
{
   if(top == NULL)
   {
      return NULL;
   }
   else
   {
      return top->data;
   }
}
class queue
{
   qnode *first,*last,*a,*b;
   public:
   queue()
   {
      first=NULL;
      last=NULL;
   }
   void nq(tnode *n);
   void dq();
   int isempty();
   tnode* peekfront();
};
void queue::nq(tnode *n)
{
   a=new qnode;
   a->next=NULL;
   a->data=n;
   if(first == NULL)
   {
      first=a;
      last=a;
   }
   else
   {
      last->next = a;
      last=a;
   }
}
void queue::dq()
{
   if(first == NULL)
   {
      cout<<"\nQueue is empty Returning\n";
      return;
   }
   else if(first==last && first != NULL)
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
int queue::isempty()
{
   if(first == NULL)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}
tnode * queue::peekfront()
{
   if(first == NULL)
   {
      cout<<"Queue is empty\nReturning NULL";
      return NULL;
   }
   else
   {
      return first->data;
   }
}

void create_tree()
{
   int x;
   queue q;
   tnode *p,*temp;
   cin>>x;
   root=new tnode;
   root->left=NULL;
   root->right=NULL;
   root->data = (float)x;
   q.nq(root);
   while(!q.isempty())
   {
      p=q.peekfront();
      cin>>x;
      if(x!= -1)
      {
         //Creating left node
         temp=new tnode;
         temp->left=NULL;
         temp->right=NULL;
         temp->data=(float)x;
         q.nq(temp);
         p->left=temp;
      }
      cin>>x;
      if(x != -1)
      {
         temp=new tnode;
         p->right = temp;
         temp->left=NULL;
         temp->right=NULL;
         temp->data=(float) x;
         q.nq(temp);
      }
      q.dq();
   }
   cout<<"\nTREE CREATED\n";

}
void inorder_display(tnode *t)
{
   if(t)
   {
      inorder_display(t->left);
   }
   if(t)
   {
      cout<<t->data<<" ";
   }
   if(t)
   {
      inorder_display(t->right);
   }
}
void inorder_iterative()
{
   stack s;
   tnode *t=root;
   s.push(t);
   t=t->left;
   
   while(!s.isempty() || t!=NULL)
   {
     if(t)
     {
        s.push(t);
        t=t->left;
     }
     else
     {
        t=s.pop();
        cout<<t->data<<" ";
        t=t->right;
     }
   }
}
void preorder_display(tnode *t)
{
if(t)
{
   cout<<t->data<<" ";
}
if(t)
{
   preorder_display(t->left);
}
if(t)
{
   preorder_display(t->right);
}
}
void postorder_display(tnode *t)
{
   if(t)
   {
      postorder_display(t->left);
   }
   if(t)
   {
      postorder_display(t->right);
   }
   if(t)
   {
      cout<<t->data<<" ";
   }

}
void level_order()
{
   queue q;
   tnode *t=root;
   q.nq(root);
   while(!q.isempty())
   {
      t=q.peekfront();
      cout<<t->data<<" ";
      if(t->left)
      {
         q.nq(t->left);
      }
      if(t->right)
      {
         q.nq(t->right);
      }
      q.dq();
   }
}
void iterative_preorder()
{
   tnode *t;
   stack s;
   s.push(root);
   t=root;
   while(t!= NULL || !s.isempty())
   {
      if(t)
      {
         cout<<t->data<<" ";
      }
      if(t)
      {
         t=t->left;
         s.push(t);
      }
      else
      {
         t=s.pop();
         if(t)
         {

         
         t=t->right;
         }
      }
   }
}
int h1=0,h2=0;
 
int height_iterative(tnode *t)
{
   int ans=-1,h=0;
   stack s;
   while(t!=NULL || !s.isempty())
   {
      if(t)
      {
         s.push(t);
         h+=1;
         t=t->left;
      }
      else
      {
         t=s.pop();
         ans = ans>h ? ans:h;
         t=t->right;
         h-=1;
      }
   }
   return ans;
} 
/*int height(tnode *t)
{
   int h=0,ans=-1;
   stack s;
   s.push(t);
   t=t->left;
   while(t!=NULL || !s.isempty())
   {
      if(t)
      {
         s.push(t);
         t=t->left;
         h+=1;
      }
      else
      {
         ans = ans>h ? ans:h;
         t=s.pop();
         h-=1;
         t=t->right;
      }
   }
   return ans;
}*/                                                                                                                                                                                                                                                                            
int count_nodes(tnode *t)
{
   int count=0;
   stack s;
   t=root;
   while(!s.isempty() || t!=NULL)
   {
      if(t)
      {
         s.push(t);
         t=t->left;
         count+=1;
      }
      else
      {
         t=s.pop();
         t=t->right;
      }
   }
   return count;
}
int count_nodes_recursively(tnode *t)
{
   int x,y;
   if(t)
   {
     x=count_nodes_recursively(t->left);
     y=count_nodes_recursively(t->right);
     return x+y+1;
   }
   else
   {
      return 0;
   }
}
int count_external(tnode *t)
{
   if(t)
   {
      int x=count_external(t->left);
      int y=count_external(t->right);
      if(!t->left && !t->right)
      {
         return x+y+1;
      }
      else
      {
         return x+y;
      }
   }
   else
   {
      return 0;
   }
}
int height_recursive(tnode *t)
{
   int x,y;
   if(t)
   {
      x=height_recursive(t->left);
      y=height_recursive(t->right);
      return x>y ? x+1:y+1;
   }
   else
   {
      return 0;
   }
}


int main()
{
   create_tree();  
   cout<<height_recursive(root);
   return 0;
}
