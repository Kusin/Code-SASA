#include<stdio.h>
#include<queue>
#include<algorithm>
#define INF 99999
using namespace std;
typedef struct _node{
	int bit,dist;
}node;
struct cmp{ //연산자 오버로딩 
    bool operator()(node a1, node a2){
    		if(a1.dist==a2.dist)
    			return a1.bit<a2.bit;
        return a1.dist > a2.dist;
    }
};
priority_queue<node,vector<node>,cmp> pq;
int n,arr[10],visit[300],dist[300],start,final,pre[300];
int Dijkstra(){
	for(int i=1;i<=n;i++){
		int bit =(1<<i)+1;
		dist[bit] = arr[i];
	}
	start=0,final=(1<<n+1)-1;
	visit[0]=1; dist[0]=0;
	pq.push({0,0});
	while(!pq.empty()){
		int id=pq.top().bit,cost=pq.top().dist;
		pq.pop();
		if(dist[id]<cost) continue;
		visit[id]=1;
		if(!(id&1)){
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					if(!(id&(1<<i))&&!(id&(1<<j))){
						int alt= id ^((1<<i)+(1<<j)+1),d;
						if(visit[alt]==0){
							d=dist[id]+max(arr[i],arr[j]);
							if(d<dist[alt]){
								pq.push({alt,d});
								dist[alt]=d;
								pre[alt]=id;
							}
						}
					}
				}
			}
		}else{
			for(int i=1;i<=n;i++){
				if(id & (1<<i)){
					int alt=id^((1<<i)+1),d;
					if(visit[alt]==0){
						d=dist[id]+arr[i];
						if(d<dist[alt]){
							pq.push({alt,d});
							dist[alt]=d;
							pre[alt]=id;
						}
					}
				}
			}
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",arr+i);
	for(int i=0;i<=300;i++) dist[i]=INF;
	Dijkstra();
	printf("%d",dist[final]);
}
