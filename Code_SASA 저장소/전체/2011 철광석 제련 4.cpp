#include<stdio.h>
int sum,min=1<<30,map[6][6];
int main(){
	for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++){
			scanf("%d",&map[i][j]);
			sum+=map[i][j];
		}
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++){
			int x=0;
			for(int k=i;k<i+3;k++)
				for(int m=j;m<j+3;m++)
					x+=map[k][m];
			if(x<min)
				min=x;
		}
	printf("%d",sum-min);
}
