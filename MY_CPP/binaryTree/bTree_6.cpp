#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
#include <deque>
using namespace std;
template <class X>
class lnode
{
public:
   lnode<X> *next;
   X data;
};
template <class X>
class llist
{
public:
   llist();
   lnode<X> *first, *last, *a, *b;
   void append(X value);
   void display();
};
// Traversals
struct node
{
   int data;
   node *left, *right, *random;
};
node *newNode(int x);
void levelOrder1(node *tree);
node *createTree();
void preOrder1(node *p);
bool treeMatch(node *t1, node *t2);
bool checkSubtree(node *T, node *S);
vector<node *> nodes;
int height(node *tree);
bool hasOneChild(node *root);
bool isFBT(node *root);
void joinNodes(node *tree);
node *createInPre(int in[], int pre[], int n);
int findRoot(int in[], int key, int n);
void postFromInPre(int in[], int pre[], int n);
void replaceWithSuccessor(node *tree);
void helper_func2(node *t, vector<int> &in);
void helper_func1(node *t, vector<int> &in);
void populateRandom(node *p);
node *findLeftMost(node *p);
void iterativeInOrder(node *p);
void NthInOrderNode(node *p, int n);
void spiralOrder(node *tree);
void printLR(node *tree, int level);
void printRL(node *tree, int level);
void printLevel(node *tree, int level);
void spiralOrder2(node *p);
void updateNext(node *p, node *key, node **next);
node *inorderSuccessor(node *p, node *key);
vector<int> reverseInorder(node *p);
void reversePath(node *tree, int key);
void reversePathUtil(node *tree, int key, vector<node *> path);
void specialLevelOrder(node *tree);
void specialLevelOrder2(node *root);
void specialLevelOrder3(node *root);
void specialLevelOrder4(node *root);
void levelOrderLinebyLine(node *root);
void reverseAlternateLevels(node *root);
void fillArr(node *root, vector<int> &arr, int level);
void fillLevels(node *root, vector<int> &arr, int level);
void morrisInorder(node *root);
void morrisPreorder(node *root);
void iterativePreorder(node *root);
void iterativePostorder(node *root);
void preorder(node *root);
void postOrder(node *root);
void diagonalOrder(node *root);
void diagonalOrderUtil(node *root, int d, queue<int> q[]);
void iterativeDiagonalOrder(node *root);
void printBoundary(node *root);
double density(node *tree);
void modifyTree(node *root);
node *modifyTreeUtil(node *root);
// Traversals

// Conversions/Creations

node *buildFromLL(llist<int> &l);
node *buildFromArray(int arr[], int n);
node *buildPrePost(int pre[], int post[], int n);
node *buildPrePre(int pre[], int mpre[], int n);
node *buildPrePreUtil(int pre[], int post[], int n);
node *buildFromHeap(int in[], int n);
int findMaxIndex(int in[], int n);
node *buildInPost(int in[], int post[], int n);
node *buildInPostUtil(int in[], int post[], int instrt, int inend, int *p);
int search1(int in[], int strt, int end, int key);
node *treeToDLL(node *root);
void treeToDLLUtil(node *root);
node *treeToDLL2(node *root);
void treeToDLL2Util(node *root, vector<node *> &nodes);
void modifyTree1(node *root);
void implementCSP(node *root);
int modifyTree2(node *root);
void mirror(node *root);
void printSpiralOrder(node *root);
node *treeToDLL3(node *root);
int modifyTree3(node *root);
bool checkCSP(node *root);
int treeSum(node *root);
bool isSumTree1(node *root);
bool isSumTree2(node *root);
int isSumTree2Util(node *root, bool *result);
int sumAllNodes(node *root);
int leafNodeSum(node *root);
bool checkCoveredUncoveredSum(node *root);
bool checkSameLevelLeaf(node *root);
bool isLeafNode(node *root);
bool checkSameLevelLeafUtil(node *root, int level, int x);
bool isDivisible(node *root);
int countNodes(node *root);
int isDivisibleUtil(node *root, int n, int &result);
node *test(int in[], int pre[], int start, int end, int n, unordered_map<int, int> &h);
bool isHeap(int lo[], int n);
bool isPFB(node *root);
bool isFBT(node *root);
void printAllPaths(node *root);
void printAllPathsUtil(node *root, vector<pair<int, int>> p, int pos);
bool isCBT(node *root);
int shortestPath(node *root);
bool isRBT(node *root);
pair<int, int> isRBTUtil(node *root, bool &result);
bool hasDuplicate(node *root);
void hasDuplicateUtil(node *root, unordered_map<int, int> &h, bool &result);
void LCAUtil(node *root, int n1, vector<int> p1, vector<int> &p);
int LCA(node *root, int n1, int n2);
node *LCA2(node *root, int n1, int n2);
node *LCA3(node *root, int n1, int n2);
node *LCA3Util(node *root, int n1, int n2, bool &c1, bool &c2);
int rootDist(node *root, int key);
void rootDistUtil(node *root, int key, int level, int &dist);
int minDist1(node *root, int n1, int n2);
int minDist2(node *root, int n1, int n2);
int dist(node *root, int n1, int n2);
int distUtil(node *root, int n1, int n2);
node *KthAncestor(node *root, int key, int k);
void _KthAncestor(node *root, int key, int k, stack<node *> &s, node **anc);

