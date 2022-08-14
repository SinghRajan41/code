#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
struct node
{
   int data;
   node *left, *right;
};
node *insert(node *root, int key);
node *newNode(int x);
void printInorder(node *root);
int height(node *root);
bool isLeafNode(node *root);
node *deleteNode(node *root, int key);
void levelOrderLinebyLine(node *root);
node *buildFromPre(int pre[], int low, int high);
node *buildFromPre1(int pre[], int size);
void BTtoBST(node *root);
bool isLeafNode(node *root);
bool isHalfNode(node *root);
bool isFullNode(node *root);
void modifyHN(node *root);
void modifyFN(node *root);
void _BTtoBST(node *root, vector<int> &pre);
void __BTtoBST(node *root, vector<int> &pre);
void toSmallerSum(node *root);
void toGreaterSum(node *root);
void _toGreaterSum(node *root, long long int *sum);
void _toSmallerSum(node *root, long long int *sum);
void BSTtoHeap(node *root);
void pushDown(node *root);
node *LOtoBST(vector<int> lo);
node *mergeBST(node *root1, node *root2);
node *buildFromSortedList(vector<int> &arr, int low, int high);
void fillInorder(node *root, vector<int> *t);
vector<int> sortedMerge(vector<int> &t1, vector<int> &t2);
void mergeBST2(node *root1, node *root2);
node *LCA(node *root, int n1, int n2);
node *LCA2(node *root, int n1, int n2);
void _LCA2(node *root, int n1, int n2, bool *flag, node **res);
bool isBST1(node *root, int Min = INT32_MIN, int Max = INT32_MAX);
bool isBST2(node *root);
bool isBST3(node *root);
void storeInorder(node *root, vector<int> &in);
void findMax(node *root, int *Max);
void findMin(node *root, int *Min);
int KthSmallest1(node *root, int k);
int KthSmallest2(node *root, int k);
void _KthSmallest2(node *root, int *res, int *k);
int KthSmallest3(node *root, int k);
int KthLargest3(node *root, int k);
void morrisInorder(node *root);
void reverseMorrisInorder(node *root);
int dist(node *root, int n1, int n2);
int _dist(node *root, int n1, int n2, int *ans);
int largestBelowN(node *root, int n);
bool search(node *root, int key);
node *deleteOutOfRange(node *root, int low, int high);
int pairsWithSumX(node *root1, node *root2, int x);
int i;
node *_deleteOutOfRange(node *root, int low, int high);
int main()
{
   node *root1, *root2;
   root1 = root2 = NULL;
   vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
   vector<int> brr = {3, 6, 8, 10, 11, 15, 18};
   root1 = buildFromSortedList(arr, 0, arr.size() - 1);
   root2 = buildFromSortedList(brr, 0, brr.size() - 1);
   root1 = deleteOutOfRange(root1, 5, 10);
   printInorder(root1);
   return 0;
}
node *_deleteOutOfRange(node *root, int low, int high)
{
   if (root == NULL)
   {
      return NULL;
   }
   root->left = _deleteOutOfRange(root->left, low, high);
   root->right = _deleteOutOfRange(root->right, low, high);
   node *a = NULL;
   if (root->data < low)
   {
      a = root->right;
      delete root;
      return a;
   }
   if (root->data > high)
   {
      a = root->left;
      delete root;
      return a;
   }
   return root;
}
node *deleteOutOfRange(node *root, int low, int high)
{
   if (low > high)
   {
      cout << "\nInvalid Range\n";
      swap(low, high);
   }
   return _deleteOutOfRange(root, low, high);
}
int pairsWithSumX(node *root1, node *root2, int x)
{
   if (root1 == NULL)
   {
      return 0;
   }
   if (search(root2, (x - root1->data)))
   {
      return 1 + pairsWithSumX(root1->left, root2, x) + pairsWithSumX(root1->right, root2, x);
   }
   else
   {
      return pairsWithSumX(root1->left, root2, x) + pairsWithSumX(root1->right, root2, x);
   }
}
bool search(node *root, int key)
{
   if (root == NULL)
   {
      return false;
   }
   if (key < root->data)
   {
      return (root->data == key) || search(root->left, key);
   }
   else
   {
      return (root->data == key) || search(root->right, key);
   }
}
int largestBelowN(node *root, int n)
{
   if (root == NULL)
   {
      return -1;
   }
   if (root->data <= n)
   {
      return max(root->data, largestBelowN(root->right, n));
   }
   else
   {
      return largestBelowN(root->left, n);
   }
}
int _dist(node *root, int n1, int n2, int *ans)
{
   if (root == NULL)
   {
      return 0;
   }
   int l = _dist(root->left, n1, n2, ans);
   int r = _dist(root->right, n1, n2, ans);
   if (root->data == n1 || root->data == n2)
   {
      if (l != 0 || r != 0)
      {
         *ans = max(l, r);
         return 0;
      }
      else
      {
         return 1;
      }
   }
   else
   {
      if (l != 0 && r != 0)
      {
         *ans = l + r;
         return 0;
      }
      else if (l != 0 || r != 0)
      {
         return max(l, r) + 1;
      }
   }
   return 0;
}
int dist(node *root, int n1, int n2)
{
   if (root == NULL)
   {
      return -1;
   }
   int ans = -1;
   _dist(root, n1, n2, &ans);
   return ans;
}
int KthSmallest3(node *root, int k)
{
   if (root == NULL)
   {
      return -1;
   }
   node *cur = root;
   while (cur != NULL)
   {
      if (cur->left == NULL)
      {
         k--;
         if (k == 0)
         {
            return cur->data;
         }
         cur = cur->right;
      }
      else
      {
         node *pre = cur->left;
         while (pre->right != NULL && pre->right != cur)
         {
            pre = pre->right;
         }
         if (pre->right == NULL)
         {
            pre->right = cur;
            cur = cur->left;
         }
         else
         {
            pre->right = NULL;
            k--;
            if (k == 0)
            {
               return cur->data;
            }
            cur = cur->right;
         }
      }
   }
   return -1;
}
int KthLargest3(node *root, int k)
{
   if (root == NULL)
   {
      return -1;
   }
   node *cur = root;
   while (cur != NULL)
   {
      if (cur->right == NULL)
      {
         k--;
         if (k == 0)
         {
            return cur->data;
         }
         cur = cur->left;
      }
      else
      {
         node *suc = cur->right;
         while (suc->left != NULL && suc->left != cur)
         {
            suc = suc->left;
         }
         if (suc->left == NULL)
         {
            suc->left = cur;
            cur = cur->right;
         }
         else
         {
            suc->left = NULL;
            k--;
            if (k == 0)
            {
               return cur->data;
            }
            cur = cur->left;
         }
      }
   }
   return -1;
}
void reverseMorrisInorder(node *root)
{
   if (root == NULL)
   {
      return;
   }
   node *cur = root;
   while (cur != NULL)
   {
      if (cur->right == NULL)
      {
         cout << cur->data << " ";
         cur = cur->left;
      }
      else
      {
         node *suc = cur->right;
         while (suc->left != NULL && suc->left != cur)
         {
            suc = suc->left;
         }
         if (suc->left == NULL)
         {
            suc->left = cur;
            cur = cur->right;
         }
         else
         {
            suc->left = NULL;
            cout << cur->data << " ";
            cur = cur->left;
         }
      }
   }
}
void morrisInorder(node *root)
{
   if (root == NULL)
   {
      return;
   }
   while (root != NULL)
   {
      if (root->left == NULL)
      {
         cout << root->data << " ";
         root = root->right;
      }
      else
      {
         node *pre = root->left;
         while (pre->right != NULL && pre->right != root)
         {
            pre = pre->right;
         }
         if (pre->right == NULL)
         {
            pre->right = root;
            root = root->left;
         }
         else
         {
            pre->right = NULL;
            cout << root->data << " ";
            root = root->right;
         }
      }
   }
}
void _KthSmallest2(node *root, int *res, int *k)
{
   if (root == NULL)
   {
      return;
   }
   _KthSmallest2(root->left, res, k);
   (*k)--;
   if ((*k) == 0)
   {
      *res = root->data;
      return;
   }
   _KthSmallest2(root->right, res, k);
}
int KthSmallest2(node *root, int k)
{
   if (root == NULL)
   {
      return -1;
   }
   int res = -1;
   _KthSmallest2(root, &res, &k);
   return res;
}
int KthSmallest1(node *root, int k)
{
   if (k <= 0 || root == NULL)
   {
      return -1;
   }
   vector<int> in;
   storeInorder(root, in);
   if (k > in.size())
   {
      return -1;
   }
   else
   {
      return in[k - 1];
   }
}
bool isBST3(node *root)
{
   if (root == NULL)
   {
      return true;
   }
   vector<int> in;
   storeInorder(root, in);
   for (int i = 0; i < in.size() - 1; i++)
   {
      if (in[i] > in[i + 1])
      {
         return false;
      }
   }
   in.clear();
   return true;
}
void storeInorder(node *root, vector<int> &in)
{
   if (root == NULL)
   {
      return;
   }
   storeInorder(root->left, in);
   in.push_back(root->data);
   storeInorder(root->right, in);
}
void findMin(node *root, int *Min)
{
   if (root == NULL)
   {
      return;
   }
   (*Min) = (*Min) < root->data ? (*Min) : root->data;
   findMin(root->left, Min);
   findMin(root->right, Min);
}
void findMax(node *root, int *Max)
{
   if (root == NULL)
   {
      return;
   }
   (*Max) = (*Max) > root->data ? (*Max) : root->data;
   findMax(root->left, Max);
   findMax(root->right, Max);
}
bool isBST2(node *root)
{
   if (root == NULL)
   {
      return true;
   }
   if (isLeafNode(root))
   {
      return true;
   }
   int Max, Min;
   Max = INT32_MIN;
   Min = INT32_MAX;
   findMax(root->left, &Max);
   findMin(root->right, &Min);
   return ((root->data < Min && root->data > Max) && (isBST2(root->left) && isBST2(root->right)));
}
bool isBST1(node *root, int Min, int Max)
{
   if (root == NULL)
   {
      return true;
   }
   bool c = root->data > Min && root->data < Max;
   return c && isBST1(root->left, Min, root->data) && isBST1(root->right, root->data, Max);
}
void _LCA2(node *root, int n1, int n2, bool *flag, node **res)
{
   if (!(*flag) || root == NULL)
   {
      return;
   }
   if (*flag && n1 < root->data && n2 > root->data)
   {
      *flag = false;
      *res = root;
   }

   _LCA2(root->left, n1, n2, flag, res);
   _LCA2(root->right, n1, n2, flag, res);
}
node *LCA2(node *root, int n1, int n2)
{
   if (root == NULL)
   {
      return NULL;
   }
   bool flag = true;
   if (n1 > n2)
   {
      swap(n1, n2);
   }
   node *a = NULL;
   _LCA2(root, n1, n2, &flag, &a);
   return a;
}
node *LCA(node *root, int n1, int n2)
{
   if (root == NULL)
   {
      return NULL;
   }
   if (n1 == root->data || n2 == root->data)
   {
      return root;
   }
   node *l, *r;
   l = LCA(root->left, n1, n2);
   r = LCA(root->right, n1, n2);
   if (l && r)
   {
      return root;
   }
   if (!l && !r)
   {
      return NULL;
   }
   return l != NULL ? l : r;
}
void mergeBST2(node *root1, node *root2)
{
   // The function takes two BST's and prints the inorder of the merged binary tree
   if (!root1 && !root2)
   {
      return;
   }
   stack<node *> s1, s2;
   while (root1 || root2 || !s1.empty() || !s2.empty())
   {
      while (root1)
      {
         s1.push(root1);
         root1 = root1->left;
      }
      while (root2)
      {
         s2.push(root2);
         root2 = root2->left;
      }
      if ((s2.empty()) || (!s1.empty() && s1.top()->data < s2.top()->data))
      {
         root1 = s1.top();
         s1.pop();
         cout << root1->data << " ";
         root1 = root1->right;
      }
      else
      {
         root2 = s2.top();
         s2.pop();
         cout << root2->data << " ";
         root2 = root2->right;
      }
   }
}
void fillInorder(node *root, vector<int> &t)
{
   if (root == NULL)
   {
      return;
   }
   fillInorder(root->left, t);
   t.push_back(root->data);
   fillInorder(root->right, t);
}
vector<int> sortedMerge(vector<int> &t1, vector<int> &t2)
{
   int n, m, i, j;
   i = j = 0;
   n = t1.size();
   m = t2.size();
   vector<int> res;
   while (i < n && j < m)
   {
      if (t1[i] < t2[j])
      {
         res.push_back(t1[i++]);
      }
      else
      {
         res.push_back(t2[j++]);
      }
   }
   while (i < n)
   {
      res.push_back(t1[i++]);
   }
   while (j < m)
   {
      res.push_back(t2[j++]);
   }
   return res;
}
node *buildFromSortedList(vector<int> &arr, int low, int high)
{
   if (high < low)
   {
      return NULL;
   }
   if (low == high)
   {
      return newNode(arr[low]);
   }
   int mid = (low + high) / 2;
   node *root = newNode(arr[mid]);
   root->left = buildFromSortedList(arr, low, mid - 1);
   root->right = buildFromSortedList(arr, mid + 1, high);
   return root;
}
node *mergeBST(node *root1, node *root2)
{
   // Function to merge two height balanced binary search tree
   if (root1 == NULL || root2 == NULL)
   {
      return root1 == NULL ? root2 : root1;
   }
   vector<int> t1, t2, t3;
   fillInorder(root1, t1);
   fillInorder(root2, t2);
   t3 = sortedMerge(t1, t2);
   return buildFromSortedList(t3, 0, t3.size() - 1);
}
node *LOtoBST(vector<int> lo)
{
   if (lo.size() == 0)
   {
      return NULL;
   }
   if (lo.size() == 1)
   {
      return newNode(lo[0]);
   }
   node *root = newNode(lo[0]);
   vector<int> left, right;
   for (int i = 1; i < lo.size(); i++)
   {
      if (lo[i] > lo[0])
      {
         right.push_back(lo[i]);
      }
      else
      {
         left.push_back(lo[i]);
      }
   }
   root->left = LOtoBST(left);
   root->right = LOtoBST(right);
   return root;
}
void pushDown(node *root)
{
   if (root == NULL)
   {
      return;
   }
   if (root->left && root->right)
   {
      node *child = (root->left->data < root->right->data) ? root->left : root->right;
      if (root->data > child->data)
      {
         swap(root->data, child->data);
         pushDown(child);
      }
   }
   if (root->left)
   {
      if (root->data > root->left->data)
      {
         swap(root->data, root->left->data);
         pushDown(root->left);
      }
   }
   if (root->right)
   {
      if (root->data > root->right->data)
      {
         swap(root->data, root->right->data);
         pushDown(root->right);
      }
   }
}
void BSTtoHeap(node *root)
{
   if (root == NULL)
   {
      return;
   }
   BSTtoHeap(root->left);
   BSTtoHeap(root->right);
   if (isLeafNode(root))
   {
      return;
   }
   pushDown(root);
}
void _toSmallerSum(node *root, long long int *sum)
{
   if (root == NULL)
   {
      return;
   }
   _toSmallerSum(root->left, sum);
   int temp = root->data;
   root->data += *(sum);
   *(sum) += temp;
   _toSmallerSum(root->right, sum);
}
void toSmallerSum(node *root)
{
   /*Given a Binary Search Tree(BST),
   convert it to a Binary Tree such that every key of the original BST
   is changed to key plus sum of all smaller keys in BST.*/
   if (root == NULL)
   {
      return;
   }
   long long int sum = 0;
   _toSmallerSum(root, &sum);
}
void _toGreaterSum(node *root, long long int *sum)
{
   if (root == NULL)
   {
      return;
   }
   _toGreaterSum(root->right, sum);
   int temp = root->data;
   root->data = *sum;
   *(sum) += temp;
   _toGreaterSum(root->left, sum);
}
void toGreaterSum(node *root)
{
   // The function sets the current node as the sum of the nodes greater
   // than the current node
   long long int sum = 0;
   _toGreaterSum(root, &sum);
}

