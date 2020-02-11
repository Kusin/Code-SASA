#include<bits/stdc++.h>
using namespace std;
struct Graph{
	int to,w;
};
const int mx=(1LL<<31)-1;
int n,m,cur,h1,h2,ans,tmp=mx,flag;
vector<struct Graph> G[400];
bool visit[400];
void input(){
	cin>>n>>m;
	for(int i=0,a,b,w;i<m;i++){
		cin>>a>>b>>w;
		G[a].push_back({b,w});
		G[b].push_back({a,w});
	}
	cin>>cur>>h1>>h2;
}
void dfs(int here,int dst,int dis){
	visit[here]=true;
	if(here==dst){
		if(dis<tmp)
			tmp=dis;
		return;
	}
	for(int i=0;i<G[here].size();i++){
		Graph x=G[here][i];
		if(!visit[x.to]){
			dfs(x.to,dst,dis+x.w);
			visit[x.to]=0;
		}
	}
}
void solve(){
	dfs(h1,h2,0);
	int distance=tmp;
	memset(visit,0,sizeof(visit)); tmp=mx;
	dfs(cur,h1,0);
	int distance1=tmp;
	memset(visit,0,sizeof(visit)); tmp=mx;
	dfs(cur,h2,0);
	int distance2=tmp;
	ans=distance+min(distance1,distance2);
 	if(distance==mx||distance1==mx||distance2==mx) flag=1;
}
int main(){
	input();
	solve();
	if(flag) printf("TT");
	else	cout<<ans;
}
