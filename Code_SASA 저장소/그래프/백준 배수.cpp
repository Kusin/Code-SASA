#include<bits/stdc++.h>
#define N 2000000
using namespace std;
int n;
long long dis[N];
void chg(long long n){
	if(n==0) return;
	chg(n/2);
	printf("%d",n%2);
}
queue<int> q;
int main(){
	scanf("%d",&n);
	if(n==1) printf("%d",1);
	else{
	for(int i=0;i<n;i++) dis[i]=(1LL<<62)-1;
	q.push(1); dis[1]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		if((dis[x]*2+1)<dis[(x*10+1)%n]){
			dis[(x*10+1)%n]=dis[x]*2+1;
			q.push((x*10+1)%n);
		}
		if((dis[x]*2)<dis[(x*10)%n]){
			dis[(x*10)%n]=dis[x]*2;
			q.push((x*10)%n);
		}
	}
	chg(dis[0]);
}
}
