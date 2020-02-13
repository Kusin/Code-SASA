#include<stdio.h>
#include<vector>
#define M 10002
using namespace std;
typedef vector<vector<int> > matrix;
matrix operator *(const matrix &a,const matrix &b){
	int r=a.size(),c=b[0].size(),m=a[0].size(); 
	matrix X(r,vector<int>(c)); //기본값 0으로 초기화  
	for(int i=0;i<r;i++) //행렬곱의 순서를 IKJ로 바꾸어 캐시 속도를 빠르게 한다. 
		for(int k=0;k<m;k++){
			int t=a[i][k]; 
			for(int j=0;j<c;j++){
				X[i][j]+=t*b[k][j];
				X[i][j]%=M;
			}	
		}
	return X; 
}
matrix a[27];
void print(const matrix &a){
	int c=a[0].size();
	for(int i=0;i<a.size();i++,puts("")){
		for(int j=0;j<c;j++)
			printf("%d ",a[i][j]);
	}
}
void scan(){
	char name;
	int r,c;
	scanf(" %c %d %d",&name,&r,&c);
	a[name-'A'].resize(r,vector<int>(c));
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			scanf("%d",&a[name-'A'][i][j]);
}
int main(){
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scan();
	}
	scanf("%d",&m);
	char c;
	scanf(" %c",&c);
	matrix ans(a[c-'A']);
	for(int i=0;i<m-1;i++){
		scanf(" %c",&c);
		ans=ans*(a[c-'A']); 
	}
	print(ans);
	return 0;
}
