#include<stdio.h> //1 / 2 / 3 / 1 3
#define INF 2100000000
int n,arr[4][301],ans=-INF;
int DT[301][5];
int max(int a,int b){
	return a>b?a:b;
}
void f(int c,int t,int sum){
	if(c>n){
		ans=max(ans,sum);
		return;
	}
	if(sum>DT[c][t])
		DT[c][t]=sum;
	else
		return;
	int x[4]={};
	for(int i=1;i<=3;i++)
		x[i]=arr[i][c];
	if(t==0){
		for(int i=1;i<=3;i++)
			f(c+1,i,sum+x[i]);
		f(c+1,4,sum+x[1]+x[3]);
	}
	else if(t==1){
		f(c+1,2,sum+x[2]);
		f(c+1,3,sum+x[3]);
	}
	else if(t==2){
		f(c+1,1,sum+x[1]);
		f(c+1,3,sum+x[3]);
		f(c+1,4,sum+x[1]+x[3]);
	}
	else if(t==3){
		f(c+1,1,sum+x[1]);
		f(c+1,2,sum+x[2]);
	}
	else{
		f(c+1,2,sum+x[2]);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=3;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&arr[i][j]);
	for(int i=0;i<=n;i++){
		for(int j=0;j<=4;j++)
			DT[i][j]=-INF;
	}	
	f(0,0,0);
	printf("%d",ans);
}
