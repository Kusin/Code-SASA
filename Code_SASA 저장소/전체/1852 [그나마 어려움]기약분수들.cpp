#include<stdio.h>
int n,cnt;
int gcd(int a,int b){
	if(a==0)
		return b;
	return gcd(b%a,a);
}
int sol(int k){
	int cnt=0;
	
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<(n+1)/2){
		cnt+=sol(i);
	}
	printf("%d",cnt)
}
