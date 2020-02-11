#include<stdio.h>
int h,x=1,end,tree[35],cnt,arr[1001][1001];
int main(){
	scanf("%d",&h);
	while(h--){
		end+=x;
		x*=2;
	}
	for(int i=1;i<=end;i++)
		scanf("%d",tree+i);
	for(int i=1;i<=end;i++){
		if(tree[i]){
			if(tree[2*i])
				arr[tree[i]][tree[2*i]]=arr[tree[2*i]][tree[i]]=1;
			if(tree[2*i+1])
				arr[tree[i]][tree[2*i+1]]=arr[tree[2*i+1]][tree[i]]=1;
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
