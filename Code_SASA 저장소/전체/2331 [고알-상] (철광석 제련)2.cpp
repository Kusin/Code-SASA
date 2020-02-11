#include<iostream> 
#include<algorithm>
#define M 2000
using namespace std;
int ans,cnt,n,m,k;
long long map[M+1][M+1]={};
struct point{
	int w,r,c;
}DT[M*M];
bool cmp(point a,point b){
	if(a.w==b.w){
		if(a.r==b.r)
			return a.c<b.c;
		return a.r<b.r;
	}
	return a.w>b.w;
}
int abs(int x){
	return x>0?x:-x;
}
bool safe(int a,int b){
	return !((abs(DT[a].r-DT[b].r)<3)&&(abs(DT[a].c-DT[b].c)<3));
}
int main(){
ios::sync_with_stdio(false);
cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>k;
			map[i][j]=k+map[i-1][j]+map[i][j-1]-map[i-1][j-1];
		}
	for(int i=1;i<=n-2;i++)
		for(int j=1;j<=m-2;j++){
			DT[cnt].w=(int)(map[i+2][j+2]-map[i+2][j-1]-map[i-1][j+2]+map[i-1][j-1]);
			DT[cnt].r=i;
			DT[cnt++].c=j;
		}
	sort(DT,DT+cnt,cmp);
	if(safe(0,1))
	ans=DT[0].w+DT[1].w;
	else{
	int e=cnt;
	for(int i=0;i<e;i++){
		for(int j=i+1;j<e;j++){
			if(safe(i,j)){
				e=j;
				if(ans<(DT[i].w+DT[j].w))
					ans=DT[i].w+DT[j].w;
				break;
			}
		}
	}
	}
	printf("%d",ans);
}
