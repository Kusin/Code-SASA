//º®Ä¥ÇÏ±â ±è³ªÀ± ver
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
#define MAX 100010
int n,m;
struct Query{
  int f,t,c,o;
  bool operator<(const Query& tmp) const{return o<tmp.o;}
}query[MAX];
priority_queue<Query> layer;
bool cmp(Query a, Query b){return a.f<b.f;}
int main(){
  scanf("%d%d",&n,&m);
  for(int i=0;i<m;i++){
    int s,e,c;
    scanf("%d%d%d",&s,&e,&c);
    query[i].f=s;
    query[i].t=e;
    query[i].c=c;
    query[i].o=i;
  }
  sort(query,query+m,cmp);
  for(int i=1,p=0;i<=n;i++){
    for(;query[p].f == i && p<m;p++) layer.push(query[p]);
    while(!layer.empty()){
      if(layer.top().t>=i) break;
      layer.pop();
    }
    if(layer.empty()) printf("0 ");
    else printf("%d ",layer.top().c);
  }
  printf("\n");
  return 0;
} 
