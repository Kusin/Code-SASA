#include<stdio.h>
int n,a,b,cnt;
int main(){
	scanf("%d%d%d",&n,&a,&b);
	a--,b--;
	while(a!=b){
		a/=2;
		b/=2;
		cnt++;
	}
	printf("%d",cnt);
}
