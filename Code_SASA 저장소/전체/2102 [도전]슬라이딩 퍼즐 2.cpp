#include<stdio.h> 
#include<map>
#include<queue>
#include<stack>
#define chg(a,b) (((a)-1)*3+(b))
using namespace std; 
int arr[10],pow[9],r,c,chk,cur,ans,dr[4]={1,0,-1,0},dc[4]={0,1,0,-1},flag;
map<int,int> visit;
queue<int> q;
typedef struct Point{
	int p,move;
}P;
map<int,P> pre;
stack<P> st;
int abs(int a){
    return a>0?a:-a;
}
bool safe(int a,int b){
    return (a>=1&&a<=3)&&(b>=1&&b<=3);
}
void init(int a){
	for(int i=9;i>=1;i--){
		arr[i]=a%10;
		a/=10;
		if(arr[i]==0)
			r=(i-1)/3+1,c=(i-1)%3+1;
	}
	return;
}
void bfs(int k){
	visit[k]=0;
	q.push(k);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		init(x);
		for(int i=0;i<4;i++){
			int a=r+dr[i],b=c+dc[i];
			if(safe(a,b)){
				int t=x-pow[9-chg(a,b)]*arr[chg(a,b)]+pow[9-chg(r,c)]*arr[chg(a,b)];
				if(visit.count(t)==0){
					q.push(t);
					visit[t]=visit[x]+1;
					pre[t]=(P){x,arr[chg(a,b)]};
				}
				if(t==123456780){
				flag=1;
				ans=visit[t];
				break;
				}
			}
		}
	if(flag) break;
	}
}
int main(){
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++){
            int t,id=(i-1)*3+j;
            scanf("%d",&t);
            arr[id]=t;
            if(t==0)
                r=i,c=j,t=9;
            chk+=abs(i-1-(t-1)/3)+abs(j-1-(t-1)%3);
        }
    if(chk%2==1){
        printf("solving failed");
        return 0;
    }
    pow[0]=1;
    for(int i=1;i<9;i++)
        pow[i]=pow[i-1]*10;
    for(int i=1;i<=9;i++)
        cur+=arr[i]*pow[9-i];
    if(cur!=123456780) {
		bfs(cur);
	    if(flag){
	    	st.push(pre[123456780]);
	    	while(st.top().p!=cur){
	    		st.push(pre[st.top().p]);
			}
			while(!st.empty()){
				printf("%d ",st.top().move);
				st.pop();
			}
		}
	    else printf("solving failed");
	}
}
