#include<stdio.h>
#include<stack>
using namespace std;
stack<char> st;
char a[110],b[110];
int n,cnt,ans;
int main(){
	scanf("%d",&n);
	scanf("%s",a);
	scanf("%s",b);
	for(int i=0,j;i<n;i++){
		cnt=0;
		for(j=0;j<n;j++){
			if(a[i+j]!=b[j])
				break;
			cnt++;
		}
		if((i+j)==n&&cnt>ans)
			ans=cnt;
	}
	printf("%d",2*n-ans);
}

