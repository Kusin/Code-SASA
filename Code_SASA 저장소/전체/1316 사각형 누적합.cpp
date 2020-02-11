#include<iostream>
using namespace std;
int n,m,a[1001][1001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1,k;j<=m;j++){
			cin>>k;
			a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+k;
			}
	for(int i=1;i<=n;i++,puts(""))
		for(int j=1;j<=m;j++)
			printf("%d ",a[i][j]);
}
