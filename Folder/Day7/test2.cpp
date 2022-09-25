#include <bits/stdc++.h>
using namespace std;

struct suffix
{
   int index;
   int rank[2];
};
int cmp(struct suffix a, struct suffix b)
{
   return (a.rank[0] == b.rank[0]) ? (a.rank[1] < b.rank[1] ? 1 : 0) : (a.rank[0] < b.rank[0] ? 1 : 0);
}
vector<int> buildSuffixArray(string txt, int n)
{
   struct suffix suffixes[n];
   for (int i = 0; i < n; i++)
   {
      suffixes[i].index = i;
      suffixes[i].rank[0] = txt[i] - 'a';
      suffixes[i].rank[1] = ((i + 1) < n) ? (txt[i + 1] - 'a') : -1;
   }
   sort(suffixes, suffixes + n, cmp);
   int ind[n];
   for (int k = 4; k < 2 * n; k = k * 2)
   {
      int rank = 0;
      int prev_rank = suffixes[0].rank[0];
      suffixes[0].rank[0] = rank;
      ind[suffixes[0].index] = 0;
      for (int i = 1; i < n; i++)
      {
         if (suffixes[i].rank[0] == prev_rank &&
             suffixes[i].rank[1] == suffixes[i - 1].rank[1])
         {
            prev_rank = suffixes[i].rank[0];
            suffixes[i].rank[0] = rank;
         }
         else
         {
            prev_rank = suffixes[i].rank[0];
            suffixes[i].rank[0] = ++rank;
         }
         ind[suffixes[i].index] = i;
      }
      for (int i = 0; i < n; i++)
      {
         int nextindex = suffixes[i].index + k / 2;
         suffixes[i].rank[1] = (nextindex < n) ? suffixes[ind[nextindex]].rank[0] : -1;
      }
      sort(suffixes, suffixes + n, cmp);
   }
   vector<int> suffixArr;
   for (int i = 0; i < n; i++)
      suffixArr.push_back(suffixes[i].index);
   return suffixArr;
}
bool isSubstring(string key, vector<int> &p, string &s)
{
   if (key.size() > s.size())
   {
      return false;
   }
   else
   {
      bool flag = true;
      int low = 0;
      int high = s.size() - 1;
      while (low <= high)
      {
         int mid = (low + high) / 2;
         string seg = s.substr(p[mid], key.size());
         if (seg == key)
         {
            return true;
            flag = false;
            break;
         }
         else if (seg > key)
         {
            high = mid - 1;
         }
         else
         {
            low = mid + 1;
         }
      }
      if (flag)
      {
         return false;
      }
   }
}
int main()
{
   string s;
   int t, n;
   bool flag;
   cin >> s;
   vector<int> p = buildSuffixArray(s, s.size());

   n = s.size();
   cin >> t;
   while (t--)
   {
      string key;
      flag = true;
      cin >> key;
      if (!isSubstring(key, p, s))
      {
         cout << 0 << endl;
      }
      else
      {
         int lb = -1;
         int ub = -1;
      }
   }
   return 0;
}
