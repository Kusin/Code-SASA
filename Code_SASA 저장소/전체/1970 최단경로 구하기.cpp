#include<stdio.h>
#include<stack>
using namespace std;
stack<int> st;
int n,m,arr[11][11],s,e,visited[11],print[11],x;
void visit(int k){
	visited[k]=1;
	st.push(k);
	if(k==e){
		x=st.size();
		while(!st.empty())
			print[st.size()-1]=st.top(),st.pop();
	}
}
void dfs(int k){
	int i;
	visit(k);
	while(!st.empty()){
		for(i=1;i<=n;i++)
			if(arr[st.top()][i]&&!visited[i]){
				visit(i);
				if(i==k)
					return;
				break;
			}
		if(i==n+1)
			st.pop();
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0,a,b;i<m;i++)
		scanf("%d%d",&a,&b),arr[a][b]=arr[b][a]=1;
	scanf("%d%d",&s,&e);
	dfs(s);
	for(int i=0;i<x;i++)
		printf("%d ",print[i]);
}
