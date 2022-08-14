#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class minHeap
{
public:
   int *harr, n, size;
   minHeap()
   {
      size = 10000;
      harr = new int[size];
      n = -1;
   }
   void insert(int value)
   {
      if (n == size - 1)
      {
         cout << "\nHeap is full";
      }
      else
      {
         harr[++n] = value;
         int i = n;
         while (i > 0)
         {
            if (harr[i] < harr[(i - 1) / 2])
            {
               swap(harr[i], harr[(i - 1) / 2]);
            }
            i = (i - 1) / 2;
         }
      }
   }
   void deleteRoot()
   {
      if (n == -1)
      {
         return;
      }
      else if (n == 0)
      {
         n--;
      }
      else
      {
         swap(harr[0], harr[n]);
         n--;
         pushDown(0);
      }
   }
   void pushDown(int i)
   {
      int j = 2 * i + 1;
      if (j + 1 <= n && harr[j + 1] < harr[j])
      {
         j++;
      }
      if (j <= n && harr[j] < harr[(j - 1) / 2])
      {
         swap(harr[j], harr[(j - 1) / 2]);
         pushDown(j);
      }
   }
   int peekRoot()
   {
      if (n == -1)
      {
         return -1;
      }
      else
      {
         return harr[0];
      }
   }
   bool empty()
   {
      return n == -1 ? true : false;
   }
};
void leastDerangement(int n)
{
   minHeap h;
   for (int i = 1; i <= n; i++)
   {
      h.insert(i);
   }
   stack<int> s;
   int i = 1;
   int count = 100;
   vector<int> res;
   while (!h.empty())
   {
      while (i == h.peekRoot() && !h.empty())
      {
         s.push(h.peekRoot());
         h.deleteRoot();
      }
      if (!h.empty())
         res.push_back(h.peekRoot());
      h.deleteRoot();
      i++;
      while (!s.empty())
      {
         h.insert(s.top());
         s.pop();
      }
      if (count-- == 0)
      {
         break;
      }
   }
   if (n & 1)
      swap(res[res.size() - 1], res[res.size() - 2]);
   for (auto i = res.begin(); i != res.end(); i++)
   {
      cout << (*i) << " ";
   }
}
int main()
{
   leastDerangement(10);
   return 0;
}