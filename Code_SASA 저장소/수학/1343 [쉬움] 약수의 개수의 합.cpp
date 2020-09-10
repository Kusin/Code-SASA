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
		sum+=2*(n/i-(i-1)); // (n/i)는 n이하 i의 배수의 수, 거기서 i-1은 i*i>k인 k의 수를 빼준 것( i*1~i*(i-1) )
	}
// 제곱수는 실제보다 약수의 개수가 1 많이 카운트된다. 
	sum-=(--i);  //즉, n보다 작은 제곱수의 개수를 sum에서 빼준다. 
	printf("%lld",sum);
}
