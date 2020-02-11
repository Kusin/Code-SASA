#include<stdio.h>
#define INF 1001
int n,m,max;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0,t;i<n;i++){
		if(i%m==0)
			max=-INF;
		scanf("%d",&t);
		if(t>max)
			max=t;
		if(i%m==m-1||i==n-1)
			printf("%d ",max);
	}
} 