// Conversions/Creations
int ans = 0;
int main()
{
   node *root = createTree();
   cout << dist(root, 2, 5);
   return 0;
}
void _KthAncestor(node *root, int key, int k, stack<node *> &s, node **anc)
{
   if (root == NULL)
   {
      return;
   }
   s.push(root);
   _KthAncestor(root->left, key, k, s, anc);
   _KthAncestor(root->right, key, k, s, anc);
   if (root->data == key)
   {
      while (k--)
      {
         s.pop();
      }
      *anc = s.top();
   }
   else
   {
      s.pop();
   }
}
node *KthAncestor(node *root, int key, int k)
{
   if (root == NULL)
   {
      return NULL;
   }
   stack<node *> s;
   node *anc = NULL;
   _KthAncestor(root, key, k, s, &anc);
   return anc;
}
int dist(node *root, int n1, int n2)
{
   ans = 0;
   distUtil(root, n1, n2);
   return ans;
}
int distUtil(node *root, int n1, int n2)
{
   if (root == NULL)
   {
      return 0;
   }
   int l, r;
   l = dist(root->left, n1, n2);
   r = dist(root->right, n1, n2);
   if (root->data == n1 || root->data == n2)
   {
      if (l || r)
      {
         ans = max(l, r);
         return 0;
      }
      else
      {
         return 1;
      }
   }
   else if (l && r)
   {
      ans = l + r;
      return 0;
   }
   else if (l || r)
   {
      return max(l, r) + 1;
   }
   return 0;
}
int minDist2(node *root, int n1, int n2)
{
   if (root == NULL)
   {
      return -1;
   }
   node *lca = LCA3(root, n1, n2);
   int a = rootDist(root, n1);
   int b = rootDist(root, n2);
   int c = rootDist(root, lca->data);
   cout << "hey";
   cout << a << " " << b << " " << c << endl;
   return a + b - 2 * c;
}
int minDist1(node *root, int n1, int n2)
{
   // Find the distance betwenn two nodes in a BTree
   // Function first finds the LCA and distance of two nodes from LCA
   if (root == NULL)
   {
      return -1;
   }
   node *lca = LCA2(root, n1, n2);
   int l = rootDist(lca, n1);
   int r = rootDist(lca, n2);
   return l + r;
}
void rootDistUtil(node *root, int key, int level, int &dist)
{
   if (root == NULL)
   {
      return;
   }
   if (root->data == key)
   {

      // flag = true;
      dist = level;
      return;
   }
   rootDistUtil(root->left, key, level + 1, dist);
   rootDistUtil(root->right, key, level + 1, dist);
}
int rootDist(node *root, int key)
{
   if (root == NULL)
   {
      return -1;
   }
   int dist = -1;
   rootDistUtil(root, key, 0, dist);
   return dist;
}
node *LCA3(node *root, int n1, int n2)
{
   // This function returns LCA as NULL if either of the keys is not present
   // in the tree
   if (root == NULL)
   {
      return NULL;
   }
   bool c1, c2;
   c1 = c2 = false;
   node *lca = LCA3Util(root, n1, n2, c1, c2);
   if (c1 && c2)
   {
      return lca;
   }
   else
   {
      return NULL;
   }
}
node *LCA3Util(node *root, int n1, int n2, bool &c1, bool &c2)
{
   if (root == NULL)
   {
      return NULL;
   }
   if (root->data == n1)
   {
      c1 = true;
      return root;
   }
   if (root->data == n2)
   {
      c2 = true;
      return root;
   }
   node *l = LCA3Util(root->left, n1, n2, c1, c2);
   node *r = LCA3Util(root->right, n1, n2, c1, c2);
   if (l != NULL && r != NULL)
   {
      return root;
   }
   if (l == NULL && r == NULL)
   {
      return NULL;
   }

   return l != NULL ? l : r;
}
node *LCA2(node *root, int n1, int n2)
{
   static node *mainRoot = root;
   static bool c1 = false;
   static bool c2 = false;
   if (root == NULL)
   {
      return NULL;
   }
   if (root->data == n1)
   {
      c1 = true;
      return root;
   }
   if (root->data == n2)
   {
      c2 = true;
      return root;
   }
   node *l = LCA2(root->left, n1, n2);
   node *r = LCA2(root->right, n1, n2);

   if (l != NULL && r != NULL)
   {
      return root;
   }
   if (l == NULL && r == NULL)
   {
      return NULL;
   }
   return l == NULL ? r : l;
}
void LCAUtil(node *root, int n1, vector<int> p1, vector<int> &p)
{
   static bool flag = true;
   if (root == NULL)
   {
      return;
   }
   p1.push_back(root->data);
   if (root->data == n1)
   {
      flag = false;
      p = p1;
      return;
   }
   LCAUtil(root->left, n1, p1, p);
   LCAUtil(root->right, n1, p1, p);
}

