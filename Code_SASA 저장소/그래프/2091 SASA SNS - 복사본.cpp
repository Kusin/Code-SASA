#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct A{
	int x;
	int y;
};
vector<struct A> frd[11];
vector<int> hbd;
int n,m,a,b,w,bd,lvl;
void scan(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&a,&b,&w);
		frd[a].push_back({b,w});
		frd[b].push_back({a,w});
	}
	scanf("%d%d",&bd,&lvl);	
}
void solve(){
	for(int i=0;i<frd[bd].size();i++)
		if(frd[bd][i].y>=lvl)
			hbd.push_back(frd[bd][i].x);
}
void print(){
	if(hbd.empty())
		printf("TT");
	else{
		sort(hbd.begin(),hbd.end());
		for(int i=0;i<hbd.size();i++)
			printf("%d ",hbd[i]);
	}
		
}
int main(){
	scan();
	solve();
	print();
}
