#include<stdio.h>
int T,a,b,c;
int main(){
	scanf("%d",&T);
	while(T){
		scanf("%d%d%d",&a,&b,&c);
		puts(a+b+1>=c&&a+c+1>=b&&b+c+1>=a?"YES":"NO");
		T--;
	}return 0;
}