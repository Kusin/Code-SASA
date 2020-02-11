#include<stdio.h>
#include<algorithm>
#define N 11
#define INF 2e9
#define min(a,b) ((a)<(b)?(a):(b))
struct edge{
	int a,b,w;
}E[N*N];
int arr[N],n,k,sum,root[N],ranked[N]; 
bool cmp(const edge& e1,const edge& e2){
	return (e1.w)<(e2.w);
}
int find(int k){
	if(k==root[k]) return k;
	return root[k] = find(root[k]); //Path compassion
}
void union_(int a,int b){
	a=find(a),b=find(b);
	if(a==b) return;
	if(ranked[a]<ranked[b])
		root[a]=b;
	else{
		root[b]=a;
		if(ranked[a]==ranked[b]) 
			ranked[a]++;
	}
}
void Kruskal(){
	int X=0;
	for(int i=2;i<=n;i++)
		for(int j=1;j<i;j++)
			E[X].a=i,E[X].b=j,E[X].w=arr[i]+arr[j],X++; 
	std::sort(E,E+X,cmp);
	for(int i=0;i<X;i++){
		int x=E[i].a,y=E[i].b;
//		printf("%d %d\n",x,y);
//		printf("%d %d\n",find(x),find(y));
		if(find(x)==find(y)) continue;
		union_(x,y);
		sum+=E[i].w;
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",arr+i); 
		root[i]=i;
	}
	Kruskal();
	if(k>=sum) printf("Assemble");
	else printf("%d",sum-k);
}
