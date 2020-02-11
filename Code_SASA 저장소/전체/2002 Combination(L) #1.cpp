#include <stdio.h>
//d[n][k]=d[n-1][k-1]+d[n-1][k]
int f(int n,int k){
	int d[301][301]={};
	for(int i=1;i<=n;i++){
		d[i][0]=1;
		d[i][1]=i;
	}
	for(int i=2;i<=n;i++)
		for(int j=2;j<=i&&j<=k;j++)
			d[i][j]=(d[i-1][j-1]+d[i-1][j])%1000009;
	return d[n][k];
}
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d\n", f(n,k));
    return 0;
}
