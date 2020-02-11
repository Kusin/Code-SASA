#include<stdio.h>
#include<queue>
#define FOR(START,var,RANGE) for(int var=START;var<START+RANGE;var++)
using namespace std;
struct S{
	int x,y;
};
int n,m,k,dr[8]={1,0,-1,0,1,1,-1,-1},dc[8]={0,1,0,-1,1,-1,1,-1}; //dr,dc´Â Å½»ö ¹è¿­  
int map[1010][1010],temp,cnt,ans;
bool arr[1010][1010];
queue<S> q;
bool safe(int r,int c){
	return r>=0&&r<n&&c>=0&&c<m;
}
void input(){
	scanf("%d%d%d",&n,&m,&k);
	FOR(0,i,n) FOR(0,j,m){
		scanf("%d",&map[i][j]);
		if(map[i][j]==2) arr[i][j]=1;
		map[i][j]=(int)((bool)map[i][j])-1;
		if(map[i][j]==0) cnt++;
	}
	for(int i=0,a,b;i<k;i++){
		scanf("%d%d",&a,&b);
		map[a][b]=1;
		cnt--;
		q.push({a,b});
	}	
}
void solve(){
	while(!q.empty()&&cnt){
		int r=q.front().x,c=q.front().y;
		q.pop();
		int range=4+arr[r][c]*4; 
		FOR(0,i,range){
			int a=r+dr[i],b=c+dc[i];
			if(safe(a,b)&&map[a][b]==0){
				q.push({a,b});
				cnt--;
				map[a][b]=map[r][c]+1;
				if(map[a][b]-1>ans)
					ans=map[a][b]-1;
			}
		}
	}
}
int main(){
	input();
	solve();
	if(cnt) printf("no");
	else printf("%d",ans);
}
