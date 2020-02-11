#include <stdio.h>
int m, n, coin[10];
int f(int k){
	int DT[100000]={};
	DT[k]=1;
	for(int i=0;i<=m;i++)
		for(int j=0;j<n;j++){
			if(i+coin[j]>m||!DT[i]) continue;
			if(!DT[i+coin[j]]) DT[i+coin[j]]=DT[i]+1;
			else DT[i+coin[j]]=(DT[i+coin[j]]<DT[i]+1)?DT[i+coin[j]]:DT[i]+1;
		}
	return DT[m]?DT[m]-1:99999;
}
int main()
{
    scanf("%d %d", &m, &n);
    for(int i=0; i<n; i++)
        scanf("%d", coin+i);
    printf("%d\n", f(0));
    return 0;
}
