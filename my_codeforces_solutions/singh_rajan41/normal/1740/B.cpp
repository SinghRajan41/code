#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
class cmp
{
public:
   bool operator()(pair<int, int> a, pair<int, int> b)
   {
      return a.first + a.second < b.first + b.second;
   }
};
#define findAns(x, y) (x.first + x.second + x.first + abs(x.second - y.second))
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin >> n;
      int l, b;
      int arr[n];
      long long int ans = 0;
      for (int i = 0; i < n; i++)
      {
         cin >> l >> b;
         if (l < b)
         {
            ans += 2 * l;
            arr[i] = b;
         }
         else
         {
            ans += 2 * b;
            arr[i] = l;
         }
      }
      sort(arr, arr + n);
      for (int i = 0; i < n - 1; i++)
      {
         ans += abs(arr[i] - arr[i + 1]);
      }
      ans += arr[0];
      ans += arr[n - 1];
      cout << ans << endl;
   }
   return 0;
}

/*


std::priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
      for (int i = 0; i < n; i++)
      {
         pair<int, int> a;
         cin >> a.first >> a.second;
         pq.push(a);
      }
      std::deque<pair<int, int>> dq;
      pair<int, int> a, b, c;
      a = pq.top();
      pq.pop();
      if (a.first > a.second)
      {
         swap(a.first, a.second);
      }
      dq.push_front(a);
      while (!pq.empty())
      {
         bool left = true;
         a = pq.top();
         pq.pop();
         b = a;
         int ans = INT32_MAX;
         int temp = findAns(a, dq.front());
         if (temp < ans)
         {
            temp = ans;
            b = a;
            left = true;
         }
         swap(a.first, a.second);
         temp = findAns(a, dq.front());
         if (temp < ans)
         {
            ans = temp;
            left = true;
            b = a;
         }
         temp = findAns(a, dq.back());
         if (temp < ans)
         {
            ans = temp;
            left = false;
            b = a;
         }
         swap(a.first, a.second);
         temp = findAns(a, dq.back());
         if (temp < ans)
         {
            temp = ans;
            b = a;
            left = false;
         }
         if (left)
         {
            dq.push_front(b);
         }
         else
         {
            dq.push_back(b);
         }
      }
      long long int ans = 0;
      vector<int> arr;
      while (!dq.empty())
      {
         a = dq.front();
         dq.pop_front();
         ans += 2 * a.first;
         arr.push_back(a.second);
      }
      for (int i = 0; i < arr.size() - 1; i++)
      {
         ans += abs(arr[i] - arr[i + 1]);
      }
      if (arr.size())
      {
         ans += arr[0];
         ans += arr[arr.size() - 1];
      }
      cout << ans << endl;*/