#include<stdio.h>
#include<string.h>
int n,m,s,x,y,G[20][20],M=90000,t=M,d,visit[20],P,Q,R;
void dfs(int k,int D){
	visit[k]=1;
	if(k==d){
		if(D<t)
			t=D;
		return;
	}
	for(int i=1;i<=n;i++)
		if(G[k][i]&&!visit[i]){
			dfs(i,D+G[k][i]);
			visit[i]=0;
		}
}
void init(int a){
	memset(visit,0,sizeof(visit));
	t=M; d=a;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0,a,b,w;i<m;i++){
		scanf("%d%d%d",&a,&b,&w);
		G[a][b]=G[b][a]=w;
	}
	scanf("%d%d%d",&s,&x,&y);
	d=y;dfs(x,0);R=t;
	init(x);dfs(s,0);P=t;
	init(y);dfs(s,0);Q=t;
	if(R==M||P==M) printf("TT");
	else printf("%d",R+(P<Q?P:Q));
}
