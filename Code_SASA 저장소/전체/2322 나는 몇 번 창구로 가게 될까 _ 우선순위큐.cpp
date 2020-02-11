#include <cstdio> //교훈:문제를 잘읽자!  입력값의 정의를 숙지해야 한다. 
#include <queue>
using namespace std;
priority_queue<int> pq; //우선순위가 큰 것부터 나온다. 작은것부터 하려면 greater<int> 사용  
int m,n;
int main(){
	int i;
	scanf("%d%d",&m,&n);
	for(i=0;i<m;i++)
		pq.push(-i);
	for(i=0;i<n;i++){
		int x=pq.top(),y=(-x)%m+1; //x는 우선순위, y는 계산대 번호 
		pq.pop();
		pq.push(x-m*y);
	}
	printf("%d",(-pq.top())%m+1);
}

