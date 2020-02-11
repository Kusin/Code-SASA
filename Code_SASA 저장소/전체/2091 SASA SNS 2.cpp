#include<stdio.h>
#include<algorithm>
int n,m,a,b,w,bd,lvl,arr[11][11],cnt,hbd[11],visit[11];
void dfs(int x){
	visit[x]=1;
	for(int i=1;i<=n;i++)
		if(visit[i]==0&&arr[x][i]>=lvl)
			hbd[cnt++]=i,dfs(i);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&a,&b,&w);
		arr[a][b]=arr[b][a]=w;
	}
	scanf("%d%d",&bd,&lvl);
	dfs(bd);
	if(cnt){
		std::sort(hbd,hbd+cnt); 
		for(int i=0;i<cnt;i++)
			printf("%d ",hbd[i]);
	}
	else
		printf("TT");
}
