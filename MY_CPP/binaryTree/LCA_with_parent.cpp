// #include <iostream>
// #include <queue>
// using namespace std;
// struct pnode
// {
//    int data;
//    pnode *left, *right, *parent;
// } *root = NULL;
// pnode *newPNode(int x)
// {
//    pnode *temp = new pnode;
//    temp->left = temp->right = temp->parent = NULL;
//    temp->data = x;
//    return temp;
// }
// pnode *createTree()
// {
//    int x;
//    cin >> x;
//    if (x == -1)
//    {
//       return NULL;
//    }
//    root = newPNode(x);
//    queue<pnode *> q;
//    q.push(root);
//    while (!q.empty())
//    {
//       pnode *cur = q.front();
//       q.pop();
//       cin >> x;
//       if (x != -1)
//       {
//          cur->left = newPNode(x);
//          cur->left->parent = cur;
//          q.push(cur->left);
//       }
//       cin >> x;
//       if (x != -1)
//       {
//          cur->right = newPNode(x);
//          cur->right->parent = cur;
//          q.push(cur->right);
//       }
//    }
//    return root;
// }
// void filldb(pnode *root, int n1, int n2, vector<pair<pnode *, int>> &db, int level)
// {
//    static bool c1 = false;
//    static bool c2 = false;
//    if (c1 && c2)
//    {
//       return;
//    }
//    if (root == NULL)
//    {
//       return;
//    }
//    if (root->data == n1)
//    {
//       c1 = true;
//       db.push_back(make_pair(root, level));
//    }
//    if (root->data == n2)
//    {
//       c2 = true;
//       db.push_back(make_pair(root, level));
//    }
//    filldb(root->left, n1, n2, db, level + 1);
//    filldb(root->right, n1, n2, db, level + 1);
// }
// pnode *LCA(pnode *root, int n1, int n2)
// {
//    if (root == NULL)
//    {
//       return NULL;
//    }

//    vector<pair<pnode *, int>> db;
//    filldb(root, n1, n2, db, 1);
//    if (db[0].second > db[1].second)
//    {
//       while (db[0].second > db[1].second)
//       {
//          db[0].second--;
//          db[0].first = db[0].first->parent;
//       }
//    }
//    else
//    {
//       while (db[1].second > db[0].second)
//       {
//          db[1].second--;
//          db[1].first = db[1].first->parent;
//       }
//    }
//    while (db[1].first != db[0].first)
//    {
//       db[1].first = db[1].first->parent;
//       db[0].first = db[0].first->parent;
//    }
//    return db[0].first;
// }
// void mi(pnode *root)
// {
//    if (root == NULL)
//    {
//       return;
//    }
//    pnode *cur = root;
//    while (cur != NULL)
//    {
//       if (cur->left == NULL)
//       {
//          cout << cur->data << " ";
//          cur = cur->right;
//       }
//       else
//       {
//          pnode *pre = cur->left;
//          while (pre->right != NULL && pre->right != cur)
//          {
//             pre = pre->right;
//          }
//          if (pre->right == NULL)
//          {
//             pre->right = cur;
//             cur = cur->left;
//          }
//          else
//          {
//             pre->right = NULL;
//             cout << cur->data << " ";
//             cur = cur->right;
//          }
//       }
//    }
// }
// int main()
// {
//    pnode *root = createTree();
//    mi(root);
//    return 0;
// }
// A C++ program to construct all unique BSTs for keys from 1 to n
#include <bits/stdc++.h>
using namespace std;

// node structure
struct node
{
   int key;
   struct node *left, *right;
};

// A utility function to create a new BST node
struct node *newNode(int item)
{
   struct node *temp = new node;
   temp->key = item;
   temp->left = temp->right = NULL;
   return temp;
}

// A utility function to do preorder traversal of BST
void preorder(struct node *root)
{
   if (root != NULL)
   {
      cout << root->key << " ";
      preorder(root->left);
      preorder(root->right);
   }
}

// function for constructing trees
vector<struct node *> constructTrees(int start, int end)
{
   vector<struct node *> list;

   /* if start > end then subtree will be empty so returning NULL
      in the list */
   if (start > end)
   {
      list.push_back(NULL);
      return list;
   }

   /* iterating through all values from start to end for constructing\
      left and right subtree recursively */
   for (int i = start; i <= end; i++)
   {
      /* constructing left subtree */
      vector<struct node *> leftSubtree = constructTrees(start, i - 1);

      /* constructing right subtree */
      vector<struct node *> rightSubtree = constructTrees(i + 1, end);

      /* now looping through all left and right subtrees and connecting
         them to ith root below */
      for (int j = 0; j < leftSubtree.size(); j++)
      {
         struct node *left = leftSubtree[j];
         for (int k = 0; k < rightSubtree.size(); k++)
         {
            struct node *right = rightSubtree[k];
            struct node *node = newNode(i); // making value i as root
            node->left = left;              // connect left subtree
            node->right = right;            // connect right subtree
            list.push_back(node);           // add this tree to list
         }
      }
   }
   return list;
}

// Driver Program to test above functions
int main()
{
   // Construct all possible BSTs
   vector<struct node *> totalTreesFrom1toN = constructTrees(1, 4);

   /* Printing preorder traversal of all constructed BSTs */
   cout << "Preorder traversals of all constructed BSTs are \n";
   for (int i = 0; i < totalTreesFrom1toN.size(); i++)
   {
      preorder(totalTreesFrom1toN[i]);
      cout << endl;
   }
   return 0;
}
