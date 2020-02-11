#include<stdio.h>
#include<algorithm>
int n,m,vsp[10][10],visit[10][10],cnt,map[100],dr[4]={-1,0,1,0},dc[4]={0,-1,0,1},ans;
bool safe(int a,int b){
	return (a>=0&&a<n)&&(b>=0&&b<n);
}
void dfs(int a,int b){
	visit[a][b]=cnt+1;
	for(int i=0;i<4;i++){
		int r=a+dr[i],c=b+dc[i];
		if(safe(r,c)&&vsp[r][c]==vsp[a][b]&&!visit[r][c])
			dfs(r,c);
	}
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%1d",&vsp[i][j]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) 
			if(!visit[i][j]){
				cnt++;
				dfs(i,j);
			}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
				map[visit[i][j]-2]++;
	for(int i=0;i<cnt;i++)
		if(map[i]>=3)
			ans+=map[i];
	printf("%d",ans);
}
