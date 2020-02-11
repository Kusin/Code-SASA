#include<stdio.h>
#define M 1<<10
#define MAX (1LL<<31)-1
int n,m,bit[3],min=MAX,x;
bool v[M][M];
int chk(int k){
	if(k>=512) return 512;
	if(k>=256) return 256;
	if(k>=128) return 128;
	if(k>=64) return 64;
	if(k>=32) return 32;
	if(k>=16) return 16;
	if(k>=8) return 8;
	if(k>=4) return 4;
	if(k>=2) return 2;
	if(k>=1) return 1;
	return 0;
}
void dfs(int dis,int a,int b,int c){
	if(dis>m)
		return;
	int cur,p,q;
	v[a][b]=1;
	if(a==x||c==x){
		if(dis<min)
			min=dis;
		return;
	}
	if(a>b){
		cur=chk(a);
		p=a-cur;q=b+cur;
	}
	else{
	 	cur=chk(b);
		p=a+cur;q=b-cur;
	}
	if(!v[p][q]){
			dfs(dis+1,p,q,c);
			v[p][q]=0;
	}
	if(b<c){
		cur=chk(c);
		p=b+cur; q=c-cur;
	}
	else{
		cur=chk(b);
		p=b-cur; q=c+cur;
	}
	if(!v[a][p]){
		dfs(dis+1,a,p,q);
		v[a][p]=0;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	x=(1<<n)-1;
	for(int i=0,j,k;i<3;i++){
		scanf("%d",&j);
		while(j--){
			scanf("%d",&k);
			bit[i]=bit[i]|(1<<k-1);
		}
	}
	dfs(0,bit[0],bit[1],bit[2]);
	printf("%d",min!=MAX?min:-1);
}

