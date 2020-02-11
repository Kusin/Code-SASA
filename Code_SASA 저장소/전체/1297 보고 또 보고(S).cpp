#include<stdio.h>
#include<algorithm>
int n,ans;
struct S{
    int s,e;
}arr[110];
bool cmp(S a,S b){
    if(a.s==b.s) return a.e<b.e;
    return a.s<b.s;
}
void f(int k,int cnt,int pre_s,int pre_e){
    if(k>n-1){
        if(cnt>ans) ans=cnt; 
        return;
    }
    if((pre_s==arr[k].s)||(arr[k].s<pre_e)) f(k+1,cnt,pre_s,pre_e);
    else if(k<n-1 && arr[k+1].e<=arr[k+1].s){
        f(k+1,cnt+1,arr[k].s,arr[k].e);
    }
    else{
        f(k+1,cnt+1,arr[k].s,arr[k].e);
        f(k+1,cnt,pre_s,pre_e);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&arr[i].s,&arr[i].e);
        if(arr[i].s>arr[i].e) arr[i].e=25;
    }
    std::sort(arr,arr+n,cmp);
    f(0,0,-1,-1);
    printf("%d",ans);
}
