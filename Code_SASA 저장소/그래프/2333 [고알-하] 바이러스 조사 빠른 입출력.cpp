#include<stdio.h>
int H[50010],V[100010]; // H:human, V:virus
int n,m,k,temp,i,ans;
int readInt()
{
	int sum = 0;
	char now = getchar_unlocked();

	while (now <'0'||now>'9') now = getchar_unlocked();
	while (now >= '0' && now<='9')
	{
		sum = sum * 10 + now - 48;
		now = getchar_unlocked();
	}

	return sum;
}
void meet(int a,int b){
	if(H[a]==H[b]) return;
	if((H[a]==0)||(H[b]==0)){
		if(H[a]==0) H[a]=H[b];
		else H[b]=H[a];
	}
	else{
		m++; H[a]=H[b]=m;
	}
}
int main(){
	n=readInt();
	m=readInt();
	k=readInt(); 
	for(i=1;i<=m;i++){
		temp=readInt();
		H[temp]=i;
	}
	for(int i=0,a,b;i<k;i++){
		a=readInt(); b=readInt();
		meet(a,b);
	}
	for(i=1;i<=n;i++)
		V[H[i]]++;
	for(i=1;i<=m;i++)
		if(V[i]>0) ans++;
	printf("%d",ans);
}
