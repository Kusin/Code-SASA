#include<stdio.h>
int n,m;
long long arr[600][600];
int R(){
	char now=getchar_unlocked();
	int sum=0;
	while(now<=32) now=getchar_unlocked();
	while(now>=48){
		sum=sum*10+now-48;
		now=getchar_unlocked();
	}
	return sum;
} 
int main(){
	n=R(); m=R();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			arr[i][j]=R();
			arr[i][j]+=arr[i][j-1]+arr[i-1][j]-arr[i-1][j-1];
		}
	long long max=0;
	int mx,my;
	for(int i=m;i<=n;i++)
		for(int j=m;j<=n;j++){
			long long sum=arr[i][j]-arr[i-m][j]-arr[i][j-m]+arr[i-m][j-m];
			if(sum>=max) max=sum,mx=i,my=j;
		}
	printf("%lld\n",max);
	printf("%d %d\n%d %d\n%d %d\n%d %d",mx-m+1,my-m+1,mx-m+1,my,mx,my-m+1,mx,my);
}
