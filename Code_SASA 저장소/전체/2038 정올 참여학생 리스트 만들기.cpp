#include<stdio.h>
#include<stdlib.h>
struct node{
	int num;
	char name[20];
	node *next;
	node(): next(NULL) {} 
};
node *head=NULL;

void insert_node(node p){
	node *tmp,*pre=NULL;
	node *n=(node*)malloc(sizeof(node));
	*n=p;
	for(tmp=head;tmp!=NULL && tmp->num<=p.num;pre=tmp,tmp=tmp->next);
	if(tmp) n->next =tmp;
	if(pre) pre->next=n;
	else head = n;
}
void delete_node(node p){
	node *tmp,*pre=NULL;
	for(tmp=head;tmp!=NULL&&tmp->num<p.num;pre=tmp,tmp=tmp->next);
	if(tmp!=NULL&&tmp->num==p.num){
		if(pre) pre->next=tmp->next;
		else head=tmp->next;
		free(tmp);
	}
}
void print(int k){
	node*p=head;
	for(int a=1;p!=NULL;p=p->next,a=a+1){
		if(a==k){
			printf("%d %s\n",p->num,p->name);
			break;
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		node x;
		char chk;
		scanf(" %c %d %s",&chk,&x.num,x.name);
		if(chk=='I'){
			insert_node(x);
		}
		else if(chk=='D'){
			delete_node(x);
		}
	}
	for(int i=0;i<5;i++){
		int k;
		scanf("%d",&k);
		print(k);
	}
}