int LCA(node *root, int n1, int n2)
{
   if (root == NULL)
   {
      return -1;
   }
   vector<int> p1, p2, p;

   LCAUtil(root, n1, p, p1);
   LCAUtil(root, n2, p, p2);
   int n = p1.size() < p2.size() ? p1.size() : p2.size();
   int i = 0;
   while (i < n && p1[i] == p2[i])
   {
      i++;
   }
   return p1[i - 1];
}
void hasDuplicateUtil(node *root, unordered_map<int, int> &h, bool &result)
{
   if (root == NULL)
   {
      return;
   }
   if (h.insert({root->data, 1}).second == false)
   {
      result = true;
      return;
   }
   hasDuplicateUtil(root->left, h, result);
   hasDuplicateUtil(root->right, h, result);
}
bool hasDuplicate(node *root)
{
   if (root == NULL)
   {
      return false;
   }
   unordered_map<int, int> h;
   bool result = false;
   hasDuplicateUtil(root, h, result);
   return result;
}
pair<int, int> isRBTUtil(node *root, bool &result)
{
   pair<int, int> p;
   if (root == NULL)
   {
      p.first = INT32_MAX - 1000;
      p.second = 0;
      return p;
   }
   if (isLeafNode(root))
   {
      p.first = p.second = 1;
      return p;
   }
   pair<int, int> p1, p2;
   p1 = isRBTUtil(root->left, result);
   p2 = isRBTUtil(root->right, result);
   if (p1.second > p1.first * 2)
   {

      result = false;
   }
   if (p2.second > p2.first * 2)
   {

      result = false;
   }
   p1.first = p1.first < p2.first ? p1.first + 1 : p2.first + 1;
   p1.second = p2.second < p1.second ? p1.second + 1 : p2.second + 1;
   return p1;
}
bool isRBT(node *root)
{
   if (root == NULL)
   {
      return false;
   }
   if (isLeafNode(root))
   {
      return true;
   }
   bool result = true;
   isRBTUtil(root, result);
   return result;
}
int shortestPath(node *root)
{
   // Function finds the length of the shortest path from root to leaf
   if (root == NULL)
   {
      return INT32_MAX - 100;
   }
   if (isLeafNode(root))
   {
      return 1;
   }
   int l, r;
   l = shortestPath(root->left);
   r = shortestPath(root->right);
   return l < r ? l + 1 : r + 1;
}
bool isCBT(node *root)
{
   // Function the check whether a function is complete binary tree
   if (root == NULL)
   {
      return false;
   }
   queue<node *> q;
   q.push(root);
   bool flag = false;
   while (!q.empty())
   {
      root = q.front();
      q.pop();
      if (flag == false && isLeafNode(root))
      {
         flag = true;
      }
      if (root->left)
      {
         q.push(root->left);
      }
      if (root->right)
      {
         q.push(root->right);
      }
      if (flag && !isLeafNode(root))
      {
         return false;
      }
   }
   return true;
}
bool isFBT(node *root)
{
   // Function to check whether a tree is full binary tree
   if (root == NULL)
   {
      return false;
   }
   stack<node *> s;
   while (root != NULL || !s.empty())
   {
      while (root != NULL)
      {
         s.push(root);
         root = root->left;
      }
      root = s.top();
      s.pop();
      if (hasOneChild(root))
      {
         return false;
      }
      root = root->right;
   }
   return true;
}
bool hasOneChild(node *root)
{
   if (root == NULL)
   {
      return false;
   }
   if (root->left == NULL && root->right != NULL)
   {
      return true;
   }
   if (root->left != NULL && root->right == NULL)
   {
      return true;
   }
   return false;
}
void printAllPaths(node *root)
{
   if (root == NULL)
   {
      return;
   }
   vector<pair<int, int>> p;
   printAllPathsUtil(root, p, 0);
}
void printAllPathsUtil(node *root, vector<pair<int, int>> p, int pos)
{
   if (root == NULL)
   {
      return;
   }
   p.push_back(make_pair(root->data, pos));
   if (isLeafNode(root))
   {
      int m = INT32_MAX;
      for (int i = 0; i < p.size(); i++)
      {
         m = m < p[i].second ? m : p[i].second;
      }
      for (int i = 0; i < p.size(); i++)
      {
         for (int j = 0; j < (p[i].second - m); j++)
         {
            cout << '_';
         }
         cout << p[i].first << endl
              << endl;
      }
      return;
   }
   printAllPathsUtil(root->left, p, pos - 1);
   printAllPathsUtil(root->right, p, pos + 1);
}
bool isPFB(node *root)
{
   if (root == NULL)
   {
      return false;
   }
   if (countNodes(root) == ((1 << height(root)) - 1))
   {
      return true;
   }
   else
   {
      return false;
   }
}
bool isHeap(int arr[], int n)
{
   if (n < 2)
   {
      return false;
   }
   for (int i = 0; i < n / 2; i++)
   {
      if (2 * i + 1 < n && arr[2 * i + 1] < arr[i])
      {
         return false;
      }
      if (2 * i + 2 < n && arr[2 * i + 2] < arr[i])
      {
         return false;
      }
   }
   return true;
}
bool isDivisible(node *root)
{
   if (root == NULL)
   {
      return false;
   }
   int result = 0;
   int n = countNodes(root);
   if (n & 1)
   {
      return false;
   }
   isDivisibleUtil(root, n, result);
   return result > 0 ? true : false;
}
int isDivisibleUtil(node *root, int n, int &result)
{
   if (root == NULL)
   {
      return 0;
   }
   int s = 0;
   s += 1;
   s += isDivisibleUtil(root->left, n, result);
   s += isDivisibleUtil(root->right, n, result);
   if (n - s == s)
   {
      result++;
   }
   return s;
}
int countNodes(node *root)
{
   return (root == NULL) ? 0 : (1 + countNodes(root->left) + countNodes(root->right));
}
bool checkSameLevelLeafUtil(node *root, int level, int x)
{
   if (root == NULL)
   {
      return true;
   }
   if (isLeafNode(root))
   {
      return (x == level) ? true : false;
   }
   bool l = checkSameLevelLeafUtil(root->left, level, x + 1);
   bool r = checkSameLevelLeafUtil(root->right, level, x + 1);
   return l && r;
}
bool isLeafNode(node *root)
{
   return (root->left == NULL && root->right == NULL) ? true : false;
}
bool checkSameLevelLeaf(node *root)
{
   // Function to check all leaf nodes are at same level
   if (root == NULL)
   {
      return false;
   }
   node *a = root;
   int level = 0;
   while (a != NULL)
   {
      level++;
      a = a->left;
   }
   return checkSameLevelLeafUtil(root, level, 1);
}
int leafNodeSum(node *root)
{
   if (root == NULL)
   {
      return 0;
   }
   if (root->left == NULL && root->right == NULL)
   {
      return root->data;
   }
   else
   {
      return leafNodeSum(root->left) + leafNodeSum(root->right);
   }
}
bool checkCoveredUncoveredSum(node *root)
{
   // A node which is neither boundary node, nor a leaf node is called a covered node
   // A node which is either leaf node or boundary node is called uncovered node
   // Check whether the sum covered and uncovered nodes is same or not
   if (root == NULL)
   {
      return false;
   }
   // Finding left boundary sum
   node *a = root;
   int uncvsum = 0;
   while (a->left != NULL)
   {
      uncvsum += a->data;
      a = a->left;
   }
   a = root->right;
   while (a != NULL && a->right != NULL)
   {
      uncvsum += a->data;
      a = a->right;
   }
   uncvsum += leafNodeSum(root);
   if (uncvsum == (sumAllNodes(root) - uncvsum))
   {
      return true;
   }
   else
   {
      return false;
   }
}
int sumAllNodes(node *root)
{
   if (root == NULL)
   {
      return 0;
   }
   return root->data + sumAllNodes(root->left) + sumAllNodes(root->right);
}
int isSumTree2Util(node *root, bool *result)
{
   if (root == NULL)
   {
      return 0;
   }
   if (root->left == NULL && root->right == NULL)
   {
      return root->data;
   }
   int l = root->left == NULL ? 0 : isSumTree2Util(root->left, result);
   int r = root->right == NULL ? 0 : isSumTree2Util(root->right, result);
   *result = *result && (root->data == l + r);
   return l + r + root->data;
}
bool isSumTree2(node *root)
{
   if (root == NULL)
   {
      return true;
   }
   bool result = true;
   isSumTree2Util(root, &result);
   return result;
}
int treeSum(node *root)
{
   if (root == NULL)
   {
      return 0;
   }
   return root->data + treeSum(root->left) + treeSum(root->right);
}
bool isSumTree1(node *root)
{
   if (root == NULL)
   {
      return true;
   }
   if (root->left == NULL && root->right == NULL)
   {
      return true;
   }
   int l, r;
   l = r = 0;
   l = root->left ? treeSum(root->left) : 0;
   r = root->right ? treeSum(root->right) : 0;
   return (l + r == root->data) && isSumTree1(root->left) && isSumTree1(root->right);
}
bool checkCSP(node *root)
{
   if (root == NULL)
   {
      return true;
   }
   if (root->left == NULL && root->right == NULL)
   {
      return true;
   }
   int childsum = (root->left == NULL ? 0 : root->left->data) + (root->right == NULL ? 0 : root->right->data);
   return (childsum == root->data) && checkCSP(root->left) && checkCSP(root->right);
}
int modifyTree3(node *root)
{
   // The function converts the tree to logical AND tree
   // Each node is a logical AND of it's left child and right child
   // Each node contains either 0 or 1
   if (root->left == NULL && root->right == NULL)
   {
      return root->data;
   }
   int l, r;
   l = modifyTree3(root->left);
   r = modifyTree3(root->right);
   root->data = (l & r);
   return root->data;
}
node *treeToDLL3(node *root)
{
   if (root == NULL)
   {
      return NULL;
   }
   node *cur, *prev = NULL;
   int level = 1, count = 1, x = 0;
   deque<node *> dq;
   dq.push_back(root);
   while (!dq.empty())
   {
      x = 0;
      if (level % 2 == 1)
      {
         while (count--)
         {
            cur = dq.back();
            dq.pop_back();
            if (cur->right)
            {
               dq.push_front(cur->right);
               x++;
            }
            if (cur->left)
            {
               dq.push_front(cur->left);
               x++;
            }
            cur->left = prev;
            if (prev != NULL)
            {
               prev->right = cur;
            }
            prev = cur;
         }
         count = x;
      }
      else
      {
         while (count--)
         {
            cur = dq.front();
            dq.pop_front();
            if (cur->left)
            {
               dq.push_back(cur->left);
               x++;
            }
            if (cur->right)
            {
               dq.push_back(cur->right);
               x++;
            }
            cur->left = prev;
            if (prev != NULL)
            {
               prev->right = cur;
            }
            prev = cur;
         }
         count = x;
      }
   }
   prev->right = NULL;
   return root;
}
void printSpiralOrder(node *root)
{
   if (root == NULL)
   {
      return;
   }
   deque<node *> dq;
   int count, level;
   count = level = 1;
   dq.push_back(root);
   while (!dq.empty())
   {
      int x = 0;
      if (level % 2 == 1)
      {
         while (count--)
         {
            node *cur = dq.back();
            dq.pop_back();
            cout << cur->data << " ";
            if (cur->right)
            {
               dq.push_front(cur->right);
               x++;
            }
            if (cur->left)
            {
               dq.push_front(cur->left);
               x++;
            }
         }
         count = x;
      }
      else
      {
         while (count--)
         {
            node *cur = dq.front();
            dq.pop_front();
            cout << cur->data << " ";
            if (cur->left)
            {
               dq.push_back(cur->left);
               x++;
            }
            if (cur->right)
            {
               dq.push_back(cur->right);
               x++;
            }
         }
         count = x;
      }
      level++;
      cout << endl;
   }
}
void mirror(node *root)
{
   // Modifies the tree as mirror image
   if (root == NULL)
      return;
   mirror(root->left);
   swap(root->left, root->right);
   mirror(root->left);
}
int modifyTree2(node *root)
{
   // The function modifies the current node as sum of curnode + sum of all nodes in left subtree
   // The function returns the sum of left subtree,current node and right subtree
   if (root == NULL)
   {
      return 0;
   }
   if (root->left == NULL && root->right == NULL)
   {
      return root->data;
   }
   int leftsum = modifyTree2(root->left);
   int rightsum = modifyTree2(root->right);
   root->data += leftsum;
   return root->data + rightsum;
}
void implementCSP(node *root)
{
   if (root->left == NULL && root->right == NULL)
   {
      return;
   }
   int x = (root->left == NULL ? 0 : root->left->data) + (root->right == NULL ? 0 : root->right->data);
   if (x > root->data)
   {
      root->data = x;
   }
   if (x < root->data)
   {
      int diff = root->data - x;
      if (root->left != NULL)
      {
         node *child = root->left;
         while (child != NULL)
         {
            child->data += diff;
            child = child->left;
         }
      }
      else
      {
         node *child = root->right;
         while (child != NULL)
         {
            child->data += diff;
            child = child->right;
         }
      }
   }
}
void modifyTree1(node *root)
{
   // The function modifies the binary tree so that every node follows the child sum property
   // The value of a node can only be incremented
   if (root == NULL)
   {
      return;
   }
   modifyTree1(root->left);
   modifyTree1(root->right);
   implementCSP(root);
}
void treeToDLL2Util(node *root, vector<node *> &nodes)
{
   if (root == NULL)
   {
      return;
   }
   treeToDLL2Util(root->left, nodes);
   nodes.push_back(root);
   treeToDLL2Util(root->right, nodes);
}
node *treeToDLL2(node *root)
{
   if (root == NULL)
   {
      return NULL;
   }
   vector<node *> nodes;
   treeToDLL2Util(root, nodes);
   nodes[0]->left = NULL;
   for (int i = 0; i < nodes.size() - 1; i++)
   {
      nodes[i]->left = nodes[i - 1];
      nodes[i]->right = nodes[i + 1];
   }
   nodes[nodes.size() - 1]->right = NULL;
   return nodes[0];
}
void treeToDLLUtil(node *root)
{
   static node *next = NULL;
   if (root == NULL)
   {
      return;
   }
   treeToDLL(root->right);
   root->right = next;
   if (next != NULL)
   {
      next->left = root;
   }
   next = root;
   treeToDLL(root->left);
}
node *treeToDLL(node *root)
{
   // Converts the given the BTree to a doubly linked list in place
   // Inorder Fashion
   // Returns the head of the resulting DoublyLinkedList
   if (root == NULL)
   {
      return NULL;
   }
   node *a = root;
   while (a->left != NULL)
   {
      a = a->left;
   }
   treeToDLLUtil(root);
   a->left = NULL;
   return a;
}
int search1(int in[], int strt, int end, int key)
{
   for (int i = strt; i <= end; i++)
   {
      if (in[i] == key)
      {
         return i;
      }
   }
}
node *buildInPostUtil(int in[], int post[], int instrt, int inend, int *p)
{
   if (instrt > inend)
   {
      return NULL;
   }
   node *root = newNode(post[*p]);
   (*p)--;
   if (instrt == inend)
   {
      return root;
   }
   int pos = search1(in, instrt, inend, root->data);
   root->right = buildInPostUtil(in, post, pos + 1, inend, p);
   root->left = buildInPostUtil(in, post, instrt, pos - 1, p);
   return root;
}
node *buildInPost(int in[], int post[], int n)
{
   int p = n - 1;
   return buildInPostUtil(in, post, 0, n - 1, &p);
}
int findMaxIndex(int in[], int n)
{
   int idx = -11;
   int m = INT32_MIN;
   for (int i = 0; i < n; i++)
   {
      if (in[i] > m)
      {
         m = in[i];
         idx = i;
      }
   }
   return idx;
}
node *buildFromHeap(int in[], int n)
{
   // Given the inorder traversal of a maxheap, construct the tree
   if (n == 0)
   {
      return NULL;
   }
   else if (n == 1)
   {
      return newNode(in[0]);
   }
   else
   {

      int pos = findMaxIndex(in, n);
      node *root = newNode(in[pos]);
      int x, y;
      x = pos;
      y = n - x - 1;
      int leftin[x], rightin[y];
      for (int i = 0; i < x; i++)
      {
         leftin[i] = in[i];
      }
      for (int i = 0; i < y; i++)
      {
         rightin[i] = in[i + pos + 1];
      }
      root->left = buildFromHeap(leftin, x);
      root->right = buildFromHeap(rightin, y);
      return root;
   }
}
node *buildPrePreUtil(int pre[], int post[], int n)
{
   if (n == 0)
   {
      return NULL;
   }
   else if (n == 1)
   {
      node *temp = newNode(pre[0]);
      return temp;
   }
   else
   {
      node *root = newNode(pre[0]);
      int pos = findRoot(post, pre[1], n);
      int x, y;
      x = pos + 1;
      y = n - x - 1;
      int leftpre[x], leftpost[x], rightpre[y], rightpost[y];
      for (int i = 0; i < x; i++)
      {
         leftpre[i] = pre[i + 1];
         leftpost[i] = post[i];
      }
      for (int i = 0; i < y; i++)
      {
         rightpre[i] = pre[i + x + 1];
         rightpost[i] = post[i];
      }
      root->left = buildPrePreUtil(leftpre, leftpost, x);
      root->right = buildPrePreUtil(rightpre, rightpost, y);
      return root;
   }
}
node *buildPrePre(int pre[], int mpre[], int n)
{
   // Construct s full binary binary tree from preorder of a tree and preorder of it's mirror tree
   for (int i = 0; i < n / 2; i++)
   {
      swap(mpre[i], mpre[n - i - 1]);
   }
   node *root = buildPrePreUtil(pre, mpre, n);
   return root;
}
node *buildPrePost(int pre[], int post[], int n)
{
   // Given the preorder and postorder of a full binary tree
   // Construct the full binary tree
   // In a full binary tree except leaf nodes, all nodes have 2 children
   // if size of pre is greater than 3 then pre[1] will be the root of leftsubtree
   // We find the position of pre[1] in postorder,that is the end of the left subtree in postorder as pre[1] is root

   /*
       1
     /   \
   2      3
        /   \
       4     5
           /   \
          6    7


          1
        /   \
      2       3
    /  \     /  \
   4    5   6    7
 /  \
8    9
   */
   if (n == 0)
   {
      return NULL;
   }
   else if (n == 1)
   {
      node *temp = newNode(pre[0]);
      return temp;
   }
   else
   {
      node *root = newNode(pre[0]);
      int pos = findRoot(post, pre[1], n);
      int x, y;
      x = pos + 1;
      y = n - x - 1;
      int leftpre[x], leftpost[x], rightpre[y], rightpost[y];
      for (int i = 0; i < x; i++)
      {
         leftpre[i] = pre[i + 1];
         leftpost[i] = post[i];
      }
      for (int i = 0; i < y; i++)
      {
         rightpre[i] = pre[x + 1 + i];
         rightpost[i] = post[x + i];
      }
      root->left = buildPrePost(leftpre, leftpost, x);
      root->right = buildPrePost(rightpre, rightpost, y);
      return root;
   }
}
node *buildFromArray(int arr[], int n)
{
   if (n == 0)
   {
      return NULL;
   }
   node *root = newNode(arr[0]);
   queue<node *> q;
   q.push(root);
   int i = 1;
   while (i < n)
   {
      node *cur = q.front();
      q.pop();
      if (i < n)
      {
         cur->left = newNode(arr[i++]);
         q.push(cur->left);
      }
      if (i < n)
      {
         cur->right = newNode(arr[i++]);
         q.push(cur->right);
      }
   }
   return root;
}
node *buildFromLL(llist<int> &l)
{
   // The inorder traversal of a binary tree is given as linked list construct
   // The binary tree
   lnode<int> *a = l.first;
   if (!a)
   {
      return NULL;
   }
   queue<node *> q;
   node *root = newNode(a->data);
   node *t;
   q.push(root);
   while (a != NULL)
   {
      t = q.front();
      q.pop();
      if (a->next != NULL)
      {
         t->left = newNode(a->next->data);
         a = a->next;
         q.push(t->left);
      }
      else
      {
         break;
      }
      if (a->next != NULL)
      {
         t->right = newNode(a->next->data);
         a = a->next;
         q.push(t->right);
      }
      else
      {
         break;
      }
   }

   return root;
}

