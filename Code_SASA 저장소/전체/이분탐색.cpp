#include<stdio.h>
int n,k,arr[110];
int bs(int s,int e){
	while(s<=e){
		int m=(s+e)/2;
		if(arr[m]==k) return m+1;
		else if(arr[m]<k) s=m+1;
		else e=m-1;
	}
	return -1;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",arr+i);
	scanf("%d",&k);
	printf("%d",bs(0,n-1));
}
