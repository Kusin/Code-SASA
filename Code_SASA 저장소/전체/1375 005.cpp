#include<stdio.h>
int n,m,arr[10][10],visit[10],s,e,cnt;
void dfs(int k){
	if(k==e){
		cnt++;
		return;
	}
	visit[k]=1;
	for(int i=1;i<=n;i++)
		if(arr[k][i]&&!visit[i])
			dfs(i),visit[i]=0;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0,a,b;i<m;i++){
		scanf("%d%d",&a,&b);
		arr[a][b]=arr[b][a]=1;
	}
	scanf("%d%d",&s,&e);
	dfs(s); 
	printf("%d",cnt);
}
