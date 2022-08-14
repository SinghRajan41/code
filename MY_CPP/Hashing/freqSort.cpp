#include <iostream>
#include <vector>
#include <utility>
using namespace std;
class maxHeap
{
public:
   pair<int, int> *harr;
   int n, size;
   maxHeap()
   {
      size = 50000;
      n = -1;
      harr = new pair<int, int>[size];
   }
   bool isGreater(pair<int, int> &a, pair<int, int> &b)
   {
      if (a.second == b.second)
      {
         return a.first < b.first;
      }
      return a.second > b.second;
   }
   void insert(pair<int, int> value)
   {
      if (n == size - 1)
      {
         cout << "\nHeap is Full\n";
         return;
      }
      else
      {
         harr[++n] = value;
         int i = n;
         while (i > 0)
         {
            if (isGreater(harr[i], harr[(i - 1) / 2]))
            {
               swap(harr[i], harr[(i - 1) / 2]);
            }
            i = (i - 1) / 2;
         }
      }
   }
   void showHeap()
   {
      for (int i = 0; i <= n; i++)
      {
         cout << harr[i].first << " " << harr[i].second << endl;
      }
   }
   bool empty()
   {
      return n == -1 ? true : false;
   }
   void deleteRoot()
   {
      if (n == -1)
      {
         cout << "\n Heap is empty\n";
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
   pair<int, int> peekRoot()
   {
      pair<int, int> p;
      if (n == -1)
      {
         p.first = p.second = INT32_MIN;
      }
      else
      {
         p.first = harr[0].first;
         p.second = harr[0].second;
         return p;
      }
   }
   void pushDown(int i)
   {
      int j = 2 * i + 1;
      if (j + 1 <= n && isGreater(harr[j + 1], harr[j]))
      {
         j++;
      }
      if (j <= n && isGreater(harr[j], harr[(j - 1) / 2]))
      {
         swap(harr[j], harr[(j - 1) / 2]);
         pushDown(j);
      }
   }
};
vector<int> freqSort(int arr[], int n)
{
   // Sorts the elements of the array based on decreasing order of frequency of elements
   int freq[100001] = {0};
   for (int i = 0; i < n; i++)
   {
      freq[arr[i]]++;
   }
   maxHeap h;
   for (int i = 0; i < 100001; i++)
   {
      if (freq[i] > 0)
      {
         pair<int, int> p;
         p.first = i;
         p.second = freq[i];
         h.insert(p);
      }
   }
   vector<int> res;
   while (!h.isFull())
   {
      res.push_back(h.peekRoot().first);
      h.deleteRoot();
   }
   return res;
}
int main()
{
   int n;
   cin >> n;
   int arr[n];
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }
   auto res = freqSort(arr, n);
   for (auto i = 0; i < res.size(); i++)
   {
      cout << res[i] << " ";
   }

   return 0;
}