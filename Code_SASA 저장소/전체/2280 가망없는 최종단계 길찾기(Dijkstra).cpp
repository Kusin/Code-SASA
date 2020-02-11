// 개선 방법 : http://www.secmem.org/blog/2019/01/09/wrong-dijkstra/
#include<stdio.h> //다익스트라 알고리즘 
#include<queue>
#define N 20
#define INF 2100000000
using namespace std;
typedef struct _node{
	int num,dist;
}node;
struct cmp{ //연산자 오버로딩 
    bool operator()(node a1, node a2){
    		if(a1.dist==a2.dist)
    			return a1.num<a2.num;
        return a1.dist > a2.dist;
    }
};
priority_queue<node,vector<node>,cmp> pq;
int d[N+2],n,m,arr[N+2][N+2],visit[N+1],s,e,lvl[N+1];
void Dijkstra(int k){
	d[k]=0;
	lvl[k]=0;
	pq.push((node){k,d[k]});
	while(!pq.empty()){
		int x=pq.top().num,cost=pq.top().dist;
		pq.pop();
		if(cost>d[x]) continue; //꽤 중요하다. 이미 왔던 때보다 cost가 크면 탐색할 필요 없다.
		visit[x]=1;
		for(int i=1;i<=n;i++){
			int alt=0;
			if(arr[x][i]!=INF&&visit[i]==0){
				alt=d[x]+arr[x][i];
				if(alt<d[i]){
					pq.push((node){i,alt});  //pq에 푸시하는 것은 값이 새롭게 갱신될 때만 이루어져야 한다.
					d[i]=alt;
					lvl[i]=lvl[x]+1;
				}
				else if(alt==d[i])
					if(lvl[i]>lvl[x]+1)
						lvl[i]=lvl[x]+1;
			}
		}
	}
} 
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			arr[i][j]=INF;
	for(int i=0,x,y,w;i<m;i++){
		scanf("%d%d%d",&x,&y,&w);
		arr[x][y]=arr[y][x]=w;
	}
	s=1,e=n;
	for(int i=1;i<=n;i++){
		d[i]=INF;// prev[i]=-1;
	}
	Dijkstra(s);
	if(d[e]!=INF)
		printf("%d %d",d[e],lvl[e]);
	else
		printf("End");
}
