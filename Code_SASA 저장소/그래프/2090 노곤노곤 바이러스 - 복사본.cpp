#include<stdio.h>
int n,home[33][33],num,cnt,dr[4]={1,0,-1,0},dc[4]={0,1,0,-1};
int stu;
void input(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%1d",&home[i][j]);
}
bool safe(int a,int b){
	return (a>=0&&a<n)&&(b>=0&&b<n);
}
void dfs(int a,int b){
	home[a][b]=cnt+1;
	num++;
	for(int i=0;i<4;i++){
		int x=a+dr[i],y=b+dc[i];
		if(safe(x,y)&&home[x][y]==1)
			dfs(x,y);
	}
}
bool cmp(int a,int b){
	return a>b;
}
void solve(){
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(home[i][j]==1)
				cnt++,dfs(i,j);
}
void output(){
	printf("%d %d",cnt,num);
}
int main(){
	input();
	solve();
	output();
}
