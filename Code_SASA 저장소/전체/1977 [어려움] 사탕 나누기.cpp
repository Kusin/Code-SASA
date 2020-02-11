#include<stdio.h>
int n,candy[310],sum;
bool DT[22600];
int main(){
	scanf("%d",&n);
	DT[0]=1;
	for(int i=1;i<=n;i++){
		scanf("%d",candy+i);
		sum+=candy[i];
		for(int j=22500;j>=0;j--)
			DT[j]|=((j>=candy[i])?DT[j-candy[i]]:0);
	}
	int ans=(1LL<<31)-1,x=0;
	for(int i=0;i<=22500;i++)
		if(DT[i]&&i<=(sum-i))
			if(ans>(sum-i)-i)
				ans=(sum-i)-i,x=(sum-i);
	printf("%d",x);
} 
