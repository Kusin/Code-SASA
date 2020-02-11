#include<stdio.h>
int n,m;
int max(int a,int b){ return a>b?a:b;}
int f(int a,int b){
	if(a*b==1) return 1;
	if(a==1||b==1){
		a=max(a,b);
		return a/2+((a+1)/2)-f((a+1)/2,1);
	}
	return max((a/2)*b+((a+1)/2)*b-f((a+1)/2,b) , a*(b/2)+a*((b+1)/2)-f(a,(b+1)/2));
}
int main(){
	scanf("%d%d",&n,&m);
	printf("%d",f(n,m));
}
