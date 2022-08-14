#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#define M 214780000

using namespace std;
class maxHeap
{
public:
   int *harr, n, size;
   maxHeap()
   {
      size = 10000;
      n = -1;
      harr = new int[size];
   }
   void heapSort(int arr[], int N)
   {
      n = -1;
      for (int i = 0; i < N; i++)
      {
         insert(arr[i]);
      }
      for (int i = 0; i < N; i++)
      {
         deleteRoot();
      }
      for (int i = 0; i < N; i++)
      {
         cout << harr[i] << " ";
      }
   }
   void insert(int value)
   {
      if (n == size - 1)
      {
         cout << "\nHeap is FUll\n";
         return;
      }
      else
      {
         harr[++n] = value;
         int i = n;
         while (i > 0)
         {
            if (harr[i] > harr[(i - 1) / 2])
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
      if (j + 1 <= n && harr[j + 1] > harr[j])
      {
         j++;
      }
      if (j <= n && harr[j] > harr[(j - 1) / 2])
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
void maxDerangement(int seq[], int n)
{
   int res[n] = {0};
   maxHeap h;
   for (int i = 0; i < n; i++)
   {
      h.insert(seq[i]);
   }
   for (int i = 0; i < n; i++)
   {
      int d = h.peekRoot();
      h.deleteRoot();
      if (d != seq[i] || i == n - 1)
      {
         res[i] = d;
      }
      else
      {
         res[i] = h.peekRoot();
         if (!h.empty())
            h.deleteRoot();
         h.insert(d);
      }
   }
   if (res[n - 1] == seq[n - 1])
   {
      swap(res[n - 1], res[n - 2]);
   }
   for (int i = 0; i < n; i++)
   {
      cout << res[i] << " ";
   }
}
int maxDistinctElement(int arr[], int n, int k)
{
   // Given an array
   // Find the maximum number of distinct elements after removing k elements from the array
   int freq[100001] = {0};
   for (int i = 0; i < n; i++)
   {
      freq[arr[i]]++;
   }
   int count = 0;
   vector<int> f;
   for (int i = 0; i < 100001; i++)
   {
      if (freq[i])
      {
         if (freq[i] == 1)
         {
            count++;
         }
         else
         {
            f.push_back(freq[i] - 1);
         }
      }
   }

   sort(f.begin(), f.end());
   cout << count << endl;
   for (int i = 0; i < f.size(); i++)
   {
      cout << i << " -> " << f[i] << " \n";
      if (k >= f[i])
      {
         count++;
         k -= f[i];
      }
      else
      {
         k = 0;
      }
   }
   cout << endl;
   if (k != 0 && k <= count)
   {
      count -= k;
   }
   return count;
}
void KSumCombi(int a[], int b[], int n, int k)
{
   // Given two arrays of equal size
   // Find out K maximum sum combination
   // Combination is defined as sum an element from first array and second array
   maxHeap h1, h2;
   for (int i = 0; i < n; i++)
   {
      h1.insert(a[i]);
      h2.insert(b[i]);
   }
   for (int i = 0; i < k; i++)
   {
      cout << (h1.peekRoot() + h2.peekRoot()) << endl;
      if (h1.peekRoot() < h2.peekRoot() && !h1.empty())
      {
         h1.deleteRoot();
      }
      else
      {
         h2.deleteRoot();
      }
   }
}
class minHeap
{
public:
   int *harr, n, size;
   minHeap()
   {
      size = 10000;
      n = -1;
      harr = new int[size];
   }
   bool empty()
   {
      return n == -1 ? true : false;
   }
   void insert(int value)
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
};
void medRunInt(int arr[], int n)
{
   cout << arr[0] << "\n"
        << (double)(arr[0] + arr[1]) / 2 << "\n";
   int minCount, maxCount;
   minCount = maxCount = 1;
   minHeap minh;
   maxHeap maxh;
   if (arr[1] >= arr[0])
   {
      minh.insert(arr[1]);
      maxh.insert(arr[0]);
   }
   else
   {
      minh.insert(arr[0]);
      maxh.insert(arr[1]);
   }
   double curMed = (minh.peekRoot() + maxh.peekRoot()) / 2.0;
   for (int i = 2; i < n; i++)
   {
      if (minCount == maxCount)
      {
         if (arr[i] < curMed)
         {
            maxh.insert(arr[i]);
            maxCount++;
            curMed = maxh.peekRoot();
         }
         else
         {
            minh.insert(arr[i]);
            minCount++;
            curMed = minh.peekRoot();
         }

         cout << curMed << "\n";
      }
      else
      {
         if (arr[i] < curMed)
         {
            if (maxCount > minCount)
            {
               // Left side is more heavy
               minh.insert(maxh.peekRoot());
               maxh.deleteRoot();
               maxh.insert(arr[i]);
               minCount++;
            }
            else
            {
               // Right side is more heavy
               maxh.insert(arr[i]);
               maxCount++;
            }
         }
         else
         {
            if (minCount > maxCount)
            {
               // Right side is more heavy
               maxh.insert(minh.peekRoot());
               minh.deleteRoot();
               minh.insert(arr[i]);
               maxCount++;
            }
            else
            {
               // Left side is more
               minh.insert(arr[i]);
               minCount++;
            }
         }

         curMed = (double)(minh.peekRoot() + maxh.peekRoot()) / 2;
         cout << curMed << "\n";
      }
   }
}
void maxTriplet(int arr[], int n)
{
   std::priority_queue<int> h;
   cout << -1 << endl
        << -1 << endl;
   h.push(arr[0]);
   h.push(arr[1]);
   for (int i = 2; i < n; i++)
   {
      h.push(arr[i]);
      int x, y, z;
      x = h.top();
      h.pop();
      y = h.top();
      h.pop();
      z = h.top();
      cout << x * y * z << endl;
      h.push(x);
      h.push(y);
   }
}
void KthLargestSubarraySum(int arr[], int n, int k)
{
   int sum[n];
   sum[0] = arr[0];
   for (int i = 1; i < n; i++)
   {
      sum[i] = sum[i - 1] + arr[i];
   }
   priority_queue<int, vector<int>, greater<int>> h;
   int x;
   for (int i = 0; i < n; i++)
   {
      for (int j = i + 1; j < n; j++)
      {
         x = sum[j] - sum[i];
         if (h.size() < k)
         {
            h.push(x);
         }
         else
         {
            if (x > h.top())
            {
               h.pop();
               h.push(x);
            }
         }
      }
   }

   cout << h.top();
}
void minKProduct(int arr[], int n, int k)
{
   // Given an array of positive integers
   // Print the minimum product of k Integers
   // Method 1
   sort(arr, arr + n);
   long long int res = 1;
   for (int i = 0; i < k; i++)
   {
      res *= arr[i];
   }
   cout << res;
}
int main()
{
   int n, k;
   cin >> n >> k;
   int arr[n];
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }
   minKProduct(arr, n, k);
   return 0;
}
