#include<cstdio>
#include<algorithm>
#define INF 2100000000
int n,min;
long long int sum;
struct A{
	int loc,col;
}Arw[100010];
bool cmp(A A1,A A2){
	if(A1.col==A2.col)
		return A1.loc<A2.loc;
	return A1.col<A2.col;
}
int readInt(){
	int sum=0;
	char now=getchar();
	while(now<=32) now=getchar();
	while(now>=48){
		sum = sum*10 +now -48;
		now=getchar();
	}
	return sum;
}
int main(){
	n=readInt();
	for(int i=1;i<=n;i++)
		Arw[i].loc=readInt(),Arw[i].col=readInt();
	Arw[0].col=-1,Arw[n+1].col=-1;
	std::sort(Arw+1,Arw+n+1,cmp);
	for(int i=1;i<=n;i++){
		min=INF;
		if(Arw[i-1].col==Arw[i].col)
			min=Arw[i].loc-Arw[i-1].loc;
		if((Arw[i+1].col==Arw[i].col)&&(Arw[i+1].loc-Arw[i].loc<min))
			min=Arw[i+1].loc-Arw[i].loc;
		if(min!=INF)
			sum+=min;
	}
	printf("%lld",sum);
}
