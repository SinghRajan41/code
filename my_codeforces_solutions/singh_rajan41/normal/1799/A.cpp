#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<int> ans(n+1,-1),q(n+m+5);
		int pos=n;
		for(int k=0;k<m;k++){
			int x;
			cin>>x;
			if(pos>0&&!q[x]) ans[pos--]=k+1;
			q[x]=1;
		}
		for(int k=1;k<=n;k++) cout<<ans[k]<<" ";
		cout<<endl;
	}
}