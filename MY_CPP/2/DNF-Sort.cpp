#include<iostream>
#include<vector>
using namespace std;
/*int arr[]={1,0,2,1,0,2,1,0,2,1,0,2,1,0,2,1,0,1,0,2,1,0,2,1,0,2,1,1,1,2,1,2,1,2,1,2,2,1,1,2,1,2,0,1,2,1,0,1,1};
void swap(int a,int b)
{
   int temp=arr[a];
   arr[a]=arr[b];
   arr[b]=temp;
}
int main()
{ 
   int n=sizeof(arr)/sizeof(arr[0]);
   int low=0,mid=0,high=n-1;
   while(mid<=high)
   {
      if(arr[mid]==2)
      {
         swap(mid,high);
         high--;
      }
      else if(arr[mid]==1)
      {
         mid++;
      }
      else 
      {
         swap(low,mid);
         mid++;low++;
      }
   }
   for(int i=0;i<n;i++)
   {
      cout<<arr[i]<<" ";
   }
   return 0;
}*/

//using vecto notations
#include<iostream>
#include<vector>
using namespace std;
int main()
{
   vector<int> v;
   int num;
   for(int i=0;i<10;i++)
   {
      cin>>num;
      v.push_back(num);
   }

   int n=v.size();
   int mid=0,low=0,high=n-1;
   
}