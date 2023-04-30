#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int
#define nl cout<<"\n"
using namespace std;
void solve();
bool cmp(pair<ll,ll> a,pair<ll,ll> b);
struct node
{
    ll idx;
    ll x;
    node *next;
};
node *f,*b;

node popBack();
bool empty();
void pushBack(ll idx , ll x);
void pushFront(ll idx , ll x);
node popFront();
node peekFront();
node peekBack();
int main()
{
    f = NULL;
    b = NULL;
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
    ll n;
    cin>>n;
    vector<pair<ll,ll>> arr(n);
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i].second;
        arr[i].first = i+1;
    }
    sort(arr.begin() , arr.end() , cmp);
    pushFront(0 , 0);
    ll dist =0;
    bool flag = true;
    ll ar[n+1];
    ll x = 1;
    for(ll i=0;i<=n;i+=2)
        ar[i] = ar[i+1] = x++;
    for(ll i=0;i<n;i++)
    {
        node a;
        if(flag)
        {
            a = peekFront();
            pushFront(arr[i].first , -(abs(a.x) + 1));
            dist += arr[i].second * 2 * ar[i];
        }
        else
        {
            a = peekBack();
            pushBack(arr[i].first , abs(a.x) + 1);
            dist += arr[i].second * 2 * ar[i];
        }
        flag = flag ? false:true;
    }
    cout<<dist<< "\n";
    while(!empty())
    {
        node a = popFront();
        ar[a.idx] = a.x;
    }
    for(ll i=0;i<=n;i++)
        cout<<ar[i]<<" ";
    cout<<"\n";
}
node peekBack()
{
    node res = {-1 , -1 ,NULL};
    if(b != NULL)
    {
        res.next = b->next;
        res.idx = b->idx;
        res.x = b->x;
    }
    return res;
}
node peekFront()
{
    node res = {-1,-1,NULL};
    if(f != NULL)
    {
        res.next = f->next;
        res.idx = f->idx;
        res.x = f->x;
    }
    return res;
}
bool cmp(pair<ll,ll> a,pair<ll,ll> b)
{
    return a.second > b.second;
}
bool empty()
{
    return f == NULL ? true:false;
}
node popBack()
{
    node res = {-1 , -1 , NULL};
    if(f == NULL)
    {
        return res;
    }
    else if(f==b && b->next == NULL)
    {
        res.idx = f->idx;
        res.x = f->x;
        res.next = f->next;
        f = b = NULL;
    }
    else
    {
        node *temp = f;
        while(temp!= NULL && temp->next != b)
            temp = temp->next;
        res.idx =  b->idx;
        res.x = b->x;
        res.next = b->next;
        b = temp;
        b->next = NULL;
    }
    return res;
}
node popFront()
{
    node res = {-1,-1,NULL};
    if(f == NULL)
    {
        return res;
    }
    else if(f==b && f->next ==NULL)
    {
        res.idx = f->idx;
        res.x = f->x;
        res.next = f->next;
        f = b = NULL;
    }
    else
    {
        res.idx = f->idx;
        res.x = f->x;
        res.next = f->next;
        f = f->next;
    }
    return res;
}
void pushBack(ll idx , ll x)
{
    node *temp = new node;
    temp->next = NULL;
    temp->idx = idx;
    temp->x = x;
    if(f == NULL)
    {
        f = b = temp;
    }
    else
    {
        b->next = temp;
        b = temp;
    }
}
void pushFront(ll idx , ll x)
{
    node *temp = new node;
    temp->next = NULL;
    temp->idx = idx;
    temp->x = x;
    if(f == NULL)
    {
        f = b = temp;
    }
    else
    {
        temp->next = f;
        f = temp;
    }
}