#include<iostream>
int t,n,h,m;
main(){
	for(scanf("%d",&t);t--;){
		scanf("%d%d%d",&h,&n,&m);
		for(;h>m*10 && n--;h=h/2+10);
		puts(h>m*10?"NO":"YES");
	}
	return 0;
}