#include<stdio.h>
#include<stdlib.h>
int In[102],Post[102],loc[1000];
typedef struct node{
	node* left;
	node* right;
	int key;
	node() : left(NULL),right(NULL){}
}node; 
node* root;
int cnt;
node* build_Tree(int in_start,int in_end,int po_start,int po_end){
	if(in_start>in_end || po_start >po_end) return NULL;
	int head = Post[po_end];
	node* n=(node*)malloc(sizeof(node*));
	n->key=head;
	int id = loc[head];
	int len = id-in_start;
	n->right=build_Tree(id+1,in_end,po_start+len,po_end-1);
	n->left =build_Tree(in_start,id-1,po_start,po_start+len-1);
	return n;
}
void preorder(node* n){
	if(n==NULL) return;
	printf("%d ",n->key);
	if(n->left) preorder(n->left);
	if(n->right) preorder(n->right);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",In+i),loc[In[i]] =i;
	for(int i=1;i<=n;i++) scanf("%d",Post+i);
	root = build_Tree(1,n,1,n);
	preorder(root);
}
