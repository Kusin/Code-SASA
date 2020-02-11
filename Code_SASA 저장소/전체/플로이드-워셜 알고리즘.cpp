#include<stdio.h>
#define INF 1<<20
int n,m,arr[20][20];
void input(){
	for(int i=1;i<=10;i++)for(int j=1;j<=10;j++)
		arr[i][j]=INF;
	scanf("%d%d",&n,&m);
	for(int i=0,a,b,w;i<m;i++){
		scanf("%d%d%d",&a,&b,&w);
		arr[a][b]=arr[b][a]=w;
	}
}
void Floyd(){
	for(int m=1;m<=n;m++)
		for(int s=1;s<=n;s++)
			for(int e=1;e<=n;e++)
				if(arr[s][e]>arr[s][m]+arr[m][e])
						arr[s][e]=arr[s][m]+arr[m][e];
}
int main(){
	input();
	Floyd();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			printf("%d에서 %d로 가는 최단거리:%d\n",i,j,arr[i][j]);
	return 0;
}
