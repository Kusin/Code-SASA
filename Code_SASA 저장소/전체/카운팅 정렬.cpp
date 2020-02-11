#include<iostream>
int n,arr[1000010],mx;
inline void R(int&k){
    char now=getchar_unlocked();
    int sum=0;
    while(now<=32) now=getchar_unlocked();
    while(now>=48){
        sum=sum*10+now-48;
        now=getchar_unlocked();
    }
    k=sum;
} 
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
    R(n); 
    for(int i=0,k;i<n;i++){
        R(k);
        arr[k]++;
        if(mx<k) mx=k;
    }
    for(int i=1;i<=mx;i++){
        for(int j=0;j<arr[i];j++)
           cout<<i<<'\n';
    }
}
