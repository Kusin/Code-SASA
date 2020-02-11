#include<stdio.h>
int n,cnt;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n/4;i++)
		for(int j=i;j<=n/3;j++)
			for(int k=j;k<=n/2;k++)
				if(n-i-j-k>=k)
					if(k<(n+1)/2)
						cnt++;
	printf("%d",cnt);
}
