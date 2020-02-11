#include<stdio.h>
int n,cnt;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n/3;i++)
		for(int j=i;j<=n/2;j++)
			if(n-i-j>=j&&n-i-j<i+j)
				cnt++;
	printf("%d",cnt);
}
