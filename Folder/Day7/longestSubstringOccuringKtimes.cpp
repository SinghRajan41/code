// Given a substring find maximum length of a substring occuring atleast k times
#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
pair<int, int> slidingWindow(vector<int> &arr, int n, int k);
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
vector<int> kasai(string txt, vector<int> suffixArr)
{
   int n = suffixArr.size();
   vector<int> lcp(n, 0);
   vector<int> invSuff(n, 0);
   for (int i = 0; i < n; i++)
      invSuff[suffixArr[i]] = i;
   int k = 0;
   for (int i = 0; i < n; i++)
   {
      if (invSuff[i] == n - 1)
      {
         k = 0;
         continue;
      }
      int j = suffixArr[invSuff[i] + 1];
      while (i + k < n && j + k < n && txt[i + k] == txt[j + k])
         k++;
      lcp[invSuff[i]] = k;
      if (k > 0)
         k--;
   }
   return lcp;
}
int main()
{
   string s;
   cin >> s;
   vector<int> sa = buildSuffixArray(s, s.size());
   vector<int> lcp = kasai(s, sa);
   int k;
   cin >> k;
   if (k == 1)
   {
      cout << s << endl;
   }
   else
   {
      pair<int, int> p = slidingWindow(lcp, s.size(), k - 1);
      cout << s.substr(p.second, p.first);
   }
   return 0;
}
pair<int, int> slidingWindow(vector<int> &arr, int n, int k)
{
   deque<int> dq;
   pair<int, int> res = {-1, -1};
   for (int i = 0; i < k; i++)
   {
      while (!dq.empty() && arr[i] < arr[dq.front()])
      {
         dq.pop_front();
      }
      dq.push_front(i);
   }
   for (int i = k; i < n; i++)
   {
      if (arr[dq.back()] > res.first)
      {
         res.second = dq.back();     // starting position of the window
         res.first = arr[dq.back()]; // minimum length of the window
      }
      while (!dq.empty() && dq.back() < i - k + 1)
      {
         dq.pop_back();
      }
      while (!dq.empty() && arr[i] < arr[dq.front()])
      {
         dq.pop_front();
      }
      dq.push_front(i);
   }
   if (!dq.empty())
   {
      if (arr[dq.back()] > res.first)
      {
         res.second = dq.back();     // starting position of the window
         res.first = arr[dq.back()]; // minimum length of the window
      }
   }
   return res;
}