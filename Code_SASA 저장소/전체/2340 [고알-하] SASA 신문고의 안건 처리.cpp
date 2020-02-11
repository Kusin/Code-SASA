#include<stdio.h>
#include<algorithm>
using namespace std;
int n,m,dt[101][1001],mt[101],cnt[101];
struct M{
	int a,w,t;
	void make(int x,int y,int z) {a=x,w=y,t=z;};
}S[101];
bool cmp (M x,M y){
	return x.a<y.a;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",mt+i);
	for(int i=0,a,w,t;i<m;i++){
		scanf("%d %d %d",&a,&w,&t);
		cnt[a]++;
		S[i].make(a,w,t);
	}
	sort(S,S+m,cmp);
	int j=0;
	for(int i=1;i<=n;i++){
		int tmp=j;
		for(;j<tmp+cnt[i];j++){
			for(int k=0;k<=mt[i];k++){
				dt[j][k]=-9999999;
				if(k-S[j].t>=0) dt[j][k]=((j==tmp)?S[j].w:max(dt[j-1][k-S[j].t]+S[j].w,dt[j-1][k]));
				else dt[j][k]=(j==tmp)?0:dt[j-1][k];
			}
		}
		int ans=0;
		for(int k=0;k<=mt[i];k++)
			ans=max(ans,dt[j-1][k]);
		printf("%d ",ans);
	}
}
