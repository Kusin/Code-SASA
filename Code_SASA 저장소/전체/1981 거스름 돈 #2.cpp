#include <stdio.h>
int m, n, coin[10];
int f(int k){
	int DT[100000]={};
	DT[k]=1;
	for(int i=m;i>=0;i--)
		for(int j=0;j<n;j++){
			if(i-coin[j]<0||!DT[i]) continue;
			if(!DT[i-coin[j]]) DT[i-coin[j]]=DT[i]+1;
			else DT[i-coin[j]]=(DT[i-coin[j]]<DT[i]+1)?DT[i-coin[j]]:DT[i]+1;
		}
	return DT[0]?DT[0]-1:99999;
}
int main()
{
    scanf("%d %d", &m, &n);
    for(int i=0; i<n; i++)
        scanf("%d", coin+i);
    printf("%d\n", f(m));
    return 0;
}
