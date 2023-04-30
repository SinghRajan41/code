#include<iostream>
using namespace std;
int main()
{
	int t,j;
	cin>>t;
	for(j=0;j<t;j++)
	{
		int x;
		cin>>x;
		cout<<x+((x-1)/9)<<'\n';
	}
}