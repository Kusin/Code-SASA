#include <cstdio> //����:������ ������!  �Է°��� ���Ǹ� �����ؾ� �Ѵ�. 
#include <queue>
using namespace std;
priority_queue<int> pq; //�켱������ ū �ͺ��� ���´�. �����ͺ��� �Ϸ��� greater<int> ���  
int m,n;
int main(){
	int i;
	scanf("%d%d",&m,&n);
	for(i=0;i<m;i++)
		pq.push(-i);
	for(i=0;i<n;i++){
		int x=pq.top(),y=(-x)%m+1; //x�� �켱����, y�� ���� ��ȣ 
		pq.pop();
		pq.push(x-m*y);
	}
	printf("%d",(-pq.top())%m+1);
}

