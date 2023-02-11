#include<iostream>
#define ll long long int
using namespace std;
struct node
{
    ll data;
    node *left,*right;
    char col;
    node(ll x)
    {
        left = right = NULL;
        col = 'r';
        data = x;
    }
}*mainroot;
node *insert(node *root , ll data);
node *RLRotation(node *a);
node *LRRotation(node *a);
node *RRRotation(node *a);
node *LLRotation(node * a);
void inorder(node *root);
int main()
{
    mainroot = NULL;
    for(int i=0;i<100;i++)  
    {
        mainroot = insert(mainroot , i);
        mainroot->col = 'b';
    }
    inorder(mainroot);
    return 0;
}
node *insert(node *root , ll key)
{
    if(root == NULL)
        return new node(key);
    if(key < root->data)
    {
        root->left = insert(root->left , key);
    }
    else
    {
        root->right = insert(root->right , key);
    }
    if(root->left && root->right && root->left->col == 'r' && root->right->col =='r' && root->col == 'b')
    {
        if(root->right->right && root->right->right->col == 'r')
        {
            root->col = 'r';
            root->left->col = root->right->col = 'b';
        }
        else if(root->right->left && root->right->left->col == 'r')
        {
            root->col = 'r';
            root->left->col = root->right->col = 'b';
        }
        else if(root->left->left && root->left->left->col == 'r')
        {
            root->col = 'r';
            root->left->col = root->right->col = 'b';
        }
        else if(root->left->right && root->left->right->col == 'r')
        {
            root->col = 'r';
            root->left->col = root->right->col = 'b';
        }
        return root;
    }
    //Check for LL Rotation
    if((root->left && root->left->left) && (root->left->col == 'r' && root->left->left->col == 'r') && (root->right == NULL || root->right->col == 'b'))
        root = LLRotation(root);
    //Check for RR Rotation
    if((root->right && root->right->right) && (root->right->col == 'r' && root->right->right->col == 'r') && (root->left == NULL || root->left->col == 'b'))
        root = RRRotation(root);
    //Check for LRRotation
    if((root->left && root->left->right) && (root->left->col == 'r' && root->left->right->col == 'r') && (root->right == NULL || root->right->col == 'b'))
        root = LRRotation(root);
    //Check for RLRotation
    if((root->right && root->right->left) && (root->right->col == 'r' && root->right->left->col == 'r') && (root->left == NULL || root->left->col == 'b'))
        root = RLRotation(root);
    if(root==mainroot && root->col == 'r')  root->col = 'b';
    return root;
}
node *RLRotation(node *a)
{
    node *b,*c,*f,*g;
    b = a->right;
    c = b->left;
    f = c->left;
    g = c->right;
    c->left = a;
    a->right = f;
    c->right = b;
    b->left = g;
    c->col = 'b';
    a->col = b->col = 'r';
    if(a == mainroot)
        mainroot = c;
    return c;
}
node *LRRotation(node *a)
{
    node *b,*d,*f,*g;
    b = a->left;
    d = d->right;
    f = d->left;
    g = d->right;
    d->left = b;
    b->right = f;
    d->right = a;
    a->left = g;
    d->col = 'b';   b->col = 'r';   a->col = 'r';
    if(a == mainroot)
    {
        mainroot = d;
    }
    return d;

}
node *RRRotation(node *a)
{
    node *b = a->right;
    node *x = b->left;
    b->left = a;a->right = x;
    if(a== mainroot)
        mainroot = b;
    return b;
}
void inorder(node *root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<< "  "<<root->col<<endl;
    inorder(root->right);
}
node *LLRotation(node * a)
{
    node *b,*c,*x;
    x = NULL;
    b = a->left;
    c = a->right;
    x = b->right;
    b->right = a;
    a->left = x;
    b->col = 'b';
    a->col = 'r';
    if(a== mainroot)
        mainroot = b;
    return b;
}