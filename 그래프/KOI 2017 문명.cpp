#include<stdio.h> //전명우님 풀이 보고 공부 : Union-Find 의 개념은 Kruskal 공부할 때 익혔기 때문에  이해가 더 잘되었다. 
#include<queue>
#define N 2020
#define K 100010
#define INF 2100000000
using namespace std;
int n,k,ans,cnt,tmp;
int dis[N][N],root[N*N+10],ranked[N*N+10], dr[]={1,0,-1,0},dc[]={0,1,0,-1};
bool visit[N][N];
queue<int> q;
int find(int k){
	if(k==root[k]) return k;
	return root[k]=find(root[k]);
}
void union_(int a,int b){
	a=find(a); b=find(b);
	if(a==b) return;
	if(ranked[a]<ranked[b]){
		root[a]=b;
	}else{
		root[b]=a;
		if(ranked[a]==ranked[b])
			ranked[a]++;
	}
}
bool safe(int a,int b){
	return a>=1&&a<=n&&b>=1&&b<=n;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=INF,++tmp,root[tmp]=tmp;
	for(int i=0,x,y;i<k;i++){
		scanf("%d%d",&x,&y);
		dis[x][y]=0;
		q.push(x);q.push(y);
	}
	for(;;ans++){
		while(!q.empty()){
			int r=q.front(); q.pop(); int c=q.front(); q.pop();
			if(dis[r][c]!=ans){
				q.push(r); q.push(c);
				break;
			}
			visit[r][c]=1; cnt++; // ,도대체 왜????? 
			for(int i=0;i<4;i++){
				int a=r+dr[i],b=c+dc[i];
				if(!safe(a,b)) continue;
				if(visit[a][b]){
					int x=find(n*(a-1)+b),y=find(n*(r-1)+c);
					if(x!=y){
						cnt--;//1번째 물음을 향한 답. dis가 2인 점에서 1인 점을 탐색할 때 union하면서 cnt도 같이 작아짐. 
						union_(x,y); 
					}
				}else if(dis[a][b]==INF){
					dis[a][b]=dis[r][c]+1;
					q.push(a); q.push(b);
				}
			}
		
		}
		if(cnt==1) break;
	}
	printf("%d",ans);
} 

