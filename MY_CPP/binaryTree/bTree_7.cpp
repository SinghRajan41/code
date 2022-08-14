// Convert a ternary tree into a doubly linked list
#include <iostream>
using namespace std;
struct tnode
{
   int data;
   tnode *left, *right, *middle;
};
struct lnode
{
   int data;
   lnode *next, *prev;
};
lnode *newLnode(int value)
{
   lnode *temp = new lnode;
   temp->next = temp->prev = NULL;
   temp->data = value;
   return temp;
};
tnode *newTnode(int value)
{
   tnode *temp = new tnode;
   temp->left = temp->middle = temp->right = NULL;
   temp->data = value;
   return temp;
}
void buildLL(tnode *root, lnode **tail)
{
   if (root == NULL)
   {
      return;
   }
   lnode *temp = newLnode(root->data);
   (*tail)->next = temp;
   temp->prev = *tail;
   *tail = temp;
   buildLL(root->left, tail);
   buildLL(root->middle, tail);
   buildLL(root->right, tail);
}
int main()
{
   tnode *root = newTnode(30);
   root->left = newTnode(5);
   root->left->left = newTnode(1);
   root->left->right = newTnode(8);
   root->left->middle = newTnode(4);
   root->middle = newTnode(11);
   root->middle->left = newTnode(6);
   root->middle->middle = newTnode(7);
   root->middle->right = newTnode(15);
   root->right = newTnode(63);
   root->right->left = newTnode(31);
   root->right->middle = newTnode(55);
   root->right->right = newTnode(65);
   lnode *tail = newLnode(root->data);
   lnode *head = tail;
   buildLL(root, &tail);
   head->prev = NULL;
   cout << "\nLinked List Created\n";
   head = head->next;
   while (head != NULL)
   {
      cout << head->data << " ";
      head = head->next;
   }
   return 0;
}