template <class X>
void llist<X>::display()
{
   a = first;
   if (!a)
   {
      return;
   }
   while (a != NULL)
   {
      cout << a->data << " ";
      a = a->next;
   }
}
template <class X>
llist<X>::llist()
{
   first = last = NULL;
}
template <class X>
void llist<X>::append(X value)
{
   a = new lnode<X>;
   a->next = NULL;
   a->data = value;
   if (first == NULL)
   {

      first = last = a;
   }
   else
   {

      last->next = a;
      last = a;
   }
}
node *modifyTreeUtil(node *p)
{
   p = p->left;
   while (p->right != NULL)
   {
      p = p->right;
   }
   return p;
}
void modifyTree(node *root)
{
   if (root == NULL)
   {
      return;
   }
   node *p, *pred;
   p = root;
   while (p != NULL)
   {
      if (p->left != NULL)
      {
         pred = modifyTreeUtil(p);
         pred->right = p->right;
         p->right = p->left;
         p->left = NULL;
         p = p->right;
      }
      else
      {
         p = p->right;
      }
   }
}
int densityUtil(node *root, double *count)
{
   if (root)
   {
      int l = densityUtil(root->left, count);
      int r = densityUtil(root->right, count);
      *count += 1.0;
      return l > r ? l + 1 : r + 1;
   }
   else
   {
      return 0;
   }
}
double density(node *tree)
{
   if (tree == NULL)
   {
      return 0.0;
   }
   double count = 0.0;
   int h = densityUtil(tree, &count);
   return count / (double)h;
}
void printBoundaryUtil1(node *root)
{
   // Prints the left boundary starting from root
   if (root == NULL)
   {
      return;
   }
   if (root->left || root->right)
   {
      cout << root->data << " ";
   }
   printBoundaryUtil1(root->left);
}
void printBoundaryUtil2(node *root)
{
   if (root == NULL)
   {
      return;
   }
   printBoundaryUtil2(root->left);
   if (root->left == NULL && root->right == NULL)
   {
      cout << root->data << " ";
   }
   printBoundaryUtil2(root->right);
}
void printBoundaryUtil3(node *root)
{
   if (root == NULL)
   {
      return;
   }
   printBoundaryUtil3(root->right);
   if (root->right != NULL || root->left != NULL)
   {
      cout << root->data << " ";
   }
}
void printBoundary(node *root)
{
   if (root == NULL)
   {
      return;
   }
   printBoundaryUtil1(root);
   printBoundaryUtil2(root);
   printBoundaryUtil3(root->right);
}
void iterativeDiagonalOrder(node *root)
{
   if (root == NULL)
   {
      return;
   }
   queue<node *> q;
   while (root != NULL)
   {
      if (root->left != NULL)
      {
         q.push(root->left);
      }
      cout << root->data << " ";
      if (root->right != NULL)
      {
         root = root->right;
      }
      else
      {
         if (q.empty())
         {
            root = NULL;
         }
         else
         {
            root = q.front();
            q.pop();
         }
      }
   }
}
void diagonalOrderUtil(node *tree, int d, queue<int> q[])
{
   if (tree == NULL)
   {
      return;
   }
   q[d].push(tree->data);
   diagonalOrderUtil(tree->left, d + 1, q);
   diagonalOrderUtil(tree->right, d, q);
}
void diagonalOrder(node *root)
{
   if (root == NULL)
   {
      return;
   }
   int h = height(root);
   h += 2;
   queue<int> q[h];
   diagonalOrderUtil(root, 0, q);
   for (int i = 0; i < h; i++)
   {
      while (!q[i].empty())
      {
         cout << q[i].front() << " ";
         q[i].pop();
      }
      cout << endl;
   }
}
void postOrder(node *root)
{
   if (root == NULL)
   {
      return;
   }
   postOrder(root->left);
   postOrder(root->right);
   cout << root->data << " ";
}
void iterativePostorder(node *root)
{
   if (root == NULL)
   {
      return;
   }
   stack<node *> s1;
   stack<int> s2;
   s2.push(root->data);
   s1.push(root);
   node *cur = root->right;
   while (!s1.empty() || cur != NULL)
   {
      while (cur != NULL)
      {
         s1.push(cur);
         s2.push(cur->data);
         cur = cur->right;
      }
      cur = s1.top();
      s1.pop();
      cur = cur->left;
   }
   while (!s2.empty())
   {
      cout << s2.top() << " ";
      s2.pop();
   }
}
void iterativePreorder(node *root)
{
   if (root == NULL)
   {
      return;
   }
   stack<node *> s;
   s.push(root);
   node *cur = root->left;
   s.push(root);
   cout << root->data << " ";
   while (!s.empty())
   {
      while (cur != NULL)
      {
         cout << cur->data << " ";
         s.push(cur);
         cur = cur->left;
      }
      cur = s.top();
      s.pop();
      cur = cur->right;
   }
}
void morrisPreorder(node *root)
{
   if (root == NULL)
   {
      return;
   }
   node *cur, *a;
   cur = root;
   while (cur != NULL)
   {
      if (cur->left == NULL)
      {
         cout << cur->data << " ";
         cur = cur->right;
      }
      else
      {
         a = cur->left;
         while (a->right != NULL && a->right != cur)
         {
            a = a->right;
         }
         if (a->right == NULL)
         {
            a->right = cur;
            cout << cur->data << " ";
            cur = cur->left;
         }
         else
         {
            a->right = NULL;
            cur = cur->right;
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
   node *cur, *a;
   cur = root;
   while (cur != NULL)
   {
      if (cur->left == NULL)
      {
         cout << cur->data << " ";
         cur = cur->right;
      }
      else
      {
         node *a = cur->left;
         while (a->right != NULL && a->right != cur)
         {
            a = a->right;
         }
         if (a->right == NULL)
         {
            a->right = cur;
            cur = cur->left;
         }
         else
         {
            cout << cur->data << " ";
            cur = cur->right;
            a->right = NULL;
         }
      }
   }
}
void fillArr(node *root, vector<int> &arr, int level)
{
   if (root == NULL)
   {
      return;
   }
   fillArr(root->left, arr, level + 1);
   if (level % 2 == 0)
   {
      arr.push_back(root->data);
   }
   fillArr(root->right, arr, level + 1);
}
void fillLevels(node *root, vector<int> &arr, int level)
{
   if (root == NULL)
   {
      return;
   }
   static int i = arr.size() - 1;
   fillLevels(root->left, arr, level + 1);
   if (level % 2 == 0)
   {
      root->data = arr[i--];
   }
   fillLevels(root->right, arr, level + 1);
}
void reverseAlternateLevels(node *root)
{
   // Given a perfect binary
   // Reverse the alternate levels of the PFB
   if (root == NULL)
   {
      return;
   }
   vector<int> arr;
   fillArr(root, arr, 1);
   fillLevels(root, arr, 1);
}
void levelOrderLinebyLine(node *root)
{
   // This function prints level order line by line
   if (root == NULL)
   {
      return;
   }
   queue<node *> q;
   q.push(root);
   int count = 1;
   while (!q.empty())
   {
      int x = 0;
      while (count--)
      {
         root = q.front();
         cout << root->data << " ";
         q.pop();
         if (root->left)
         {
            q.push(root->left);
            x++;
         }
         if (root->right)
         {
            q.push(root->right);
            x++;
         }
      }
      cout << endl;
      count = x;
   }
}
void specialLevelOrder4(node *root)
{
   /*1
    / \
   2   3
  / \   / \
 4   5  6  7
   */
   // Given a genral binary tree
   // Processing two nodes at a time
   // OutPut::::: 4 7 5 6 2 3 1
   // Reverse of specialLevelOrder1() ie staring from the lower level
   if (root == NULL)
   {
      return;
   }
   if (root->left && root->right)
   {
      stack<int> s;
      deque<int> dq;
      queue<int> q2;
      queue<node *> q1;
      int curlevel = 0;
      node *curnode = NULL;
      q1.push(root);
      q2.push(0);
      while (!q1.empty())
      {
         while (curlevel == q2.front())
         {
            curnode = q1.front();
            q1.pop();
            q2.pop();
            dq.push_back(curnode->data);
            if (curnode->left)
            {
               q1.push(curnode->left);
               q2.push(curlevel + 1);
            }
            if (curnode->right)
            {
               q1.push(curnode->right);
               q2.push(curlevel + 1);
            }
         }
         curlevel++;
         bool check = true;
         while (!dq.empty())
         {
            if (check)
            {
               s.push(dq.front());
               dq.pop_front();
            }
            else
            {
               s.push(dq.back());
               dq.pop_back();
            }
            check = check ? false : true;
         }
      }
      while (!s.empty())
      {
         cout << s.top() << " ";
         s.pop();
      }
   }
}
void specialLevelOrder3(node *root)
{
   /*1
    / \
   2   3
  / \   / \
 4   5  6  7
   */
   // Given a perfect binary tree
   // Processing two nodes at a time
   // OutPut::::: 4 7 5 6 2 3 1
   // Reverse of specialLevelOrder1() ie staring from the lower level
   stack<int> s;
   queue<node *> q;
   if (root == NULL)
   {
      return;
   }
   if (root->left && root->right)
   {
      q.push(root->left);
      q.push(root->right);
      s.push(root->data);
      node *a, *b;
      while (!q.empty())
      {
         a = q.front();
         q.pop();
         b = q.front();
         q.pop();
         s.push(a->data);
         s.push(b->data);
         if (a->left)
         {
            q.push(a->left);
         }
         if (b->right)
         {
            q.push(b->right);
         }
         if (a->right)
         {
            q.push(a->right);
         }
         if (b->left)
         {
            q.push(b->left);
         }
      }
      while (!s.empty())
      {
         cout << s.top() << " ";
         s.pop();
      }
   }
}
void specialLevelOrder2(node *root)
{
   /*1
    / \
   2   3
  / \   / \
 4   5  6  7*/
   // Output :::  1 2 3 4 7 5 6
   cout << root->data << " ";
   queue<node *> q;
   q.push(root->left);
   q.push(root->right);
   while (!q.empty())
   {
      node *a, *b;
      a = q.front();
      q.pop();
      b = q.front();
      q.pop();
      if (a->left)
      {
         q.push(a->left);
      }
      if (b->right)
      {
         q.push(b->right);
      }
      if (a->right)
      {
         q.push(a->right);
      }
      if (b->left)
      {
         q.push(b->left);
      }
      cout << a->data << " " << b->data << " ";
   }
}
void specialLevelOrder(node *tree)
{

   /*1
    / \
   2   3
  / \   / \
  4   5  6  7
  */
   // Given a perfect binary tree
   //  Output :::  1 2 3 4 7 5 6
   if (tree == NULL)
   {
      return;
   }
   int curlevel = 0;
   node *curnode = tree;
   queue<int> q2;
   queue<node *> q1;
   q1.push(tree);
   q2.push(0);
   deque<int> dq;
   while (!q1.empty())
   {
      while (curlevel == q2.front())
      {
         curnode = q1.front();
         q1.pop();
         q2.pop();
         dq.push_back(curnode->data);
         if (curnode->left)
         {
            q1.push(curnode->left);
            q2.push(curlevel + 1);
         }
         if (curnode->right)
         {
            q1.push(curnode->right);
            q2.push(curlevel + 1);
         }
      }
      bool check = true;
      curlevel++;
      while (!dq.empty())
      {
         if (check)
         {
            cout << dq.front() << " ";
            dq.pop_front();
         }
         else
         {
            cout << dq.back() << " ";
            dq.pop_back();
         }
         check = (check) ? false : true;
      }
      cout << endl;
   }
}
void reversePathUtil(node *tree, int key, vector<node *> path)
{
   if (tree == NULL)
   {
      return;
   }
   path.push_back(tree);
   if (tree->data == key)
   {
      // Reverse the path vector
      int n = path.size();
      for (int i = 0; i < n / 2; i++)
      {
         int temp;
         temp = path[i]->data;
         path[i]->data = path[n - i - 1]->data;
         path[n - i - 1]->data = temp;
      }
      return;
   }
   reversePathUtil(tree->left, key, path);
   reversePathUtil(tree->right, key, path);
}
void reversePath(node *tree, int key)
{
   if (tree == NULL)
   {
      return;
   }
   vector<node *> path;
   reversePathUtil(tree, key, path);
}
vector<int> reverseInorder(node *p)
{
   vector<int> res;
   stack<int> s;
   queue<node *> q;
   q.push(p);
   while (!q.empty())
   {
      p = q.front();
      q.pop();
      s.push(p->data);
      if (p->left)
      {
         q.push(p->left);
      }
      if (p->right)
      {
         q.push(p->right);
      }
   }
   while (!s.empty())
   {
      res.push_back(s.top());
      s.pop();
   }
   return res;
}
void updateNext(node *p, node *key, node **next)
{
   if (p == NULL || key == NULL)
   {
      return;
   }
   updateNext(p->right, key, next);
   if (key != p)
   {
      *next = p;
   }
   else
   {
      return;
   }
   updateNext(p->left, key, next);
}
node *inorderSuccessor(node *p, node *key)
{
   if (p->right)
   {
      // Case 1: The right node exists
      p = p->right;
      while (p->left != NULL)
      {
         p = p->left;
      }
      return p;
   }
   else
   {
      // Case 2: The right node doesn't exist
      node *next = NULL;
      updateNext(p, key, &next);
      return next;
   }
}
node *findLeftMost(node *p)
{
   while (p->left != NULL)
   {
      p = p->left;
   }
   return p;
}
void spiralOrder2(node *p)
{
   if (p == NULL)
   {
      return;
   }
   stack<node *> s1, s2;
   s1.push(p);
   while (!s1.empty() || !s2.empty())
   {
      if (s2.empty())
      {
         while (!s1.empty())
         {
            p = s1.top();
            s1.pop();
            cout << p->data << " ";
            if (p->right)
            {
               s2.push(p->right);
            }
            if (p->left)
            {
               s2.push(p->left);
            }
         }
      }
      else
      {
         while (!s2.empty())
         {
            p = s2.top();
            s2.pop();
            cout << p->data << " ";
            if (p->left)
            {
               s1.push(p->left);
            }
            if (p->right)
            {
               s1.push(p->right);
            }
         }
      }
      cout << endl;
   }
}
void printLevel(node *tree, int level)
{
   if (tree == NULL)
   {
      return;
   }
   if (level == 1)
   {
      cout << tree->data << " ";
      return;
   }
   printLevel(tree->left, level - 1);
   printLevel(tree->right, level - 1);
}
void printRL(node *tree, int level)
{
   if (tree == NULL)
   {
      return;
   }
   if (level == 1)
   {
      cout << tree->data << " ";
      return;
   }
   printRL(tree->right, level - 1);
   printRL(tree->left, level - 1);
}
void printLR(node *tree, int level)
{
   if (tree == NULL)
   {
      return;
   }
   if (level == 1)
   {
      cout << tree->data << " ";
      return;
   }
   printLR(tree->left, level - 1);
   printLR(tree->right, level - 1);
}
void spiralOrder(node *tree)
{
   if (tree == NULL)
   {
      return;
   }
   int h = height(tree);
   bool check = true;
   for (int i = 1; i <= h; i++)
   {
      if (check)
      {
         cout << "RL    ";
         printRL(tree, i);
      }
      else
      {
         cout << "LR    ";
         printLR(tree, i);
      }
      check = check ? false : true;
      cout << endl;
   }
}
void NthInorderNode(node *p, int n)
{
   if (n == 0)
   {
      return;
   }
   stack<node *> s;
   while (p != NULL || !s.empty())
   {
      while (p != NULL)
      {
         s.push(p);
         p = p->left;
      }
      if (p == NULL)
      {
         p = s.top();
         s.pop();
         n -= 1;
         if (n == 0)
         {
            cout << "\nNth node of inorder is= " << p->data << endl;
            return;
         }
         p = p->right;
      }
   }
}
void iterativeInOrder(node *p)
{
   stack<node *> s;
   while (p != NULL || !s.empty())
   {
      while (p != NULL)
      {
         s.push(p);
         p = p->left;
      }
      if (p == NULL)
      {
         p = s.top();
         s.pop();
         cout << p->data << " ";
         p = p->right;
      }
   }
}
void populateRandom(node *p)
{
   // This function sets random node with inorder successor
   static node *next = NULL;
   if (p)
   {
      populateRandom(p->right);
      p->random = next;
      next = p;
      populateRandom(p->left);
   }
}
void helper_func1(node *t, vector<int> &in)
{
   if (t == NULL)
   {
      return;
   }
   else
   {
      helper_func1(t->left, in);
      in.push_back(t->data);
      helper_func1(t->right, in);
   }
}
void helper_func2(node *t, vector<int> &in)
{
   static int i = 0;
   if (t == NULL)
   {
      return;
   }
   else
   {

      helper_func2(t->left, in);
      t->data = in[i++];
      helper_func2(t->right, in);
   }
}
void replaceWithSuccessor(node *tree)
{
   vector<int> in;
   helper_func1(tree, in);
   vector<int> newin(in.size());
   for (int i = 1; i < in.size() - 1; i++)
   {
      newin[i] = (in[i - 1] + in[i + 1]);
   }
   newin[0] = in[1];
   newin[in.size() - 1] = in[in.size() - 2];
   helper_func2(tree, newin);
}
void postFromInPre(int in[], int pre[], int n)
{
   int root = findRoot(in, pre[0], n);
   if (root != 0)
   {
      postFromInPre(in, pre + 1, root);
   }
   if (root != n - 1)
   {
      postFromInPre(in + root + 1, pre + root + 1, n - root - 1);
   }
   cout << pre[0] << " ";
}
int findRoot(int in[], int key, int n)
{
   for (int i = 0; i < n; i++)
   {
      if (in[i] == key)
      {
         return i;
      }
   }
   return -1;
}
node *createInPre(int in[], int pre[], int n)
{
   if (n == 0)
   {
      return NULL;
   }
   else if (n == 1)
   {
      node *a = newNode(pre[0]);
      return a;
   }
   else
   {
      int pos = findRoot(in, pre[0], n);
      int x, y;
      x = pos;
      y = n - pos - 1;
      int leftin[x], leftpre[x], rightin[y], rightpre[y];
      for (int i = 0; i < x; i++)
      {
         leftin[i] = in[i];
         leftpre[i] = pre[i + 1];
      }
      for (int i = 0; i < y; i++)
      {
         rightin[i] = in[i + pos + 1];
         rightpre[i] = pre[i + pos + 1];
      }
      node *a = newNode(pre[0]);
      a->left = createInPre(leftin, leftpre, x);
      a->right = createInPre(rightin, rightpre, y);
      return a;
   }
}
void joinNodes(node *tree)
{
   if (tree == NULL)
   {
      return;
   }
   queue<int> q1;
   queue<node *> q2;
   q1.push(0);
   q2.push(tree);
   node *curnode;
   int curlevel;
   while (!q2.empty())
   {
      curlevel = q1.front();
      q1.pop();
      curnode = q2.front();
      q2.pop();
      if (q2.empty() || curlevel != q1.front())
      {
         curnode->random = NULL;
      }
      else
      {

         curnode->random = q2.front();
      }
      if (curnode->left)
      {
         q1.push(curlevel + 1);
         q2.push(curnode->left);
      }
      if (curnode->right)
      {
         q1.push(curlevel + 1);
         q2.push(curnode->right);
      }
   }
}
int height(node *tree)
{
   if (tree != NULL)
   {
      int l, r;
      l = height(tree->left);
      r = height(tree->right);
      return l > r ? l + 1 : r + 1;
   }
   else
   {
      return 0;
   }
}
bool checkSubtree(node *T, node *S)
{
   if (S == NULL)
   {
      return true;
   }
   if (T == NULL)
   {
      return false;
   }
   if (T->data == S->data && treeMatch(T, S))
   {
      return true;
   }
   return checkSubtree(T->left, S) || checkSubtree(T->right, S);
}
bool treeMatch(node *T, node *S)
{
   if (T == NULL)
   {
      return false;
   }
   else
   {
      bool c1, c2;
      c1 = c2 = false;
      if (S->left)
      {
         c1 = treeMatch(T->left, S->left);
      }
      else
      {
         c1 = true;
      }
      if (S->right)
      {
         c2 = treeMatch(T->right, S->right);
      }
      else
      {
         c2 = true;
      }
      return (T->data == S->data) && c1 && c2;
   }
}
void preOrder1(node *a)
{
   if (a == NULL)
   {
      return;
   }
   cout << a->data << " ";
   preOrder1(a->left);
   preOrder1(a->right);
}
void levelOrder1(node *tree)
{
   if (tree == NULL)
   {
      return;
   }
   queue<node *> q;
   q.push(tree);
   while (!q.empty())
   {
      node *a = q.front();
      cout << a->data << " ";
      if (a->left)
      {
         q.push(a->left);
      }
      if (a->right)
      {
         q.push(a->right);
      }
      q.pop();
   }
}
node *createTree()
{
   int x;
   cin >> x;
   node *root;
   if (x == -1)
   {
      root = NULL;
      return root;
   }
   node *a;
   a = newNode(x);

   root = a;
   queue<node *> q;
   q.push(root);
   while (!q.empty())
   {
      a = q.front();
      cin >> x;
      if (x != -1)
      {
         a->left = newNode(x);
         q.push(a->left);
      }
      cin >> x;
      if (x != -1)
      {
         a->right = newNode(x);
         q.push(a->right);
      }
      q.pop();
   }
   return root;
}
node *newNode(int x)
{
   node *temp = new node;
   temp->left = temp->right = temp->random = NULL;
   temp->data = x;
   return temp;
}