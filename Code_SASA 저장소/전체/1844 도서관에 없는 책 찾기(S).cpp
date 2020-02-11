#include<stdio.h>
int n,m,cnt;
bool real[11];
struct book{
	char name[202];
	int len;
}A[101];
struct want{
	char name[202];
	int len;
}B[11];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0,t;i<n;i++){
		scanf(" %[^\n]s",A[i].name);
		for(t=0;A[i].name[t];t++);
		A[i].len=t;
	}
	for(int i=0,t;i<m;i++){
		scanf(" %[^\n]s",B[i].name);
		for(t=0;B[i].name[t];t++);
		B[i].len=t;
	}
	for(int i=0,flag;i<m;i++){
		real[i]=1;
		flag=1;
		for(int j=0;j<n;j++){
			flag=1;
			if(B[i].len!=A[j].len)
				continue;
		for(int k=0;k<B[i].len&&k<A[j].len;k++){
			if(B[i].name[k]!=A[j].name[k]){
				flag=0;
				break;
			}
		}
		if(flag){
			real[i]=0;
			break;
		}
	}
}
	for(int i=0;i<m;i++)
		if(real[i])
			puts(B[i].name);
}
