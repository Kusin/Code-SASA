#include<stdio.h>
#define MOD 12345
int n,flag=1;
long long ans;
void solve(int n){
	long long fac=1;
	if(n<=1){
		ans=1^n;
		return;
	}
	if(n%2) flag=-1;
	for(int i=n;i>=2;i--,flag*=-1){
		ans+=fac*flag;
		ans%=MOD;
		fac=(fac*i)%MOD;
	}
	if(ans<0) ans+=MOD; 
}
int main(){
	scanf("%d",&n);
	solve(n);
	printf("%lld",ans);
}
