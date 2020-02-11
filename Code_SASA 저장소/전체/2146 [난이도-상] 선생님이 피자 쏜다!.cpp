#include<stdio.h>
int n,m,sum[100010],ans,cnt;
double score[100010],max;
double abs(double x){
	return x>0?x:-x;
}
int main(){
	scanf("%d",&n);
	for(int i=1,k;i<=n;i++){
		scanf("%d",&k);
		sum[i]=sum[i-1]+k;
	}
	scanf("%d",&m);
	for(int i=0,k,a,b;i<m;i++){
		scanf("%d%d%d",&k,&a,&b);
		if(a<=b)
			score[k]=(double)(sum[b]-sum[a-1])/(b-a+1);
		else
			score[k]=(double)(sum[b]+sum[n]-sum[a-1])/(b+n-a+1);
		if(max<score[k]){
			ans=k;
			max=score[k];
		}
		if(max==score[k]){
			if(ans<k)
				ans=k;
		}
	}
	printf("%d",ans);
} 
