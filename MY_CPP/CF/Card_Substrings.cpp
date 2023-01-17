#include<iostream>
using namespace std;
class map
{
    int freq[26],neg;
    public:
    map()
    {
        neg = 0;
        for(int i=0;i<26;i++)   freq[i] = 0;
    }
    void add(char x)
    {
        freq[x-'a']++;
        if(freq[x-'a'] == 0)
            neg--;
    }
    void remove(char x)
    {
        freq[x - 'a']--;
        if(freq[x-'a'] == -1)
            neg++;
    }
    bool hasNeg()
    {
        return neg > 0 ? true:false;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    char s[n],t[m];
    for(int i=0;i<n;i++)    cin>>s[i];
    for(int i=0;i<m;i++)    cin>>t[i];
    unsigned long long int ans = 0;
    int l,r;
    l = r = 0;
    map mp;
    for(int i=0;i<m;i++)
    {
        mp.add(t[i]);
    }
    for(;r<n;r++)
    {
        mp.remove(s[r]);
        while(mp.hasNeg())
        {
            mp.add(s[l++]);
        }
        if(l<=r)
            ans += (r-l+1);
    }
    cout<<ans<<"\n";
    return 0;
}