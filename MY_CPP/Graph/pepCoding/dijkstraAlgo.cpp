#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class priorityQueue
{
public:
   pair<int, int> *harr;
   int n, size;

   priorityQueue()
   {
      n = -1;
      size = 500;
      harr = new pair<int, int>[size];
   }
   void insert(pair<int, int> value)
   {

      if (n == size - 1)
      {
         cout << "\nPriority Queue is full";
         return;
      }
      harr[++n] = value;
      int i = n;
      while (i > 0)
      {
         if (harr[i].second < harr[(i - 1) / 2].second)
         {
            swap(harr[i], harr[(i - 1) / 2]);
         }
         i = (i - 1) / 2;
      }
   }
   bool empty()
   {
      return n == -1 ? true : false;
   }
   pair<int, int> peekRoot()
   {
      return (n == -1 ? harr[0] : harr[n]);
   }
   void pushDown(int i)
   {
      int j = 2 * i + 1;
      if (j + 1 <= n && harr[j + 1].second < harr[j].second)
      {
         j++;
      }
      if (j <= n && harr[j].second < harr[(j - 1) / 2].second)
      {
         swap(harr[j], harr[(j - 1) / 2]);
         pushDown(j);
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
         n -= 1;
         pushDown(0);
      }
   }
};

int main()
{
   /*priorityQueue pq;
   for (int i = 1; i <= 10; i++)
   {
      pq.insert(make_pair(100, i));
   }
   for (int i = 0; i < 10; i++)
   {
      cout << pq.peekRoot().second << " ";
      pq.deleteRoot();
   }*/
   priority_queue<pair<int, int>> pq;
   for (int i = 1; i <= 10; i++)
   {
      pq.push(make_pair(i, 100));
   }
   for (int i = 1; i < 11; i++)
   {
      cout << pq.top().first << " ";
      pq.pop();
   }
   return 0;
}