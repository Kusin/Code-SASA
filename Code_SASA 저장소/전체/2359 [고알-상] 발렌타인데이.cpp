#include<stdio.h>
#define MOD 10000
long long d[410][410],ans;
int a,b,g,n;
int Eulerphi(int n){
	int phi=n,temp=n;
	for(int i=2;i*i<=temp;i++)
			if(temp%i==0){
				while(temp%i==0) temp/=i;
				phi=phi*(i-1)/i;
			}
	if(temp!=1) phi = phi * (temp-1) /temp;
	return phi;
}
int gcd(int a,int b){
	if(!b) return a;
	return gcd(b,a%b);
}
void combination(){
	for(int i=1;i<=n;i++)
		d[i][0]=1,d[i][1]=i;
	for(int i=2;i<=n;i++)
		for(int j=2;j<=i;j++)
			d[i][j]=(d[i-1][j]+d[i-1][j-1]);
}
int main(){
	scanf("%d%d",&a,&b);
	n=a+b,g=gcd(a,b);
	combination();
	for(int i=1;i<=g;i++)
		if(g%i==0){
			ans+=d[n/i][a/i]*Eulerphi(i);
			ans%=MOD;
		}
	ans/=n;
	ans%=MOD;
	printf("%lld",ans);
}