bool isFullNode(node *root)
{
   if (root->left != NULL && root->right != NULL)
   {
      return true;
   }
   else
   {
      return false;
   }
}
bool isHalfNode(node *root)
{
   if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL))
   {
      return true;
   }
   else
   {
      return false;
   }
}
void __BTtoBST(node *root, vector<int> &pre)
{
   if (root == NULL)
   {
      return;
   }
   __BTtoBST(root->left, pre);
   root->data = pre[i++];
   __BTtoBST(root->right, pre);
}
void _BTtoBST(node *root, vector<int> &pre)
{
   if (root == NULL)
   {
      return;
   }
   pre.push_back(root->data);
   _BTtoBST(root->left, pre);

   _BTtoBST(root->right, pre);
}
void BTtoBST(node *root)
{
   if (root == NULL)
   {
      return;
   }
   vector<int> pre;
   _BTtoBST(root, pre);
   sort(pre.begin(), pre.end());
   i = 0;
   __BTtoBST(root, pre);
}
node *buildFromPre1(int pre[], int size)
{
   // The function uses a stack to build the tree
   if (size == 0)
   {
      return NULL;
   }
   stack<node *> s;
   node *root = newNode(pre[0]);
   s.push(root);
   for (int i = 1; i < size; i++)
   {
      node *cur = NULL;
      while (!s.empty() && pre[i] > s.top()->data)
      {
         cur = s.top();
         s.pop();
      }
      if (cur != NULL)
      {
         cur->right = newNode(pre[i]);
         s.push(cur->right);
      }
      else
      {
         s.top()->left = newNode(pre[i]);
         s.push(s.top()->left);
      }
   }
   return root;
}
node *buildFromPre(int pre[], int low, int high)
{
   if (high < low)
   {
      return NULL;
   }
   if (low == high)
   {
      return newNode(pre[low]);
   }
   node *root = newNode(pre[low]);
   int i = low + 1;
   while (pre[low] > pre[i])
   {
      i++;
   }
   root->left = buildFromPre(pre, low + 1, i - 1);
   root->right = buildFromPre(pre, i, high);
   return root;
}
void levelOrderLinebyLine(node *root)
{
   if (root == NULL)
   {
      return;
   }
   queue<node *> q;
   int count = 1;
   q.push(root);
   while (!q.empty())
   {
      int x = 0;
      while (count--)
      {
         node *cur = q.front();
         q.pop();
         cout << cur->data << " ";
         if (cur->left)
         {
            q.push(cur->left);
            x++;
         }
         if (cur->right)
         {
            q.push(cur->right);
            x++;
         }
      }
      cout << endl;
      count = x;
   }
}
bool isLeafNode(node *root)
{
   if (root->left == NULL && root->right == NULL)
   {
      return true;
   }
   else
   {
      return false;
   }
}
node *deleteNode(node *root, int key)
{
   if (root == NULL)
   {
      return NULL;
   }
   if (root->data == key)
   {
      if (isLeafNode(root))
      {
         delete root;
         return NULL;
      }

      if (height(root->left) > height(root->right))
      {
         node *pred = root->left;
         while (pred->right != NULL)
         {
            pred = pred->right;
         }
         root->data = pred->data;
         root->left = deleteNode(root->left, pred->data);
      }
      else
      {
         node *suc = root->right;
         while (suc->left != NULL)
         {
            suc = suc->left;
         }
         root->data = suc->data;
         root->right = deleteNode(root->right, suc->data);
      }
   }
   if (key < root->data)
   {
      root->left = deleteNode(root->left, key);
   }
   else
   {
      root->right = deleteNode(root->right, key);
   }
   return root;
}
int height(node *root)
{
   if (root)
   {
      int l = height(root->left);
      int r = height(root->right);
      return l > r ? l + 1 : r + 1;
   }
   return 0;
}
void printInorder(node *root)
{
   if (root == NULL)
   {
      return;
   }

   printInorder(root->left);
   cout << root->data << " ";
   printInorder(root->right);
}
node *insert(node *root, int key)
{
   if (root == NULL)
   {
      return newNode(key);
   }
   if (key < root->data)
   {
      root->left = insert(root->left, key);
   }
   else
   {
      root->right = insert(root->right, key);
   }
   return root;
}
node *newNode(int x)
{
   node *temp = new node;
   temp->left = temp->right = NULL;
   temp->data = x;
   return temp;
}