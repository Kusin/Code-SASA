#include<stdio.h>
#include<stdlib.h>
int main(){
	int n,i;
	scanf("%d",&n);
	int*a=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	int max=a[0],min=a[0];
	for(int i=1;i<n;i++){
	max=max<a[i]?a[i]:max;
	min=min>a[i]?a[i]:min;
	}
	printf("%d %d",max,min);
	free(a);
	return 0;
}
