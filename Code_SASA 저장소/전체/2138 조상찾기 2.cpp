#include<stdio.h>
int tree[10000000];
int n,d,h,k;
int lvl(int l){
    int sum=0,t=1;
    while(l>1) sum+=t,t*=d,l--;
    return sum;;
}
int lvl2(int k){
    int sum=0,t=1;
    while(sum<k) sum+=t,t*=d;
    return sum;
}
int par(int k){
    return (k+d-2)/d;
}
void LA(int k){
    while(k>1){
        k=par(k);
        printf("%d ",tree[k]);
    }
}
int main(){
    scanf("%d%d%d",&n,&d,&h);
    for(int i=0,v,l,o;i<n;i++){
        scanf("%d%d%d",&v,&l,&o);
        tree[lvl(l)+o]=v;
    }
    scanf("%d",&k);
    for(int i=1;i<=lvl2(k);i++)
        if(tree[i]==k){
            k=i;
            break;
        }
    LA(k);
}
