#include<stdio.h>  // 1����(��)���� ���� �ѹ� �����ϰ�, �̸� 2����(������)�� ���Ѵٰ� �����Ѵ�. 
int n,m,q,arr[1010][1010];  
int R()
{
	int sum = 0,flag=1;
	char now = getchar_unlocked();

	while (now <= 32) now = getchar_unlocked();
	if(now=='-') {
		flag=-1;
		now = getchar_unlocked();
	}
	while (now >= 48)
	{
		sum = sum * 10 + now - 48;
		now = getchar_unlocked();
	}

	return flag*sum;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0,a,b,c,d,w;i<q;i++){
		a=readInt();
		b=readInt();
		c=readInt();
		d=readInt();
		w=readInt();
		arr[a][b]+=w;
		arr[c+1][b]-=w;
		arr[a][d+1]-=w;
		arr[c+1][d+1]+=w;
	}
	int i,j;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			arr[j][i]+=arr[j-1][i];
	for(i=1;i<=n;i++,puts(""))
		for(j=1;j<=m;j++){
			arr[i][j]+=arr[i][j-1];
			printf("%d ",arr[i][j]);
		}
}
