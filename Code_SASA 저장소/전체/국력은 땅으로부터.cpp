#include<stdio.h>
#include<vector>
using namespace std;
vector<vector<int> > pow;
int n,w,h,map[200][200],dr[4]={1,0,-1,0},dc[4]={0,1,0,-1};
bool safe(int a,int b){
	return a>=0&&a<w&&b>=0&&b<h;
}
void find(int r,int c,int k){
	pow[map[r][c]].back()++;
	map[r][c]=0;
	for(int i=0;i<4;i++){
		int a=r+dr[i],b=c+dc[i];
		if(safe(a,b)&&map[a][b]==k)
			find(a,b,k);
	}
}
int main(){
	scanf("%d%d%d",&n,&h,&w);
 	pow.resize(n+5);
	for(int i=0;i<w;i++)
		for(int j=0;j<h;j++)
			scanf("%d",&map[i][j]);
	for(int i=0;i<w;i++)
		for(int j=0;j<h;j++)
			if(map[i][j]){
				pow[map[i][j]].push_back(0);
				find(i,j,map[i][j]);
			}
	int maxi=1,mini=1;
	int* sum;
	sum = new int[n+5];
	for(int i=1;i<=n;i++){
		int k=0;
		while(!pow[i].empty()){
			k+=pow[i].back()*pow[i].back();
			pow[i].pop_back();
		}
		sum[i]=k;
		if(sum[i]>sum[maxi])
			maxi=i;
		if(sum[i]<sum[mini])
			mini=i;
	}
	printf("%d %d %d %d",maxi,sum[maxi],mini,sum[mini]);
}
