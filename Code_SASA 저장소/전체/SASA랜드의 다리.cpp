#include<stdio.h> //1번째 접근  fail : 이때는 최소비용신장트리의 개념을 몰랐다 .
#include<string.h>
#define N 20
using namespace std;
int n,m,depth[N],arr[N][N],sum,ans=(1LL<<31)-1,cnt,m_min;
void dfs(int k,int from){
	for(int i=1;i<=n;i++){
		if(!arr[k][i]||i==from) continue;
		if(!depth[i]){
			depth[i]=depth[k]+1;
			dfs(i,k);
		}
		else if(depth[i]<depth[k]){
			m_min+=arr[k][i];
			cnt--;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0,a,b,w;i<m;i++){
		scanf("%d%d%d",&a,&b,&w);
		if(!arr[a][b]) sum+=w;
		arr[a][b]=arr[b][a]=w;
	}
	for(int i=1;i<=n;i++){
		m_min=0; memset(depth,0,sizeof(depth)); depth[i]=1; cnt=m-(n-1);
		dfs(i,0);
		if(cnt==0 && m_min<ans) ans=m_min;
	}
	if(m-(n-1)<=0) printf("%d",sum);
	else printf("%d",sum-ans);
}
