#include<stdio.h>
#include<queue>
#define INF 987654321
using namespace std;
typedef struct point{
	int r,c;
}P;
queue<P> q;
int n,m,map[1001][1001],dr[4]={1,0,-1,0},dc[4]={0,1,0,-1};
int v[1001][1001],v2[1001][1001];
bool safe(int r,int c){
	return (r>=1)&&(r<=n)&&(c>=1)&&(c<=m);
}
void bfs(int r,int c){
	v[r][c]=1;
	q.push((P){r,c});
	while(!q.empty()){
		int x=q.front().r,y=q.front().c;
		q.pop();
		for(int i=0;i<4;i++){
			int a=x+dr[i],b=y+dc[i];
			if(safe(a,b)&&!v[a][b]&&(map[a][b]==0)){
				v[a][b]=v[x][y]+1;
				q.push((P){a,b});
			}
		}
	}
}
void bfs2(int r,int c){
	v2[r][c]=1;
	q.push((P){r,c});
	while(!q.empty()){
		int x=q.front().r,y=q.front().c;
		q.pop();
		for(int i=0;i<4;i++){
			int a=x+dr[i],b=y+dc[i];
			if(safe(a,b)&&!v2[a][b]&&(map[a][b]==0)){
				v2[a][b]=v2[x][y]+1;
				q.push((P){a,b});
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%1d",&map[i][j]);
	bfs(1,1);
	int ans=INF;
	if(v[n][m]) ans=v[n][m];
		while(!q.empty()) q.pop();
		bfs2(n,m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(map[i][j]){
				for(int k=0;k<4;k++)
					for(int w=0;w<4;w++){
						int x1=i+dr[k],y1=j+dc[k];
						int x2=i+dr[w],y2=j+dc[w];
						if(safe(x1,y1)&&safe(x2,y2)&&v[x1][y1]&&v2[x2][y2])
							if(ans>(v[x1][y1]+v2[x2][y2]+1))
								ans=v[x1][y1]+v2[x2][y2]+1;
					}	
			}
	printf("%d",ans!=INF?ans:-1);
}
