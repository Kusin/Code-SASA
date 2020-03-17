#include<stdio.h>
#include<queue>
#define N 100
using namespace std;
int n,m,map[110][110],dr[4]={1,0,-1,0},dc[4]={0,1,0,-1},s1,s2,e1,e2;;
char c;
queue<int> q;
bool safe(int a,int b){
	return a>=0&&a<n&&b>=0&&b<m;
}
void bfs(int a,int b){
	q.push(a*N+b);
	while(!q.empty()){
		int r=q.front()/N,c=q.front()%N;
		if((r==e1)&&(c==e2)) break;
		q.pop();
		for(int i=0;i<4;i++){
			int x=r+dr[i],y=c+dc[i];
			if(safe(x,y)&&(map[x][y]==0)){
				q.push(x*N+y);
				map[x][y]=map[r][c]+1;
			}
		}
	}
}
int main(){
	scanf("%d %d",&m,&n);
	for(int i=0;i<n;i++) for(int j=0;j<m;j++){
		scanf(" %c",&c);
		if(c=='S') s1=i,s2=j,map[i][j]=1;
		if(c=='1') map[i][j]=-1;
		if(c=='H') e1=i,e2=j;
	}
	bfs(s1,s2);
	printf("%d",map[e1][e2]?map[e1][e2]-1:0);
}
