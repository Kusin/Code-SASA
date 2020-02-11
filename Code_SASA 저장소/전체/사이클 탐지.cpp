#include<stdio.h>
#include<vector>
#define N 300000
using namespace std;
int n,m,visit[N+30],cnt;
vector<int> v[N+30];
bool cycle_dfs(int k,int before){
	if(visit[k]){
		if(visit[k]==-1){
			return true;
		}
		return false;
	}
	visit[k]=-1;
	for(int i;v[k].size();i++)
		if(v[k][i]!=before){
			if(cycle_dfs(v[k][i],k))
				return true;
		}
	visit[k]=1;
	return false;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0,a,b;i<m;i++){
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	printf("%d",cycle_dfs(1,0));
}
