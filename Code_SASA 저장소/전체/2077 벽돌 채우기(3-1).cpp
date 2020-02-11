#include<stdio.h>
int n;
long long int DT[101]={0,1,1,2};
int main(){
	scanf("%d",&n);
	if(DT[n])
		printf("%d",DT[n]);
	else{
	 for(int i=4;i<=n;i++)
	 	DT[i]=DT[i-1]+DT[i-3];
	printf("%lld",DT[n]);
	}
}

