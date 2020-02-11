#include<stdio.h>
int n,m,arr[100010];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0,a,b,w;i<m;i++){
		scanf("%d%d%d",&a,&b,&w);
		arr[a]+=w;
		arr[b+1]-=w;
	}
	for(int i=1;i<=n;i++){
		arr[i]+=arr[i-1];
		printf("%d ",arr[i]);
	}
}
