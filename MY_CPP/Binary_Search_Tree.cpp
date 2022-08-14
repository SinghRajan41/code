#include<iostream>
using namespace std;

struct tnode
{
    tnode *left,*right;
    int data;
};
struct node 
{
    node *next;
    tnode * data;
};
class stack
{
    node *top,*a,*b;
    public:
    stack()
    {
        top=NULL;
    }
    void push(tnode *n);
    tnode *pop();
    int isempty();
    tnode *peektop();
    int stack_top_value();
};
int stack::stack_top_value()
{
    if(top == NULL)
    {
        return 9999999;
    }
    else
    {
        tnode *temp=top->data;
        return temp->data;
    }
}
void stack::push(tnode *n)
{
    a=new node;
    a->data = n;
    if(top == NULL)
    {
      top=a;
      top->next = NULL;
    }
    else
    {
      a->next = top;
      top =a;
    }
}
tnode * stack::pop()
{
    tnode *ptr;
    if(top == NULL)
    {
        cout<<"\nStack is already empty\n";
        return NULL;
    }
    else
    {
    ptr=top->data;
    a=top;
    top=top->next;
    delete a;
    return ptr;
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
    node *first,*last,*a,*b;
    public:
    queue()
    {
        first = NULL;
        last = NULL;
    }
    void nq(tnode *t);
    void dq();
    int isempty();
    tnode *peekfront();
};
void queue::nq(tnode *t)
{
    a=new node;
    a->data = t;
    a->next = NULL;
    if(first == NULL)
    {
      first =a;
      last =a;
    }
    else
    {
       last->next = a;
       last = a;
    }
}
void queue::dq()
{
    if(first == NULL)
    {
        return;
    }
    else if(first == last && first!=NULL)
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
        return NULL;
    }
    else
    {
        return first->data;
    }
}
tnode *root=NULL;
void create_tree()
{
    int x;
    queue q;
    cin>>x;
    tnode *t,*prev;
    if(x != -1)
    {
      t=new tnode;
      t->data = x;
      t->left =NULL;
      t->right=NULL;
      q.nq(t);
    }
    root=t;
    while(!q.isempty())
    {
        prev=q.peekfront();
        cin>>x;
        //Creating a left child and linking with parent node
        if(x!=-1)
        {
           t=new tnode;
           t->left=NULL;
           t->right = NULL;
           t->data = x;
           q.nq(t);
           prev->left = t;
        }
        //Now creating right child
        cin>>x;
        if(x!= -1)
        {
            t=new tnode;
            t->data = x;
            t->left=NULL;
            t->right=NULL;
            q.nq(t);
            prev->right=t;
        }
        q.dq();
    }
    cout<<"\nTree Created\n";
}
void preorder_display(tnode *t)
{
    if(t)
    {
        cout<<t->data<<" ";
        preorder_display(t->left);
        preorder_display(t->right);
    }
}
void insert(int key)
{
    tnode *t=root,*prev=NULL;
    while(t!=NULL)
    {
        if(t->data == key)
        {
            cout<<"\nDuplicate Values Found\nReturning\n";
            return ;
        }
        else if(t->data < key)
        {
           prev=t;
           t=t->right;
        }
        else if(t->data > key)
        {
           prev=t;
           t=t->left;
        }
    }
    t=new tnode;
    t->data=key;
    t->left=NULL;
    t->right=NULL;
    if(prev->data < key)
    {
        prev->right = t;
    }
    else
    {
        prev->left=t;
    }
}
void level_order_display(tnode *t)
{
    queue q;
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
void recursive_insert(int key,tnode *prev,tnode *t)
{
    if(t)
    {
       if(key < t->data)
       {
          recursive_insert(key,t,t->left);
       }
       else if(key == t->data)
       {
           cout<<"\nDuplicate values cannot be inserted\n";
           return;
       }
       else
       if(key > t->data)
       {
          recursive_insert(key,t,t->right);
       }
    }
    else
    {
      t=new tnode;
      t->right=NULL;
      t->left=NULL;
      t->data = key;
      if(key < prev->data)
      {
          prev->left=t;
      }
      else
      {
          prev->right=t;
      }
    }
}
void iterative_preorder()
{
   tnode *t=root;
   stack s;
   while(t!=NULL || !s.isempty())
   {
      if(t)
      {
         cout<<t->data<<" ";
         s.push(t);
         t=t->left;
      }
      else
      {
         t=s.pop();
         t=t->right;
      }
   }
}
tnode * search(int key)
{
   tnode *t=root;
   while(t!=NULL)
   {
      if(key < t->data)
      {
         t=t->left;
      }
      else if(key > t->data)
      {
         t=t->right;
      }
      else
      {
         return t;
      }
   }
   return NULL;
}
void create_root(int x)
{
   root=new tnode;
   root->left=NULL;
   root->right=NULL;
   root->data = x;
}
void iterative_inorder()
{
    stack s;
    tnode *t=root;
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
void generate_from_preorder(int arr[],int n)
{
    root=new tnode;
    stack s;
    tnode *temp,*prev;
    root->left=NULL;
    root->right=NULL;
    root->data=arr[0];
    prev=root;
    s.push(root);
    for(int i=1;i<n;i++)
    {
        //Creating a new node and assinging values to it
        temp = new tnode;
        temp->left=NULL;
        temp->right=NULL;
        temp->data=arr[i];
        //Now deciding where to attach the new node
        if(arr[i] < prev->data)
        {
            prev->left=temp;
            prev=temp;
            s.push(temp); 
        }
        else
        {
           if(arr[i] > prev->data && arr[i] > s.stack_top_value())
           {
               //Check is stack is empty
               if(s.isempty())
               {
                   prev->right=temp;
                   continue;
               }
               prev=s.pop();
               prev->right = temp;
               prev=temp;
           }
           else
           {
               prev->right=temp;
               prev=temp;
           }
        }
    }
}
int main()
{
    int arr[15];
    for(int i=0;i<15;i++)
    {
        cin>>arr[i];
    }
    generate_from_preorder(arr,15);
    iterative_inorder();
    return 0;
}