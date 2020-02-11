#include<stdio.h>
int h,d,x=1,end,tree[35],cnt,arr[1001][1001];
int main(){
	scanf("%d%d",&d,&h);
	while(h--){
		end+=x;
		x*=d;
	}
	for(int i=1;i<=end;i++)
		scanf("%d",tree+i);
	for(int i=1;i<=end;i++){
		if(tree[i]){
			for(int j=i*d+1;j>(i-1)*d+1;j--)
			if(tree[j])
				arr[tree[i]][tree[j]]=arr[tree[j]][tree[i]]=1;
		}
	}
	for(int i=1;i<=end;i++)
		if(tree[i]){
			for(int j=1;j<=end;j++)
				if(tree[j])
					printf("%d ",arr[tree[i]][tree[j]]);
			puts("");
		}
}
