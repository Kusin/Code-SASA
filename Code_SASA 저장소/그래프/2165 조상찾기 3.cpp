#include<stdio.h> //���ο���̵��: Ʈ�� ��ü�� �����ϴ� ���� �ƴ϶� ������ ���ͷ� tree[l][o]�� ��������. 
#include<vector>
using namespace std;
int n,d,h,k;
vector<int> tree;
int lvl(int l){
    int sum=0,t=1;
    while(l>1) sum+=t,t*=d,l--;
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
    tree.resize(lvl(h+1)+1); 
    for(int i=0,v,l,o;i<n;i++){
        scanf("%d%d%d",&v,&l,&o);
        tree[lvl(l)+o]=v;
    }
    scanf("%d",&k);
    for(int i=1;i<=lvl(h+1)+1;i++)
        if(tree[i]==k){
            k=i;
            break;
        }
    LA(k);
}
