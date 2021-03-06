#include<stdio.h>
//Code Sasa 문제 1343: 약수의 개수의 합  
//일반적으로 n의 약수의 개수를 n^(1/2)로 구하는 과정의 변형
/*
for(i=1;i*i<=n;i++)
	if(n%i==0)
		sum+=2;
if((--i)*i==n)
 	sum--;
*/
int main(){
	long long n,i,sum=0;
	scanf("%lld",&n);
//k가 i를 약수로 가진다 <-> i가 k를 배수로 가진다   
	for(i=1;i*i<=n;i++){
		/*
		어떤 k의 약수 i에 대해 k = i * j 라 하자. 
		i<=j인 경우 i<=sqrt(n) 임은 자명하다.
		i,j에 대해 카운팅을 따로 따로 하지 말고
		i에 대해 할 때 j에 대한 카운팅을 같이 해준다.
		i의 배수 각각에 대해 j가 존재하므로 기본적으로 n/i를 2배 해준다는 발상을 할 수 있다.
		그러나 i<=j인 경우만 카운팅 해야하는데 i>j인 경우까지 처리해버리면 이중으로 처리하게 된다. 
		그러므로 n/i에 대해 i>j인 경우는 i*1 부터 i*(i-1)까지 이므로 n/i - (i-1)이 원하는 값이 된다.
		다만 i==j인 경우 1번만 카운팅 되어야 하나 2번 카운팅 된다. 그러므로 제곱수의 개수만큼 ans에서 빼준다.
		*/
		sum+=2*(n/i-(i-1)); // (n/i)는 n이하 i의 배수의 수, 거기서 i-1은 i*i>k인 k의 수를 빼준 것( i*1~i*(i-1) )
	}
// 제곱수는 실제보다 약수의 개수가 1 많이 카운트된다. 
	sum-=(--i);  //즉, n보다 작은 제곱수의 개수를 sum에서 빼준다. 
	printf("%lld",sum);
}
