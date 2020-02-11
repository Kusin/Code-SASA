#include<stdio.h>
int n,arr[510],dt[510][2];
int max(int a,int b){
	return a>b?a:b;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",arr+i);
	dt[1][0]=dt[1][1]=arr[1];
	for(int i=2;i<=n;i++){
		dt[i][0]=max(dt[i-2][0],dt[i-2][1])+arr[i];
		dt[i][1]=dt[i-1][0]+arr[i];
	}
	int ans=max(dt[n][0],dt[n][1]);
	printf("%d",max(dt[n-1][1],ans));
}

 
