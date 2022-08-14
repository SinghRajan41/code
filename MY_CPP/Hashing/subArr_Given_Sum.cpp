// Print a subarray whose sum is equal to the given sum
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
void subArrGivenSum(int arr[], int n, int k)
{
   unordered_map<int, int> map;
   int curSum = 0;
   int count = 0;
   for (int i = 0; i < n; i++)
   {
      curSum += arr[i];
      if (curSum == k)
      {
         count++;
      }
      if (map.find(curSum - k) != map.end())
      {
         count += map[curSum - k];
      }
      map[curSum]++;
   }
   cout << count;
}
void printAll(int arr[], int n, int k)
{
   // function to print all subarrays having sum equal to k
   unordered_map<int, vector<int>> map;
   vector<pair<int, int>> res;
   long long int sum = 0;
   for (int i = 0; i < n; i++)
   {
      sum += arr[i];
      if (sum == k)
      {
         res.push_back(make_pair(0, i));
      }
      if (map.find(sum - k) != map.end())
      {
         vector<int> temp = map[sum - k];
         for (int j = 0; j < temp.size(); j++)
         {
            res.push_back(make_pair(temp[j] + 1, i));
         }
      }
      map[sum].push_back(i);
   }
   for (int i = 0; i < res.size(); i++)
   {
      int a = res[i].first;
      int b = res[i].second;
      while (a <= b)
      {
         cout << arr[a] << " ";
         a++;
      }
      cout << endl;
   }
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
   printAll(arr, n, k);
   return 0;
}
// C++ program to print subarray with sum as given sum
// #include <bits/stdc++.h>
// using namespace std;

// // Function to print subarray with sum as given sum
// void subArraySum(int arr[], int n, int sum)
// {
//    // create an empty map
//    unordered_map<int, int> map;

//    // Maintains sum of elements so far
//    int curr_sum = 0;

//    for (int i = 0; i < n; i++)
//    {
//       // add current element to curr_sum
//       curr_sum = curr_sum + arr[i];

//       // if curr_sum is equal to target sum
//       // we found a subarray starting from index 0
//       // and ending at index i
//       if (curr_sum == sum)
//       {
//          cout << "Sum found between indexes "
//               << 0 << " to " << i << endl;
//       }

//       // If curr_sum - sum already exists in map
//       // we have found a subarray with target sum
//       if (map.find(curr_sum - sum) != map.end())
//       {
//          cout << "Sum found between indexes "
//               << map[curr_sum - sum] + 1
//               << " to " << i << endl;
//       }

//       map[curr_sum] = i;
//    }

//    // If we reach here, then no subarray exists
//    cout << "No subarray with given sum exists";
// }

// // Driver program to test above function
// int main()
// {
//    int arr[] = {10, 2, -2, -20, 10};
//    int n = sizeof(arr) / sizeof(arr[0]);
//    int sum = -10;

//    subArraySum(arr, n, sum);

//    return 0;
// }
