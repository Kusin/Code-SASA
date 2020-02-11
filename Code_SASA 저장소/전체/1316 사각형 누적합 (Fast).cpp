#include<stdio.h>
int n,m,a[1001][1001];
int readInt()
{
	int sum = 0;
	char now = getchar_unlocked();

	while (now <= 32) now = getchar_unlocked();
	while (now >= 48)
	{
		sum = sum * 10 + now - 48;
		now = getchar_unlocked();
	}

	return sum;
}
int main(){
	n=readInt();
	m=readInt();
	for(int i=1;i<=n;i++)
		for(int j=1,k;j<=m;j++){
			k=readInt();
			a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+k;
			}
	for(int i=1;i<=n;i++,puts(""))
		for(int j=1;j<=m;j++)
			printf("%d ",a[i][j]);
}
