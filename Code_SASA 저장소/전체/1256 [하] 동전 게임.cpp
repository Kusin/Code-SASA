#include<stdio.h>
int cnt,M,N;
int abs(int a){
	return a>0?a:-a;
}
void f(int m,int n){ 
	if(n==0){
		if(abs(m)==M)
			cnt++;
		return;
	}
	if(abs(m)>=M)
		return;
	f(m-1,n-1);
	f(m+1,n-1);
}
int main(){
	scanf("%d%d",&M,&N);
	if((M%2)==(N%2))
		f(0,N);
	printf("%d",cnt);
}
