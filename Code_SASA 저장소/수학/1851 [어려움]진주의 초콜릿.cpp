// ��Ÿ�� ��� :https://m.cafe.daum.net/math-hm/pRQk/427?listURI=%2Fmath-hm%2FpRQk
// ���� �ϳ� ��ô ���� n�� �Ҽ��� ��� ���Ϸ� �����Լ��� ���� �ƴ϶� 1���� n������ ���� ���̴�.
// a�� n�� ���μҶ�� n-a�� n�� ���μ��̱� ������ ���μ��� ������ �׻� ��Ī�� ���� �� �� �ִ�.
// n�� ¦���� ���� n/2�� n�� ���μҰ� �ƴϱ� ������ ��Ī�� �ƴ� ���� ������ �ʴ´�. 
// n�� �ռ����� ��� ���� (phi(n)*n)/2; 
#include<stdio.h>
#define MOD 482379
long long n,phi,temp;
int main(){
	scanf("%lld",&n);
	phi=temp=n;
	for(int i=2;i*i<=temp;i++)
			if(temp%i==0){
				while(temp%i==0) temp/=i;
				phi=phi*(i-1)/i;
			}
	if(temp!=1) phi=phi*(temp-1)/temp;
	long long ans = ((phi*n)/2)%MOD;
	if(temp==n) ans=((n*(n+1))/2)%MOD;
	if(n==1) ans=1;
	printf("%lld",ans);
}
