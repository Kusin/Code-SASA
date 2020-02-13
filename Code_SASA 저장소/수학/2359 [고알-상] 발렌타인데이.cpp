#include<stdio.h> //MOD가 10000인게 치명적이다. 
int MOD=10000; 
int d[410][410],sum,ans;
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
int pow(int n,int cnt){
	if(n==1) return 1;
	int calc=1;
	while(cnt){
		if(cnt%2){
			calc*=n;
			calc%=MOD;
		}
		cnt/=2;
		n*=n;
		n%=MOD;
	}
	return calc;
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
			d[i][j]=(d[i-1][j]+d[i-1][j-1])%MOD;
}
int main(){
	scanf("%d%d",&a,&b);
	n=a+b,g=gcd(a,b);
	combination();
	for(int i=1;i<=g;i++)
		if(g%i==0){
			sum+=d[n/i][a/i]*Eulerphi(i);
			sum%=MOD;
		}
	int g_prime = gcd(MOD,n);
	printf("%d\n",Eulerphi(142857));
	n/=g_prime;
	int n_reverse = pow(n,Eulerphi(10000)-1),x=sum*n_reverse;
	for(ans=0;ans<MOD;ans++)
		if((ans*g_prime)%MOD == (sum*n_reverse)%MOD)
			break;
	printf("%d",ans);
}
