#include<iostream>
#include<cstring>
using namespace std;
class dsu
{
    int *maxSize,*minSize,*maxPar,*minPar;
    int n;
    int get_Min_Par(int a);
    int get_Max_Par(int a);
    void UnionMax(int a,int b);
    void UnionMin(int a,int b);
    public:
    dsu()
    {
        n = 3e5+1;
        maxSize = new int[n];
        minSize = new int[n];
        maxPar = new int[n];
        minPar = new int[n];
        for(int i=0;i<n;i++)
        {
            maxSize[i] = 1;
            minSize[i] = 1;
            maxPar[i] = i;
            minPar[i] = i;
        }
    }
    void Union(int a,int b);
    int getMin(int a);
    int getMax(int a);
    int getSize(int a);
};
int main()
{
    int n,q;
    cin>>n>>q;
    dsu d;
    for(int i=0;i<q;i++)
    {
        char s[20];
        scanf("%s" , s);
        if(strcmp(s , "union") == 0)
        {
            int a,b;
            cin>>a>>b;
            d.Union(a,b);
        }
        else
        {
            int a;
            cin>>a;
            cout<<d.getMin(a)<<" "<<d.getMax(a)<<" "<<d.getSize()<<"\n";
        }
    }
    return 0;
}
int dsu::getMin(int a)
{
    return get_Min_Par(a);
}
int dsu::getMax(int a)
{
    return get_Max_Par(a);
}
void dsu::Union(int a,int b)
{
    UnionMax(a,b);
    UnionMin(a,b);
}
int dsu::get_Min_Par(int i)
{
    if(minPar[i] == i)
        return i;
    else
    {
        int temp = get_Min_Par(minPar[i]);
        minPar[i] = temp;
        return temp;
    }
}
int dsu::get_Max_Par(int i)
{
    if(maxPar[i] == i)
        return i;
    else
    {
        int temp = get_Max_Par(maxPar[i]);
        maxPar[i] = temp;
        return temp;
    }
}
void dsu::UnionMax(int a,int b)
{
    a = get_Max_Par(a);
    b = get_Max_Par(b);
    if(a != b)
    {
        if(a > b)
        {
            // a is parent of b
            maxPar[b] = a;
            maxSize[a] += maxSize[b];
        }
        else
        {
            //b is parent of a
            maxPar[a] = b;
            maxSize[b] += maxSize[a];
        }
    }
}
void dsu::UnionMin(int a,int b)
{
    a = get_Min_Par(a);
    b = get_Min_Par(b);
    if(a != b)
    {
        if(a > b)
        {
            //b is parent of a
            minPar[a] = b;
            minSize[b] += minSize[a];
        }
        else
        {
            //a is parent of b
            minPar[b] = a;
            minSize[a] += minSize[b];
        }
    }
}