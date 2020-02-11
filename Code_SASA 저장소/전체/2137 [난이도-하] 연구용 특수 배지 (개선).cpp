#include<stdio.h>
#define FOR(START,var,RANGE) for(int var=START;var<START+RANGE;var++)
int n,m,t,cnt,r,c,h,w,arr[40][40];
void R(int&k){
	k=0;
	char now=getchar();
	while(now<=32) now=getchar();
	while(now>='0'){
		k=k*10+now-'0';
		now=getchar();
	}
}
int main(){
	R(n);R(m);R(t);
	FOR(0,i,t){ //가장 왼쪽 위를 0,0으로 잡자 
		R(r);R(c);R(h);R(w);
		arr[r][c]++;
		arr[r+h][c]--;
		arr[r][c+w]--;
		arr[r+h][c+w]++;
	}
	FOR(1,i,n)
	FOR(1,j,m){
		arr[i][j]+=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
		cnt+=!(arr[i][j]%2);
	}
	printf("%d",cnt);
}
