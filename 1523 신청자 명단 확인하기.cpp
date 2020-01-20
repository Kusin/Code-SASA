#include<stdio.h>
int n,m;
char Sj[60];
struct Student{
	char a[60];
	int ord;
}S[110];
int len(char a[]){
	int l=0;
	for(;a[l];l++);
	return l;
}
int main(){
	scanf("%d%d",&n,&m);
	int ans1=-1; 
	char ans2='X';
	for(int i=0;i<n;i++){
		scanf("%s",S[i].a);
		S[i].ord=i+1;
	}
	scanf("%s",Sj);
	int l=len(Sj);
	for(int i=0;i<n;i++){
		if(l!=len(S[i].a)) continue;
		bool flag=1;
		for(int j=0;j<l;j++){
			if((Sj[j])!=(S[i].a[j])) {
				flag=0;
				break;
			}
		}
		if(flag){
		ans1=S[i].ord;
		if(ans1<=m) ans2='O';
		break;
		}
	}
	printf("%d %c",ans1,ans2);
}
