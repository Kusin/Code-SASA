#include<iostream>
#include<queue>
using namespace std;
int a,n,arr[31][31],s,k,cnt,visit[31];
queue<int> q;
void bfs(int k){
	visit[k]=1;
	q.push(k);
	while(q.size()){
		int t=q.front();
		q.pop();
	for(int i=1;i<=a;i++)
		if(visit[i]==0&&arr[t][i])
			visit[i]=visit[t]+1,q.push(i);
	}
}
int main(){
	cin>>a>>n;
	for(int i=0,x,y,w;i<n;i++){
		cin>>x>>y>>w;
		if(w<=1000)
			arr[x][y]=arr[y][x]=1;
	}
	cin>>s>>k;
	bfs(s);
	for(int i=1;i<=a;i++)
		if(i!=s&&visit[i]>1&&visit[i]<=k)
			cnt++;
	cout<<cnt;
}
