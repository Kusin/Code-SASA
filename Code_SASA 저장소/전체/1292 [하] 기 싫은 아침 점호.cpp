#include<stdio.h>
#define num 15
int n;
long long int fac(long long int n){
	if(n<=1)
		return 1;
	return fac(n-1)*n;
}
int main(){
	scanf("%d",&n);
	long long int ans=1;
	ans*=fac(num-n);
	for(int i=num-n+2;i<=num;i++)
		ans*=i;
	printf("%lld",ans);
} 
