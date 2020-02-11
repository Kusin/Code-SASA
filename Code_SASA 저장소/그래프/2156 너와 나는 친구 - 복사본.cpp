#include<iostream>
#include<queue>
using namespace std;
int a,n,arr[31][31],s,e,visit[31];
queue<int> q;
void bfs(int k){
	visit[k]=1;
	q.push(k);
	while(q.size()){
		int t=q.front();
		if(t==e)
			break;
		q.pop();
	for(int i=1;i<=a;i++)
		if(visit[i]==0&&arr[t][i])
			visit[i]=1,q.push(i);
	}
}
int main(){
	cin>>a>>n;
	for(int i=0,x,y;i<n;i++){
		cin>>x>>y;
			arr[x][y]=arr[y][x]=1;
	}
	cin>>s>>e;
	bfs(s);
	if(visit[e])
		cout<<"Yes";
	else
		cout<<"No";
}
