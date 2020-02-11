// 제타님 댓글 :https://m.cafe.daum.net/math-hm/pRQk/427?listURI=%2Fmath-hm%2FpRQk
// 함정 하나 투척 ㅋㅋ n이 소수일 경우 오일러 파이함수가 답이 아니라 1부터 n까지의 합이 답이다.
// a가 n과 서로소라면 n-a도 n과 서로소이기 때문에 서로소인 수들은 항상 대칭인 것을 알 수 있다.
// n이 짝수일 때는 n/2는 n과 서로소가 아니기 때문에 대칭이 아닌 경우는 생기지 않는다. 
// n이 합성수일 경우 답은 (phi(n)*n)/2; 
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
