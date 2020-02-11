#include<stdio.h>
#include<deque>
#include<utility>
using namespace std; 
int N,L,tmp;
deque<pair<int,int> > dq;
int main(){
	scanf("%d%d",&N,&L);
	for(int i=1;i<=N;i++){
		scanf("%d",&tmp);
		while(!dq.empty() && dq.back().first<tmp)
			dq.pop_back();
		dq.push_back(make_pair(tmp,i));
		while(!dq.empty() && dq.front().second<=i-L)
			dq.pop_front();
		printf("%d ",dq.front().second);
	}
	for(int i=N+1;i<N+L;i++){
		while(!dq.empty() && dq.front().second<=i-L)
			dq.pop_front();
		printf("%d ",dq.front().second);
	}
}

