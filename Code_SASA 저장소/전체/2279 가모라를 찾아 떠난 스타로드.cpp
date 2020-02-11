#include<stdio.h>
#include<queue>
int n,m,r,c,visit[14][14],dr[4]={-1,1,2,2},dc[4]={2,2,-1,1};
struct loc{
	int r1,c1;
};
bool safe(int a,int b){
	return (a>=1&&a<=n)&&(b>=1&&b<=n);
}
void bfs(int a,int b){
	std::queue<struct loc> q;
	q.push({a,b});
	visit[a][b]=1;
	while(!q.empty()){
		int k=q.front().r1,m=q.front().c1;
		q.pop();
		for(int i=0;i<4;i++){
			int k1=k+dr[i],m1=m+dc[i];
			if(safe(k1,m1)&&visit[k1][m1]==0){
				q.push({k1,m1});
				visit[k1][m1]=visit[k][m]+1;
				if(k1==r&&m1==c)
					return;
			}
		}
	}
}
int main(){
	scanf("%d%d%d%d",&n,&m,&r,&c);
	for(int i=0,p,q;i<m;i++)
		scanf("%d%d",&p,&q),visit[p][q]=-1;
	bfs(1,1);
	printf("%d",visit[r][c]?visit[r][c]-1:-1);
} 
