#include<stdio.h>
#include<queue>
int m,n,me,idol;
int rel[101][101],visit[101];
void bfs(int k){
	std::queue<int> q;
	q.push(k);
	visit[k]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=1;i<=m;i++)
			if(!visit[i]&&rel[x][i])
				q.push(i),visit[i]=visit[x]+1;
	}
}
int main(){
	scanf("%d%d",&m,&n);
	int i=0,a,b;
	while(i++<n){
		scanf("%d%d",&a,&b);
		rel[a][b]=rel[b][a]=1;
	}
	scanf("%d%d",&me,&idol);
	bfs(me);
	printf("%d",visit[idol]?visit[idol]-1:-1);
}
