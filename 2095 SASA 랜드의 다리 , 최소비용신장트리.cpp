//kruskal 알고리즘 : https://ghkvud2.tistory.com/97?category=826403
//https://gmlwjd9405.github.io/2018/08/29/algorithm-kruskal-mst.html
//Union Find :https://gmlwjd9405.github.io/2018/08/31/algorithm-union-find.html  
#include<stdio.h>
#include<algorithm>
#include<vector>
#define N 15
#define M 35
using namespace std;
int n,m,root[M],ranked[M],ans;
struct edge{
	int a,b,w;
};
vector<edge> E;
bool cmp(const edge& e1,const edge& e2){ //레퍼런스로 받아오는 이유: 불필요한 복사 방지  
	return e1.w>e2.w;
}
int find(int k){
	if(root[k]==k)
		return k;
	else{
		return root[k]=find(root[k]);
	}
}
void union_(int a,int b){
	a=find(a);
	b=find(b);
	if(a==b) return;
	if(ranked[a]<ranked[b]){
		root[a]=b;
	}else{
		root[b]=a;
		if(ranked[a]==ranked[b])
		ranked[a]++;
	}
}
void Kruskal(){
	for(int i=1;i<=n;i++)
		root[i]=i;
	vector<edge> A;
	sort(E.begin(),E.end(),cmp);
	for(auto e : E){
		int x=e.a,y=e.b;
		if(find(x)==find(y)) continue;
		else{
			union_(x,y);
			A.push_back(e);
			ans+=e.w;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0,a,b,w;i<m;i++){
		scanf("%d%d%d",&a,&b,&w);
		E.push_back({a,b,w});
	}
	Kruskal();
	printf("%d",ans);
}
