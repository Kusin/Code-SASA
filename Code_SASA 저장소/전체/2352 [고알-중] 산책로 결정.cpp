#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
int n,dist[40010];
const int INF=2e9;
struct node{
	int num,dis;
};
struct cmp{
	bool operator()(node a1,node a2){
		if(a1.dis==a2.dis)
			return a1.num<a2.num;
		return a1.dis>a2.dis; 
	}
};
priority_queue<node,vector<node>,cmp> pq;
vector<vector<node> > v;
void Dijkstra(int s){
	fill(dist,dist+n+1,INF);
	pq.push({s,0});
	dist[s]=0;
	while(!pq.empty()){
		node cur=pq.top();
		pq.pop();
		if(cur.dis > dist[cur.num])
			continue;
		for(node &nxt : v[cur.num]){
			if(dist[cur.num]+nxt.dis<dist[nxt.num]){
				dist[nxt.num] = dist[cur.num]+ nxt.dis;
				pq.push({nxt.num,dist[nxt.num]});
			}
		}
	}
}
int main(){
	scanf("%d",&n);
	v.resize(n+1);
	for(int i=0,a,b,w;i<n-1;i++){
		scanf("%d%d%d",&a,&b,&w);
		v[a].push_back({b,w});
		v[b].push_back({a,w});
	}
	Dijkstra(1);
	int max_id=1;
	for(int i=1;i<=n;i++)
		if(dist[i]>dist[max_id])
			max_id=i;
	Dijkstra(max_id);
	int ans=-1;
	for(int i=1;i<=n;i++)
		if(dist[i]>ans)
			ans=dist[i];
	printf("%d",ans);
}
