#include<stdio.h>
int n,k,a[2164],cnt;
int bs(int s,int e){
	while(s<e){
		int m=(s+e)/2;
		cnt++;
		if(a[m]==k)
			return m+1;
		else if(a[m]>k)
			e=m-1;
		else
			s=m+1;
	}
	return a[s]==k?s+1:-1;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	scanf("%d",&k);
	int tmp=bs(0,n-1);
	printf("%d %d",tmp,cnt);
	
}
