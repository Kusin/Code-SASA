#include<stdio.h>
#include<algorithm>
int n,home[30][30],cnt,ans[900],dr[4]={-1,0,1,0},dc[4]={0,-1,0,1};
bool safe(int a,int b){
	return (a>=0&&a<n)&&(b>=0&&b<n);
}
void dfs(int a,int b){
	home[a][b]=cnt+1;
	for(int i=0;i<4;i++){
		int r=a+dr[i],c=b+dc[i];
		if(safe(r,c)&&home[r][c]==1)
			dfs(r,c);
	}
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%1d",&home[i][j]);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			if(home[i][j]==1){
				cnt++;
				dfs(i,j);
			}
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(home[i][j])
				ans[home[i][j]-2]++;
	std::sort(ans,ans+cnt,cmp);
	printf("%d",cnt);
	for(int i=0;i<cnt;i++)
		printf("\n%d",ans[i]);
}
