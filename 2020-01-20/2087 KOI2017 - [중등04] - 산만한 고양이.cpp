#include<stdio.h> //전명우님 풀이 보고 공부 , 코드 짤 때는 보지 않기. 
#include<vector>
using namespace std;
#define pb push_back
#define MXN 300010
int n,m;
long long ans; 
vector<int> adj[MXN],child[MXN];
int R[MXN],A[MXN],P[MXN],dep[MXN]; //[Real backedge, Almost backedge, backedge to its Parent] from index node 
void dfs(int k,int from){
	for(int x : adj[k]){
		if(x==from) continue;
		if(!dep[x]){
			dep[x]=dep[k]+1; child[k].pb(x);
			int tmp=R[k];
			dfs(x,k);
			P[x]=R[k]-tmp;
			R[k]+=R[x]; A[k]+=A[x];
		}
		else if(dep[x]<dep[k]){
			A[k]++; R[x]++;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0,a,b;i<m;i++){
		scanf("%d%d",&a,&b);
		adj[a].pb(b); adj[b].pb(a);
	}
	dep[1]=1; dfs(1,0);
	for(int i=1;i<=n;i++){
		bool isnt=0;
		for(int t : child[i]){
			if(R[t]||(A[t]-P[t])>1){
			// A[t]-P[t]>1 이면 i 위로 넘어가는 backedge가 2개 이상 존재한다는 말이고 이는 새로운 사이클을 의미한다 
				isnt=1; break;
			}
		}
		if(isnt || (m-(n-1)-A[i])) continue;
		ans+=i;
	}
	printf("%lld",ans);
	return 0;
}
