#include<stdio.h>
#include<algorithm>
int n,money;
struct player{
	int price,chg;
}A[101];
bool cmp(player a1,player a2){
	return a1.chg>a2.chg;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d %d",&A[i].price,&A[i].chg);
	std::sort(A+1,A+n+1,cmp);
	for(int i=n;i>=1;i--)
		money+=A[i].price+A[i].chg*i;
	printf("%d",money);
}
