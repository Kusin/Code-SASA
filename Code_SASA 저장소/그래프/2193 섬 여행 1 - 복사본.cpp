#include<stdio.h>
#include<queue>
using namespace std;
int n,m,arr[51][51],k,visit[51],cnt;
void bfs(int x){
	queue<int> q;
	visit[x]=1;
	q.push(x);
	while(!q.empty()){
		int p=q.front();
		q.pop();
		for(int i=1;i<=n;i++)
			if(!visit[i]&&arr[p][i])
				visit[i]=1,q.push(i);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,a,b;i<=m;i++){
		scanf("%d%d",&a,&b);
		arr[a][b]=arr[b][a]=1;
	}
	scanf("%d",&k);
	bfs(k);
	for(int i=1;i<=n;i++)
		if(visit[i])
			cnt++;
	printf("%d",cnt-1);
	return 0;
}
