#include<stdio.h>
#include<algorithm>
using namespace std;
int cmp(int a,int b){
	return a>b;
}
int n,arr[6][41],dt[6][41],ans;
int f(int k,int id){
	if(k<=0){
		return 1;
	}
	int sum=0,size=k<5?arr[k+1][id]:99999;
	for(int i=n;i>=1;i--){
		if(arr[k][i]>=size) break;
		sum+=f(k-1,i);
	}
	return dt[k][id]=sum;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=5;i++){
		for(int j=1;j<=n;j++)
			scanf("%d",&arr[i][j]);
		sort(arr[i]+1,arr[i]+n+1,cmp);
	}
	printf("%d",f(5,0));
}
