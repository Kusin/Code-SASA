#include<stdio.h>
int n,arr[101][101],cnt[101];
char a,b; 
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf(" %c %c",&a,&b);
		arr[a-'A'+1][b-'A'+1]=arr[b-'A'+1][a-'A'+1]=1;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(arr[i][j])
				cnt[i]++;
	int maxi=0;
	for(int i=1;i<=n;i++)
		if(cnt[i]>cnt[maxi])
			maxi=i;
	printf("%c",maxi+'A'-1);
}
