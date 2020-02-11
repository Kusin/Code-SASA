#include<stdio.h> //https://leetcode.com/problems/sort-colors/discuss/175056/c-100-0ms-insertion-sort
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
vector<int> v;
char in[1000010];
void init() { fread(in, 1, sizeof(in), stdin); }
void readN(int &r) {
	static char *p = in;
	int b = 1;
	while (*p < 45) p++;
	if (*p == 45) b = -1, p++;
	for (r = *p & 15; *++p & 16; r = r * 10 + (*p & 15));
	r *= b;
}
int main(){
	int n;
	init();readN(n);
	for(int i=0,k;i<n;i++) readN(k),v.push_back(k);
	sort(v.begin(),v.end(),greater<int>());
	for(int i=0;i<n;i++){
		printf("%d ",v[i]);
	}
}
