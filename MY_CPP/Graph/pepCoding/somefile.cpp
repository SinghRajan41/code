#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fio                      \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);                   \
   cout.tie(0);
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repe(i, a, b) for (int i = a; i <= b; i++)
#define w(x) \
   int x;    \
   cin >> x; \
   while (x--)
#define F first
#define S second
#define all(x) x.begin(), x.end()

#define input(v)    \
   for (int &a : v) \
   cin >> a
#define pb push_back
#define mod 1000000007
template <class T>
using vi = vector<T>;
template <class T1, class T2>
using umap = unordered_map<T1, T2>;
template <typename T>
class dsu
{
public:
   vector<T> size;
   vector<T> parent;
   dsu(int sz)
   {
      size.resize(sz + 1);
      parent.resize(sz + 1);
   }
   void make(T a)
   {
      size[a] = 1;
      parent[a] = a;
   }
   T find(T a)
   {
      if (a == parent[a])
         return a;
      return parent[a] = find(parent[a]);
   }
   void makeunion(T a, T b)
   {
      a = find(a);
      b = find(b);
      if (a != b)
      {
         if (size[a] > size[b])
         {
            parent[b] = a;
            size[a] += size[b];
         }
         else
         {
            parent[a] = b;
            size[b] += size[a];
         }
      }
   }
   int sizenode(T a)
   {
      return size[find(a)];
   }
};
int binpow(int a, int b)
{
   int res = 1;
   while (b)
   {
      if (b & 1)
         res *= a;
      a = a * a;
      b >>= 1;
   }
   return res;
}
int32_t main()
{
   fio int t, w, l;
   cin >> t >> w >> l;
   vi<pair<int, int>> v(t);
   int st = 0, en = 1e18;
   for (auto &a : v)
      cin >> a.F >> a.S;

   int op = 0;
   while (st <= en)
   {
      int mid = (st + en) / 2, ans = 0LL;
      for (auto a : v)
      {
         if ((a.F + a.S * mid) >= l)
            ans += (a.F + a.S * mid);
         if (ans >= w)
            break;
      }
      if (ans >= w)
      {
         op = mid;
         en = mid - 1;
      }
      else
         st = mid + 1;
   }
   cout << op << '\n';
   cerr
       << "processor time: " << clock() / (double)CLOCKS_PER_SEC << "s    ";

   return 0;
}