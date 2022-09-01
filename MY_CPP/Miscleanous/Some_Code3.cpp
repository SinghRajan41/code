#include<iostream>
#include<cstring>
using namespace std;
struct tnode
{
   tnode *left,*right;
   //Data stored by the tree node will be integer type
   int data;int height;
}*root=NULL;
struct node
{
   //This is a simple node used in Stack and Queues
   node *next;
   tnode *data;
};
class stack
{
   node *top,*a,*b;
   public:
   stack()
   {
      top = NULL;
   }
   void push(tnode *n);
   tnode *pop();
   int isempty();
   tnode *peektop();
};
class queue
{
   node *first,*last,*a;
   public:
   queue(){first=last=NULL;}
   void nq(tnode *n);
   void dq();
   int isempty();
   tnode *peekfront();
};




tnode * Rinsert(tnode * n,int key);
int node_height(tnode *t);
int balance_factor(tnode *t);
tnode * LLRotation(tnode *p);
tnode * LRRotation(tnode *p);
tnode *RRRotation(tnode *p);
tnode *RLRotation(tnode *p);
void level_order_display(tnode *t);
int balance_factor(tnode *p);

int main()
{
   int x;
   cin>>x;
   root=Rinsert(root,x);
   for(int i=0;i<15;i++)
   {
      cin>>x;
      Rinsert(root,x);
   }
   level_order_display(root);
   return 0;
}


void stack::push(tnode *n)
{
  a=new node;
  a->next=NULL;
  a->data=n;
  if(top == NULL)
  {
     top=a;return;
  }
  else
  {
     a->next=top;
     top=a;
  }
}
tnode * stack::pop()
{
   tnode *temp=NULL;
   if(top == NULL)
   {
      return NULL;
   }
   else
   {
      a=top;
      top=top->next;
      temp=a->data;
      delete a;
      return temp;
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
void queue::nq(tnode *n)
{
   a=new node;
   a->next=NULL;
   a->data=n;
   if(first == NULL)
   {
      first=last=a;
   }
   else
   {
      last->next=a;
      last=a;
   }
}
void queue::dq()
{
   if(first == NULL)
   {return;}
   else if(first==last && first!=NULL)
   {
      delete first;
      first=last=NULL;
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
      return NULL;
   }
   else
   {
      return first->data;
   }
}

tnode * Rinsert(tnode *t,int key)
{
   if(t == NULL)
   {
      tnode *temp=new tnode;
      temp->left=temp->right=NULL;
      temp->height=1;
      temp->data=key;
      return temp;
   }
   if(key <  t->data)
   {
      t->left = Rinsert(t->left,key);
   }
   else if(key > t->data)
   {
      t->right = Rinsert(t->right,key);
   }
   t->height=node_height(t);
   if(balance_factor(t)==2 && balance_factor(t->left)==1)
   {
      //Perform LL Rotation
      return LLRotation(t);
   }
   else if(balance_factor(t)==2 && balance_factor(t->left)==-1)
   {
      //Perform LR Rotation
      return LRRotation(t);
   }
   else if(balance_factor(t)==-2 && balance_factor(t->right)==-1)
   {
      //Perform RR Rotation
      return RRRotation(t);
   }
   else if(balance_factor(t)==-2 && balance_factor(t->right) == 1)
   {
      //Perform RL Rotation
      return RLRotation(t);
   }
   return t;
}
void level_order_display(tnode *t)
{
   if(t == NULL)
   {
      return;
   }
   else
   {
      queue q;
      q.nq(t);
      while(!q.isempty())
      {
         t=q.peekfront();
         cout<<t->data<< " ";
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
}
int node_height(tnode *t)
{
   int hl,hr;
   hl = t && t->left ? t->left->height: 0;
   hr= t&&t->right ? t->right->height : 0;
   return hl>hr ? hl+1:hr+1;
}
tnode * LLRotation(tnode *p)
{
 tnode *pl,*b;
 pl=p->left;
 b=pl->right;
 pl->right=p;
 p->left=b;
 pl->height=node_height(pl);
 p->height=node_height(p);
 if(p == root)
 {
    root=pl;
 }
 return pl;
}
tnode * RRRotation(tnode *p)
{
  tnode *pr,*b;
  pr=p->right;
  b=pr->left; 
  pr->left=p;
  p->right=b;
  p->height=node_height(p);
  pr->height=node_height(pr);
  if(p == root)
  {
     root = pr;
  }
  return pr;
}
tnode * RLRotation(tnode *p)
{
  tnode *a,*pr,*c,*d;
  pr=p->right;
  a=pr->left;
  c=a->left;
  d=a->right;
  a->left=p;
  p->right=c;
  a->right=pr;
  pr->left=d; 
  a->height=node_height(a);
  p->height=node_height(p);
  pr->height=node_height(pr);
  if(root == p)
  {
     root = a;
  }
  return a;
}
tnode *LRRotation(tnode *p)
{
  tnode *pl,*a,*c,*d;
  pl=p->left;
  a=pl->right;
  c=a->left;
  d=a->right;
  a->left=pl;
  pl->right=c;
  a->right=p;
  p->left=d;
  a->height=node_height(a);
  pl->height=node_height(pl);
  p->height=node_height(p);
  if(p==root)
  {
     root=a;
  } 
  return a;
}
int balance_factor(tnode *p)
{
 int hl,hr;
 hl=p && p->left ? p->left->height : 0;
 hr=p && p->right? p->right->height:0;
 return hl-hr;
}