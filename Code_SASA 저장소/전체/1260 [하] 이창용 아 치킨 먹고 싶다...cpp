#include<stdio.h>
int n,arr[1010],cnt[3],arr2[1010],ans;
int main(){
	scanf("%d",&n);
	getchar();
	char c;
	for(int i=0;i<n;i++){
		scanf("%c",&c);
		arr[i]=c-'A';
		cnt[arr[i]]++;
	}
	for(int i=cnt[0];i<cnt[0]+cnt[1];i++)
		arr2[i]=1;
	for(int i=cnt[0]+cnt[1];i<n;i++)
		arr2[i]=2;
	for(int i=0;i<n;i++)
		if(arr[i]!=arr2[i]) ans++;
	ans=(ans+1)/2;
	printf("%d",ans);
}
