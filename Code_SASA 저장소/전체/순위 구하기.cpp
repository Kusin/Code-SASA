#include<stdio.h>
int n,arr[1010],grd[1010];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",arr+i);
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++){
			if(arr[j]>arr[i])
				grd[i]++;
			else if(arr[j]<arr[i])
				grd[j]++;
			}
	for(int i=0;i<n;i++)
		printf("%d %d\n",arr[i],grd[i]+1);
}
