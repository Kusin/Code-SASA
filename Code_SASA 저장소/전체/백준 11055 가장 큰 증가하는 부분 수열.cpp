#include<stdio.h>
typedef long long int ii;
int n,a[1001];
ii max,dp[1001];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	for(int i=0;i<n;i++){
		dp[i]=a[i];
		for(int j=0;j<i;j++)
			if((a[i]>a[j])&&(dp[i]<dp[j]+a[i]))
				dp[i]=dp[j]+a[i];
		if(max<dp[i])
			max=dp[i];
	}
	printf("%lld",max);
}
