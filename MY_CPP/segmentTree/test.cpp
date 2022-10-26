#include <bits/stdc++.h>
using namespace std;
void solve();
struct node
{
   int i;
   node *left, *right;
};
node *newNode(int x);
bool cmp(pair<long long int, long long int> &a, pair<long long int, long long int> &b);
void removeNode(node *n);
void solve2();
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      solve2();
   }
   return 0;
}
bool cmp(pair<long long int, long long int> &a, pair<long long int, long long int> &b)
{
   return a.first < b.first;
}
void removeNode(node *n)
{

   if (n->left && n->right)
   {
      n->left->right = n->right;
      n->right->left = n->left;
   }
   else if (n->left || n->right)
   {
      if (n->right)
      {
         n->right->left = NULL;
      }
      else
      {
         n->left->right = NULL;
      }
   }
   if (n)
   {
      delete n;
   }
}
void solve()
{
   int n;
   cin >> n;
   long long int a[n], b[n];
   for (int i = 0; i < n; i++)
      cin >> a[i];
   for (int j = 0; j < n; j++)
      cin >> b[j];
   vector<pair<long long int, long long int>> c(n);
   for (int i = 0; i < n; i++)
      c[i] = {b[i], (long long int)i};
   sort(c.begin(), c.end(), cmp);
   node *d[n];
   node *p, *q;
   p = q = NULL;
   for (int i = 0; i < n; i++)
   {
      node *temp = newNode(i);
      if (p == NULL)
      {
         p = q = temp;
      }
      else
      {
         q->right = temp;
         temp->left = q;
         q = temp;
      }
      d[i] = temp;
   }
   long long int cost = 0;
   for (int i = 0; i < n; i++)
   {
      int idx = c[i].second;
      int incr = c[i].first;
      cost += a[idx];
      if (d[idx]->left)
      {
         int j = d[idx]->left->i;
         a[j] += incr;
      }
      if (d[idx]->right)
      {
         int j = d[idx]->right->i;
         a[j] += incr;
      }
      removeNode(d[idx]);
   }
   cout << cost << endl;
}
void solve2()
{
   int n;
   cin >> n;
   long long int a[n], b[n];
   for (int i = 0; i < n; i++)
      cin >> a[i];
   for (int j = 0; j < n; j++)
      cin >> b[j];
   long long int cost = 0;
   for (int i = 0; i < n; i++)
   {
      cost += a[i];
   }
   sort(b, b + n);
   for (int i = 0; i < n - 1; i++)
   {
      cost += b[i];
   }
   cout << cost << endl;
}
node *newNode(int x)
{
   node *temp = new node;
   temp->left = temp->right = NULL;
   temp->i = x;
   return temp;
}
