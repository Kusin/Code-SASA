#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct S{
	int P,Y,code,ord;
};
vector<S> v;
bool cmp_1(const S& s1,const S& s2){
	if(s1.P==s2.P) return s1.Y<s2.Y;
	return s1.P<s2.P;
}
bool cmp_2(const S& s1,const S& s2){
	return s1.ord<s2.ord;
}
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0,p,y;i<m;i++){
		scanf("%d%d",&p,&y);
		v.push_back({p,y,0,i});
	}
	sort(v.begin(),v.end(),cmp_1);
//	vector<S>::iterator iter=v.begin();
	int cnt=0,pre_P=0;
	for(int i=0;i<v.size();i++){
		if(v[i].P!=pre_P) cnt=1,pre_P=v[i].P;
		v[i].code=cnt++;
	}
	sort(v.begin(),v.end(),cmp_2);
	for(int i=0;i<v.size();i++){
		printf("%04d%04d\n",v[i].P,v[i].code);
	}
}
