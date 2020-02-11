#include<stdio.h> //±×¸®µð  
#include<algorithm>
using namespace std;
int n,m,arr[31][31],can[31],ans[31],id,cnt;
bool chk[31];
int main(){
	scanf("%d%d",&n,&m);
	cnt=n;
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		if(!arr[a][b]) can[a]++,can[b]++;
		arr[a][b]=arr[b][a]=1;
	}
	while(cnt){
		int mx=-1,m_id;
		for(int i=1;i<=n;i++)
			if(can[i]>mx)
				mx=can[i],m_id=i;
		if(mx<=-1) break;
		ans[id++]=m_id; can[m_id]=0;
		chk[m_id]=1; cnt--;
		for(int i=1;i<=n;i++){
			if(arr[m_id][i] && !chk[i]){
				can[i]--; arr[m_id][i]=arr[i][m_id]=0;
				chk[i]=1; cnt--;
			}
		}
	}
	sort(ans,ans+id);
	printf("%d\n",id);
	for(int i=0;i<id;i++) printf("%d ",ans[i]);
} 
