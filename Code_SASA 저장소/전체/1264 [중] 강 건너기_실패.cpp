#include<iostream> //map의 비중이 너무 컸다;-; 장렬하게 TLE  
#include<bitset>
#include<map>
#define INF 2e9
using namespace std;
int max(int a,int b){
	return a>b?a:b;
}
int n,arr[1010],ans=INF;
bitset<1010> bit;
map<string,int> s;
map<string,bool> d;
void dfs(int cnt){
	if(cnt>ans) return;
	if(s.count(bit.to_string())>0)
		if(cnt>s[bit.to_string()]) 
			return;
	d[bit.to_string()]=1;
	s[bit.to_string()]=cnt;	
	bool chk=1;
	for(int i=0;i<=n;i++)
		if(!bit[i]){
			chk=0;
			break;
		}
	if(chk){
		if(cnt<ans) 
			ans=cnt;
		return;
	}
	if(bit[0]==0){
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++){
				if(!bit[i]&&!bit[j]){
					bit[i]=1; bit[j]=1; bit[0]=1;
					if(d.count(bit.to_string())==0 || d[bit.to_string()]==0){
						dfs(cnt+max(arr[i],arr[j]));
						d[bit.to_string()]=0;
					}
					bit[i]=0; bit[j]=0; bit[0]=0;
				}
			}
	}else{
		for(int i=1;i<=n;i++){
			if(bit[i]==1){
				bit[i]=0; bit[0]=0;
				if(d.count(bit.to_string())==0 || d[bit.to_string()]==0){
					dfs(cnt+arr[i]);
					d[bit.to_string()]=0;
				}
				bit[i]=1; bit[0]=1;
			}
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",arr+i);
	bit.reset();
	dfs(0);
	printf("%d",ans);
}
