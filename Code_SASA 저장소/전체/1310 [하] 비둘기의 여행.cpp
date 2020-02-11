//D[n]=2*D[n-1]+D[n-2]+...+D[0]
#include<stdio.h>
#define M 12345
typedef unsigned short us;
int n;
us ku(int k,us sum,us a,us b){
	if(k>=n) return a;
	return ku(k+1,(sum+b)%M,b,(sum+2*b)%M);
}
int main(){
	scanf("%d",&n);
	n-=1;
	printf("%hu",ku(0,1,1,2));
}
