#include<stdio.h>
int H[50010],V[100010]; // H:human, V:virus
int n,m,k,temp;
void meet(int a,int b){
	if(H[a]==H[b]) return;
	if((H[a]==0)||(H[b]==0)){
		if(H[a]==0) V[H[b]]++,H[a]=H[b];
		else V[H[a]]++,H[b]=H[a];
	}
	else if(V[H[a]]==V[H[b]]){
		V[H[a]]--,V[H[b]]--;
		V[++m]+=2;
		H[a]=H[b]=m;
	}
	else{
		int t=V[H[a]]<V[H[b]]?a:b;
		V[H[t]]--;
		V[++m]++;
		H[t]=m;
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d",&temp);
		H[temp]=i;
		V[i]++;
	}
	for(int i=0,a,b;i<k;i++){
		scanf("%d%d",&a,&b);
		meet(a,b);
	}
	int ans=0;
	for(int i=1;i<=m;i++){
		if(V[i]>ans)
			ans=V[i];
	}
	printf("%d",ans);
}
