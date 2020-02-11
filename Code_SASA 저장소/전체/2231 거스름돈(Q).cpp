#include <stdio.h>
#include <memory.h>
#include <queue>
using namespace std;
queue<int> Q;
int m, n, coin[10];
int main() {
	scanf("%d %d", &m, &n);
	for(int i=0; i<n; i++)
		scanf("%d", &coin[i]);
	int v[100000],flag=0;
	for(int i=1;i<=m;i++) v[i]=0;
	Q.push(0);
	v[0]=0;
	while(!Q.empty()){
		int x=Q.front();
		Q.pop();
		for(int i=n-1;i>=0;i--){
			int k=x+coin[i];
			if((k<=m)&&!v[k])
				v[k]=v[x]+1,Q.push(k);
			if(k==m){
				flag=1;
				break;
			}
		}
		if(flag)
			break;
	}
	printf("%d",v[m]?v[m]:99999);
		return 0;	
}
