#include<stdio.h>
int max=0,map[6][6];
int main(){
	for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++)
			scanf("%d",&map[i][j]);
	for(int i=1;i<=2;i++)
		for(int j=1;j<=2;j++){
			int x=0;
			for(int k=i;k<i+4;k++)
				for(int m=j;m<j+4;m++)
					x+=map[k][m];
			if(x>max)
				max=x;
		}
	printf("%d",max);
}
