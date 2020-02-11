#include<stdio.h>
int n,k,a[2164];
void ub(int s,int e){
	while(s<e){
		int m=(s+e)/2;
		printf("%d ",a[m]);
		if(a[m]>k)
			e=m;
		else
			s=m+1;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	scanf("%d",&k);
	ub(0,n);
}
