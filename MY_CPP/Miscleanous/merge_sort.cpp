/*#include<iostream>
#include<string>
using namespace std;
void merge(int arr[],int l,int mid,int r)
{
   int n1=mid-l+1;
   int n2=r-mid;
   int a[n1];
   int b[n2];   
   for(int i=0;i<n1;i++)
   {
      a[i]=arr[l+i];
   }

   for(int i=0;i<n2;i++)
   {
      b[i]=arr[mid+i+1];
   }
   
   int i=0,j=0,k=l;

   while(i<n1 && j<n2)
   {
      if(a[i]<b[j])
      {
         arr[k]=a[i];
         k++;
         i++;
      }
      else
      {
         arr[k]=b[j];
         k++;
         j++;
      }
   }

   while(i<n1)
   {
      arr[k++]=a[i++];
   }

   while(j<n2)
   {
      arr[k++]=b[j++];
   }

}


void mergeSort(int arr[], int l, int r)
{   if(l<r)
   {  int mid=(l+r)/2;
      mergeSort(arr,l,mid);
      mergeSort(arr,mid+1,r);
      merge(arr,l,mid,r);
   }
}

int main()
{
   int arr[]={3,2};
   mergeSort(arr,0,1);
   for(int i=0;i<2;i++)
   {
      cout<<arr[i]<<" ";
   }
   cout<<endl;
   return 0;

}*/


#include<iostream>
using namespace std;
int arr[]={8,7,6,5,4,3,2,1};

void merge(int l,int mid,int h)
{
   int n1,n2;                             
   n1=mid-l+1;
   n2=h-mid;
   int a[n1],b[n2];
   for(int i=0;i<n1;i++)
   {
      a[i]=arr[i+l];
   }
   for(int i=0;i<n2;i++)
   {
      b[i]=arr[i+1+mid];
   }
   int i=0,j=0,k=l;
   while(i<n1 && j<n2)
   {
      if(a[i]<b[j])
      {
         arr[k]=a[i];
         k++;
         i++;
      }
      else
      {
         arr[k]=b[j];
         k++;
         j++;
      }
   }


   while(i<n1)
   {
      arr[k++]=a[i++];
   }
   while(j<n2)
   {
      arr[k++]=b[j++];
   }
}

void mergesort(int l,int h)
{
   int mid=(l+h)/2;
   if(l<h)
   {
      mergesort(l,mid);
      mergesort(mid+1,h);
      merge(l,mid,h);
   }
}
int main()
{
   int n=sizeof(arr)/sizeof(arr[0]);
   mergesort(0,n-1);
   for(int i=0;i<n;i++)
   {
      cout<<arr[i]<<" ";
   }

   return 0;
}
