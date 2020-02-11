#include<stdio.h>
#include<queue>
int k,m,n;
int f(int n,int k){
	if(n==1) return 0;
	return (f(n-1,k)+k)%n;
}
int main(){
	scanf("%d%d%d",&k,&m,&n);
	n-=m;
	if(n<0) n+=k;
	int c=0,x=-1;
	while(x!=n){
		c++;
		x=f(k,c);
	}
	printf("%d\n",c);
	n+=m;
	if(n>k) n-=k;
	std::queue<int> q;
	for(int i=0;i<k;i++)
		q.push(i);
	while(q.size()!=1){
		for(int i=0;i<c-1;i++)
			q.push(q.front()),q.pop();
		printf("%d",(q.front()+m-1)%k+1);
		if(q.size()>2) printf(" ");
		q.pop();
	}
}
