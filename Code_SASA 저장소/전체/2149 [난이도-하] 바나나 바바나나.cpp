#include<stdio.h> //문제 설명 부족 
#include<algorithm>
int n,a[1010],b[1010],cnt,cur;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
	std::sort(a,a+n);
	std::sort(b,b+n);
	for(int i=0,j=0;i<n;i++){
		if(a[i]>cur){
			cur=a[i];
			cnt++;
			for(;b[j]<=cur&&j<n;j++);
			if(j>=n)
				break;
			cur=b[j],cnt++;
		}
	}
	printf("%d",cnt);
}
