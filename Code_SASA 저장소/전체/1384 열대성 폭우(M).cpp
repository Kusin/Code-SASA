#include<stdio.h> (วเ ภ๚ภๅ)
int n,m,q,arr[1010][1010];
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0,a,b,c,d,w;i<q;i++){
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&w);
		for(int j=a;j<=c;i++){
			arr[j][b]+=w;
			arr[j][d+1]-=w;
		}
	}
	for(int i=1;i<=n;i++,puts(""))
		for(int j=1;j<=m;j++){
			arr[i][j]+=arr[i][j-1];
			printf("%d ",arr[i][j]);
		}
}
