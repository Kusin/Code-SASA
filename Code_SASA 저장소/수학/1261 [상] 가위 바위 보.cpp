#include<stdio.h> //������ �ؽ��� �밡�ٸ� ���� �ذ��ߴ�. ����Լ��� �̿��� �� ȿ�������� ������ �� �� ������? 
long long DT[10][10],DT2[10][10],a[6];
int n,m,x,y;
void calc(int k){
	int cnt=0,chk[4]={0,};
	for(int i=1;i<=k;i++){
		if(a[i]) cnt++;
		chk[a[i]]++;
	}
	if(chk[1]&&chk[2]&&chk[3]) DT2[cnt][cnt]++;
	else if(chk[1]&&chk[2]) DT2[cnt][chk[2]]+=(a[1]==2?1:0);
	else if(chk[1]&&chk[3]) DT2[cnt][chk[1]]+=(a[1]==1?1:0);
	else if(chk[2]&&chk[3]) DT2[cnt][chk[3]]+=(a[1]==3?1:0);
	else DT2[cnt][cnt]++;
}
void init(){ //DT2 �� n���̼� ������������ ���� �� �����̸� ������ k���� ��Ƴ��� ����� ��  
	for(a[1]=1;a[1]<=3;a[1]++){
		calc(1);
		for(a[2]=1;a[2]<=3;a[2]++){
			calc(2);
			for(a[3]=1;a[3]<=3;a[3]++){
				calc(3);
				for(a[4]=1;a[4]<=3;a[4]++){
					calc(4);
					for(a[5]=1;a[5]<=3;a[5]++){
						calc(5);
					}
				}
			}
		}
	}
}
long long f(int n,int m){
	if(DT[n][m]) return DT[n][m];
	if(m==1){
		return 3;
	}
	long long sum=0;
	for(int i=n;i>=2;i--)
		sum+=f(i,m-1)*DT2[n][i];
	return sum;
}
int main(){
	scanf("%d%d",&n,&m);
	init();
	printf("%lld",f(n,m));
}
