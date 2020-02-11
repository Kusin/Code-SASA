#include<iostream>
using namespace std;
int n,m,q,loc[101][101];
int main(){
	cin>>n>>m>>q;
	for(int i=0,a,b,c,d,w;i<q;i++){
		cin>>a>>b>>c>>d>>w;
		for(int j=a;j<=c;j++)
			for(int k=b;k<=d;k++)
				loc[j][k]+=w;
	}
	for(int i=1;i<=n;i++,puts(""))
		for(int j=1;j<=m;j++)
			cout<<loc[i][j]<<" ";
	return 0;
}
