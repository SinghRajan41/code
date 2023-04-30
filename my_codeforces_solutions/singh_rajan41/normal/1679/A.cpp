#include<iostream>
#include<algorithm>
#define ll long long int
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a = 1ll;
        if(n%2==1)
            cout<<-1<<"\n";
        else
        {
            if(n==2)
                {cout<<-1<<endl;continue;}
            if(n%4 == 0 && n%6 == 0)
                cout<<n/6<<" "<<n/4<<"\n";
            else if(n%4 == 0 || n%6 == 0)
            {
                if(n%6==0)
                    cout<<(n/6)<<" "<<(n/4)<<endl;
                else
                    cout<<(n/6 + 1)<<" "<<(n/4)<<endl;
            }
            else
            {
                cout<<(n/6 + 1)<<" "<<(n/4 + 0)<<endl;
            }

        }
    }
    return 0;
}
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