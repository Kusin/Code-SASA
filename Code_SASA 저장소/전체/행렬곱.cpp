#include<stdio.h>
#include<vector>
using namespace std;
typedef vector<vector<int> > matrix;
matrix operator *(const matrix &a,const matrix &b){
	int r=a.size(),c=b[0].size(),m=a[0].size(); //a[0].size()==b.size()
	matrix X(r,vector<int>(c)); //기본값 0으로 초기화  
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			for(int k=0;k<m;k++)
				X[i][j]+=a[i][k]*b[k][j];
	return X; 
}
void print(const matrix &a){
	int c=a[0].size();
	for(int i=0;i<a.size();i++,puts("")){
		for(int j=0;j<c;j++)
			printf("%d ",a[i][j]);
	}
}
void scan(matrix &a){
	int r,c;
	scanf("%d%d",&r,&c);
	a.resize(r,vector<int>(c));
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			scanf("%d",&a[i][j]);
	return;
}
int main(){
	matrix a,b;
	scan(a);
	scan(b);
	if(a[0].size()!=b.size()) 
		printf("Undefined");
	else{
		matrix c=a*b;
		print(c);
	}
	return 0;
}
