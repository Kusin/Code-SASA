#include<stdio.h> //Special Thanks to itsss (°­ÅÂ¿ø)
//https://github.com/itsss/SASA_Programming-II 
int tree[1000010];
void insert_pre(int k){
	int loc=1;
	while(tree[loc]){
		if(k<tree[loc]) loc=loc*2;
		else loc=loc*2+1;	
	}
	tree[loc]=k;
}
void post_traversal(int k){
	if(tree[2*k]) post_traversal(2*k);
	if(tree[2*k+1])post_traversal(2*k+1);
	printf("%d ",tree[k]);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0,k;i<n;i++){
		scanf("%d",&k);
		insert_pre(k);
	}
	post_traversal(1);
}
