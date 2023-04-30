#include<iostream>
#include<algorithm>
#define ll long long int
using namespace std;
int arr[100001];
int n;
void solve(int arr[],int n);
class minHeap
{
    public:
    int harr[10000];
    int n;
    int size;
    
    minHeap()
    {
        n=-1;
        size=10000;
    }
    void insert(int data)
    {
        if(n==size-1)
            return;
        else
        {
            harr[++n] = data;
            int i = n;
            while(i>0)
            {
                if(harr[i] < harr[(i-1)/2])
                {
                    swap(harr[i],harr[(i-1)/2]);
                }
                i = (i-1) / 2;
            }
        }
    }
    int remove()
    {
        if(n==-1)
            return -1;
        else if(n==0)
        {
            n--;
            return harr[0];
        }
        else
        {
            int rvalue = harr[0];
            swap(harr[n] , harr[0]);
            n-=1;
            int i = 0;
            while(i<=n)
            {
                int j = 2*i+1;
                if(j+1<=n && harr[j] > harr[j+1])
                    j+=1;
                if(j<=n && harr[j] < harr[i])
                {
                    swap(harr[j],harr[i]);
                }
                i = j;
            }
            return rvalue;
        }
    }
    bool empty()
    {
        return n == -1 ? true:false;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        solve(arr,n);
        
    }
    return 0;
}
void solve(int arr[],int n)
{
    if(n==1)
    {
        cout<<-1<<endl;
        return;
    }
    else
    {
        int res[n];
        int arrcp[n];
        for(int i=0;i<n;i++)
            arrcp[i] = arr[i];
        for(int i=0;i<n;i++)
        {
            int idx = i;
            int Min = INT32_MAX;
            for(int j = 0;j<n;j++)
            {
                if(j != i)
                {
                    if(arr[j] < Min)
                    {
                        Min = arr[j];
                        idx = j;
                    }
                }
            }
            res[i] = arr[idx];
            arr[idx] = INT32_MAX;
        }
        if(res[n-1] == arrcp[n-1])
        {
            swap(res[n-1],res[n-2]);
        }
        for(int i=0;i<n;i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
}