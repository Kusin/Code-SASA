#include<stdio.h>
#define N 110
int w,h,n,arr[N][N];
void color(int x,int y,int a){
	int p1=0,p2=w,q1=0,q2=h;
	switch(a){
		case 1: p2=x; break;
		case 2: p1=x; break;
		case 3: q2=y; break;
		case 4: q1=y; break;
	}
	for(int i=p1;i<p2;i++)
		for(int j=q1;j<q2;j++)
			arr[i][j]=1;
}
int check(){
	int cnt=0;
	for(int i=0;i<w;i++)
		for(int j=0;j<h;j++)
			if(!arr[i][j])
				cnt++;
	return cnt;
}
int main(){
	scanf("%d%d%d",&w,&h,&n);
	for(int i=1,x,y,a;i<=n;i++){
		scanf("%d%d%d",&x,&y,&a);
		color(x,y,a);
	}
	printf("%d",check());
}
