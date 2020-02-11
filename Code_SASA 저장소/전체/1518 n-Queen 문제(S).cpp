#include<stdio.h>
long long  n,ans;
bool col[11],crs[21],crs2[21];
void f(int r,int c){
	if(col[c]||crs[r-c+n]||crs2[r+c-2])
		return;
	if(r==n){
		ans++;
		return;
	}
	col[c]=1; crs[r-c+n]=1; crs2[r+c-2]=1;
	for(int i=1;i<=n;i++){
		f(r+1,i);
	}
	col[c]=0; crs[r-c+n]=0; crs2[r+c-2]=0;
}
void solve(){
	for(int i=1;i<=n;i++){
		f(1,i);
	}
}
int main(){
	scanf("%d",&n);
	solve();
	printf("%d",ans);
}
