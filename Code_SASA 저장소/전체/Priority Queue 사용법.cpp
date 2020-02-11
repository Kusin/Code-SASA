#include<cstdio> //����:https://koosaga.com/9 
#include<queue>
using namespace std;
struct mart{
	int name,time;
};
struct cmp{ //������ �����ε� 
    bool operator()(mart t, mart u){
        return t.time > u.time;
    }
};
priority_queue<mart,vector<mart>,cmp> pq;
int m,n;
int main(){
	int i;
	scanf("%d%d",&m,&n);
	for(i=0;i<m;i++)
		pq.push((mart){i+1,i});
	for(i=0;i<n;i++){
		int x=pq.top().name,y=pq.top().time;
		printf("%d %d\n",x,y);
		pq.pop();
		pq.push((mart){x,y+m*x});
	}
	printf("%d",pq.top().name);
}
