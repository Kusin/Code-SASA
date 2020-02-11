#include <iostream> //교훈:문제를 잘읽자!  입력값의 정의를 숙지해야 한다. 
#include <utility>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
int n,m,k,farm[1001][1001],cnt,dr[4]={0,1,0,-1},dc[4]={1,0,-1,0},_max;
queue<pii > q;
void input(){
	    cin>>m>>n>>k;
    for (int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			cin>>farm[i][j];
			if(farm[i][j]==0||farm[i][j]==2)
				cnt++;
			if(farm[i][j]==1){
				farm[i][j]=3;
				q.push(pii{i,j});
			}
			}
}
bool safe(int a,int b){
	return (a>=0&&a<n)&&(b>=0&&b<m);
}
void solve(){
	while(!q.empty()){
		if(cnt==0)
			return;
		int r=q.front().first, c=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int x=r+dr[i],y=c+dc[i];
			if(!safe(x,y)) continue;
			if(farm[x][y]==0){
				q.push(pii{x,y}),--cnt,farm[x][y]=farm[r][c]+1;
				if(_max<farm[x][y]-3)
					_max=farm[x][y]-3;
			}
			else if(farm[x][y]==2){
				int cnt2=0;
				for(int j=0;j<4;j++){
					int p=x+dr[j],q=y+dc[j];
					if(safe(p,q)&&(farm[p][q]>=3))
						cnt2++;
				}
				if(cnt2>=k){
					q.push(pii{x,y}),--cnt,farm[x][y]=farm[r][c]+1;
					if(_max<farm[x][y]-3)
						_max=farm[x][y]-3;
				}
			}
		}
	}
}
void output(){
	if(cnt==0)
		cout<<_max;
	else
		cout<<cnt;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	solve();
	output();
}

