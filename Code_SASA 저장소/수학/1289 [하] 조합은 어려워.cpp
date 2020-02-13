#include<stdio.h>
#include<time.h>
int n,m,ans,arr[21];
void ku(int k,int cnt){
	if((k>n)&&(cnt!=m)) return;
	if(cnt==m){
		ans++;
		for(int i=0;i<m;i++,printf(" "))
			printf("%d",arr[i]);
		puts(""); 
		return;
		}
	arr[cnt]=k;
	ku(k+1,cnt+1);
	ku(k+1,cnt);
}
int main(){
	scanf("%d%d",&n,&m);
//	time_t start=clock();
	ku(1,0);
	printf("%d",ans);
//	printf("\ntime=%lf",(double)(clock()-start)/CLOCKS_PER_SEC);
} 
