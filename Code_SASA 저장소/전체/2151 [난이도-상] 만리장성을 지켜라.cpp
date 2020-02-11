#include<stdio.h>
#include<algorithm>
using namespace std;
int n,m,ans=1;
bool flag;
struct point{
	int a,b;
}P[100002];
bool cmp(const point& p1,const point& p2){
	if(p1.a==p2.a) return p1.b>p2.b;
	return p1.a<p2.a;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int x,r;
		scanf("%d%d",&x,&r);
		int a=x-r,b=x+r;
		if(a<1) a=1; if(b>n) b=n;
		P[i].a=a,P[i].b=b;
	}
	sort(P,P+m,cmp);
	int itr=0,next;
	while(1){
		next=itr+1;
		for(int i=itr+1;i<m;i++){
			if(P[i].a>P[itr].b+1) break;
			if(P[i].a==P[itr].a||P[i].b<=P[itr].b) continue;
			if(P[i].b>P[next].b) next=i;
		}
		if(next==itr+1&&P[next].a-P[next].b>1){
			flag=1;
			break;
		}
		ans++; itr=next;
		if(itr==m-1||P[itr].b==n) break; 
	}
	if(P[0].b==n) ans=1;
	if(flag || P[0].a>1 || P[itr].b<n) printf("impossible");
	else printf("%d",ans);
}
