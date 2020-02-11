#include<stdio.h>
#include<algorithm>
int n,cnt[200001],x=1;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=2*n-1;i++)
		scanf("%d",cnt+i);
	std::sort(cnt+1,cnt+2*n);
	for(int i=2;i<=2*n-1;i++){
		if(cnt[i-1]==cnt[i])
			x++;
		else
			x=1;
		if(x>=n){
			printf("%d",cnt[i]);
			break;
		}
	}
}

