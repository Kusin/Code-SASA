#include<stdio.h>
#include<queue>
using namespace std;
struct node{
	int num,w;
};
struct cmp{
	bool operator()(node a,node b){
		return a.w>b.w;
	}
};
priority_queue<node,vector<node>,cmp> pq;
int n,k,arr[21][21],chk[21],cnt,ans;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<k;i++){
		char a,b;
		int x,y,w;
		scanf(" %c %c %d",&a,&b,&w);
		a= a-'a'+1; b= b-'a'+1;
		arr[a][b]=arr[b][a]=w; 	
	}
	pq.push(node{1,0});
	while(1){
		int p=pq.top().num,q=pq.top().w;
		pq.pop();
		cnt++; ans+=q; chk[p]=1;
		if(cnt>=n) break;
		for(int i=1;i<=n;i++){
			if(arr[p][i]&&!chk[i]){
				pq.push(node{i,arr[p][i]});
			}
		}
	}
	printf("%d",ans);
}
