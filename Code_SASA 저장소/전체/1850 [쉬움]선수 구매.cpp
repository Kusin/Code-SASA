#include<stdio.h>
#include<algorithm>
int n;
bool no;
long long money;
struct player{
	int price;
	float chg;
}A[10000001];
bool cmp(player a1,player a2){
	return a1.chg>a2.chg;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d %f",&A[i].price,&A[i].chg);
	scanf("%lld",&money);
	long double current=(long double)money;
	std::sort(A+1,A+n+1,cmp);
	for(int i=n;i>=1;i--){
		current-=A[i].price+A[i].chg*i;
		if(current<0){
			no=1;
			break;
		}
	}
	printf("%s",no?"NO":"YES");
}
