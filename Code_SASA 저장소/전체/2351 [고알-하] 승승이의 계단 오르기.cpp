#include<iostream>
#define N 510
using namespace std;
int m,n,k,ans;
int map[N][N],dr[4]={1,0,-1,0},dc[4]={0,1,0,-1};
bool safe(int a,int b){
	return a>=0&&a<m&&b>=0&&b<n;
}
void dfs(int r,int c){
	if(r==m-1&&c==n-1){
		ans++;
		return;
	}
	int t=map[r][c];
	map[r][c]=0;
	for(int i=0;i<4;i++){
		int a=r+dr[i],b=c+dc[i];
		if(safe(a,b)&&(map[a][b]>t)&&(map[a][b]-t<=k))
			dfs(a,b);
	}
	map[r][c]=t;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>m>>n>>k;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>map[i][j];
	dfs(0,0);
	printf("%d",ans);
}
