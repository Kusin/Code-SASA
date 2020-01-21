#include<stdio.h>
#define N 11
#define INF 2e9
#define min(a,b) ((a)<(b)?(a):(b))
int arr[N],n,k,sum,dis[N],cnt;
bool visit[N]; 
void prim(int s){
	while(cnt<n-1){
		visit[s]=1;
		int min_i,min_w=INF;
		for(int i=1;i<=n;i++) dis[i]=min(dis[i],arr[s]+arr[i]);
		for(int i=1;i<=n;i++)
			if(!visit[i]&&(dis[i]<min_w))
				min_i=i,min_w=dis[i];
		sum+=dis[min_i]; cnt++; s=min_i;
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",arr+i);
	for(int i=1;i<=n;i++) dis[i]=INF;
	dis[1]=0; prim(1);
	if(k>=sum) printf("Assemble");
	else printf("%d",sum-k);
}
