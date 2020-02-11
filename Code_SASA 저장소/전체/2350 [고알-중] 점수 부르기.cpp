#include<stdio.h>
#include<algorithm>
#include<utility>
using namespace std;
typedef pair<int,int> pii;
pii p[1000001];
int n,IDT[4000000],real[1000001],rec[1000001];
bool comp(pii p1,pii p2){
	if(p1.first==p2.first)
		return p1.second<p2.second;
	return p1.first>p2.first;
}
bool comp2(pii p1,pii p2){
	return p1.second<p2.second;
}
int tr_sum(int a,int b){
	int sum=0;
	while(a<b){
		if(b%2==0) sum+=IDT[b],b--;
		a>>=1,b>>=1;
	}
	if(a==b)
		sum+=IDT[a];
	return sum;
}
void update(int a){
	IDT[a]++;
	a>>=1;
	while(a){
		IDT[a]=IDT[a*2]+IDT[a*2+1];
		a>>=1;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i].first);
		p[i].second=i;
	}
	sort(p+1,p+n+1,comp); 
	int base;
	for(base=1;base<n;base<<=1);
	p[0].first=-1;
	int dec=0;
	for(int i=1;i<=n;i++){ // 순서로 세그먼트 트리를 구성했을 때 조밀하기 때문에 효율적. 
		if(p[i].first==p[i-1].first){
			real[p[i].second]=real[p[i-1].second];
			dec++;
		}
		else{
			real[p[i].second]=i;
			dec=0;
		}
		rec[p[i].second]=tr_sum(base,base+p[i].second-2)+1-dec;
		update(base+p[i].second-1);
	}
	sort(p+1,p+n+1,comp2);
	for(int i=1;i<=n;i++)
		printf("%d ",real[i]-rec[i]);
}
