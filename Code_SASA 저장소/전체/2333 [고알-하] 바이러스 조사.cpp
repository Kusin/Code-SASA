#include<stdio.h>
int H[50010],V[100010]; // H:human, V:virus
int n,m,k,temp,i;
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
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=m;i++){
		scanf("%d",&temp);
		H[temp]=i;
	}
	for(int i=0,a,b;i<k;i++){
		scanf("%d%d",&a,&b);
		meet(a,b);
	}
	int ans=0;
	for(i=1;i<=n;i++)
		V[H[i]]++;
	for(i=1;i<=m;i++)
		if(V[i]>0)
			ans++;
	printf("%d",ans);
}
