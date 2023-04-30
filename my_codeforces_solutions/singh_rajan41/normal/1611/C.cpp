#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int
#define nl cout<<"\n"
using namespace std;
void solve();
struct node{
    int data;
    node *next;
    node *prev;
};
void printArray(int arr[] , int n);
bool check(int p[] , int arr[] , int n);
class dequeue{
    node *f,*b;
    public:
    dequeue(){f = b = NULL;}
    void pushFront(int data);        
    void popFront();          
    int peekFront();         
    void pushBack(int data);
    void popBack();           
    int peekBack();          
    bool empty();             
    node *newNode(int data);  
};
int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return  0;
}
void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int low = 0;
    int high = n-1;
    dequeue dq;
    while(low <= high)
    {
        if(arr[low] > arr[high])
        {    dq.pushFront(arr[low]);
             ++low;
        }
        else
        {    
            dq.pushBack(arr[high]);
            --high;
        }
    }
    int p[n];
    int idx = 0;
    while(!dq.empty())
    {
        p[idx++] = dq.peekFront();
        dq.popFront();
    }
    if(check(p , arr, n))
    {
        printArray(p,n);
    }
    else
    {
        cout<<"-1\n";
    }
}
bool check(int p[] , int arr[] , int n)
{
    dequeue dq;
    int low = 0;
    int high = n-1;
    while(low < high)
    {
        if(p[low] < p[high])
        {
            dq.pushFront(p[low++]);
        }
        else
        {
            dq.pushBack(p[high--]);
        }
    }
    dq.pushBack(p[low]);
    int temp[n];
    int idx = 0;
    while(!dq.empty())
    {
        temp[idx++] = dq.peekFront();
        dq.popFront();
    }
    bool ok = true;
    for(int i=0;i<n;i++)
    {
        if(temp[i] != arr[i])
            ok = false;
    }
    if(ok)
        return true;
    else
    {
        int m = temp[n-1];
        for(int i=n-2;i>=0;i--)
            temp[i+1] = temp[i];
        temp[0] = m;
        ok = true;
        for(int i=0;i<n;i++)
        {
            if(arr[i] != temp[i])
                return false;
        }
    }
    return true;
}
void dequeue::popBack()
{
    if(b==NULL)
        return;
    else if(f==b)
    {
        delete f;
        f = b = NULL;
    }
    else
    {
        node *a = b;
        b = b->prev;
        b->next = NULL;
        delete a;
    }
}
int dequeue::peekBack()
{
    if(b==NULL)
        return -1;
    else
        return b->data;
}
void dequeue::pushBack(int data)
{
    node *temp = newNode(data);
    if(f==NULL)
    {
        f = temp;
        b = temp;
    }
    else
    {
        b->next = temp;
        temp->prev = b;
        b = temp;
    }
}
int dequeue::peekFront()
{
    if(f == NULL)
    {
        return -1;
    }
    else
    {
        return f->data;
    }
}
void dequeue::popFront()
{
    if(f == NULL)
        return;
    else if(f==b && f != NULL)
    {
        delete f;
        f = NULL;
        b = NULL;
    }
    else
    {
        node *temp = f;
        f = f->next;
        delete temp;
        f->prev = NULL;
    }
}
void dequeue::pushFront(int data)
{
    if(f == NULL)
    {
        f = newNode(data);
        b = f;
    }
    else
    {
        node *temp = newNode(data);
        temp->next = f;
        f->prev = temp;
        f = temp;
    }
}
bool dequeue::empty()
{
    return (f==NULL ? true : false);
}

void printArray(int arr[] , int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
node * dequeue::newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}