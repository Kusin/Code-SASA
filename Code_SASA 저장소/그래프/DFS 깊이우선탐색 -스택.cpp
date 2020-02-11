#include<stdio.h>
#include<stack>
using namespace std;
int n,m,arr[10][10],visit[10],s,e;
stack<int> st;
void dfs(int k){
	visit[k]=1;
	st.push(k);
	while(!st.empty()){
		int x=st.top(),i;
		printf("%d->",x);
	for(i=1;i<=n;i++)
		if(arr[x][i]&&visit[i]==0){
			st.push(i);
			visit[i]=1;
			break;
		}
		if(i==n+1)
			st.pop();
}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0,a,b;i<m;i++){
		scanf("%d%d",&a,&b);
		arr[a][b]=arr[b][a]=1;
	}
	scanf("%d",&s);
	dfs(s); 
}
