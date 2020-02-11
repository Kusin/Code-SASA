// 위에 코드는 Code sasa, 밑에 코드는 백준 6198 옥상 정원 꾸미기 정답 

#include<stdio.h>
#include<stack>
#include<utility>
#include<vector>
using namespace std;
typedef long long int lli;
int n,cnt[80001];
lli k,sum;
int main(){
	scanf("%d",&n);
	vector<pair<lli,int> > v;
	stack<pair<lli,int> > st;
	for(int i=0;i<n;i++){
		scanf("%lld",&k);
		v.push_back(make_pair(k,i));
	}
	for(int i=0;i<n;i++){
		while(!st.empty()&&st.top().first<=v[i].first){
			cnt[st.top().second]=i-st.top().second-1;
			st.pop();
		}
//		sum+=(lli)st.size();
		st.push(v[i]);
	}
	while(!st.empty()){
			cnt[st.top().second]=n-st.top().second-1;
			st.pop();
		}
//	printf("%lld",sum);
	for(int i=0;i<n;i++)
		printf("%d\n",cnt[i]);
}
/*#include<stdio.h>
#include<stack>
#include<vector>
using namespace std;
int n,k;
vector<int> v;
stack<int> st;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&k);
		v.push_back(k);
	}
	long long int cnt=0;
	for(int i=0;i<n;i++){
		while(!st.empty()&&st.top()<=v[i]){
			st.pop();
		}
		cnt+=(long long int)st.size();
		st.push(v[i]);
	}
	printf("%lld",cnt);
}
*/
