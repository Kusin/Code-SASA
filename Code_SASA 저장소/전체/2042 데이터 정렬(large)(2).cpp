#include<stdio.h> //���� �켱���� ť(��)�� �۵������� �������� ���ߴ�. 
#include<queue>
using namespace std;
priority_queue<int> pq;
int n;
int main(){
	scanf("%d",&n);
	for(int i=0,k;i<n;i++){
		scanf("%d",&k);
		pq.push(-k);
	}
	for(int i=0;i<n;i++){
		printf("%d\n",-pq.top());
		pq.pop();
	}
	return 0;
}
