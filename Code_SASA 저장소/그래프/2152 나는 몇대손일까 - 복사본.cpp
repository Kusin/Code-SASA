#include<stdio.h>
int d,n;
char tree[102],ku,cnt;

int main(){
	scanf("%d%d",&d,&n);
	for(int i=1;i<=n;i++)
		scanf(" %c",tree+i);
	scanf(" %c",&ku);
	for(int i=1;i<=n;i++)
		if(tree[i]==ku){
			ku=i;
			break;
		}
	while(ku>0) ku=(ku+d-2)/d,cnt++;
	printf("%d",cnt);
}
