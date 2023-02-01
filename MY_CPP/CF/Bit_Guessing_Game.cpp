#include<iostream>
using namespace std;
int main()
{
    int t;  cin>>t;
    for(int i=0;i<t;i++)
    {
        int l,r,m;  l = 1;  r = (int)1e9;
        int ans = 0;
        int cnt;    cin>>cnt;
        do
        {
            m = (l + r)>>1;
            int q = m - ans;
            cout<<"- "<<q<<"\n";
                cin>>cnt;
            if(cnt == 0)
            {
                ans += q;
                break;
            }
            else if(cnt == -1)
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
                ans += q;
            }
        }while(l<=r);
        cout<<"! "<<ans<<"\n";
    }
    return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
int main(){
	int t=1;
	cin>>t;
	while(t--){
		int x,ans=0,curr=1,temp=0,z,vk;
		cin>>x;
		while(x>temp){
			cout<<"- "<<curr<<endl;
			cin>>vk;
			z=vk-x;
			for(int i=0;i<z+1;i++)curr*=2;
			temp+=(z+1);
			ans+=curr;
			curr*=2;
			x=vk;
		}
		cout<<"! "<<ans<<endl;
	}
}*/