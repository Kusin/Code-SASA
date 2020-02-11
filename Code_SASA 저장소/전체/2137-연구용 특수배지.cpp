#include<stdio.h>
int main(){
   int arr[31][31]={};
   int n,m,t,r,c,h,w;
   int i,j,k;
   int cnt=0;
   scanf("%d%d%d",&n,&m,&t);
   for(i=1;i<=t;i++){
   	  scanf("%d%d%d%d",&r,&c,&h,&w);
   	   for(j=r;j<r+h;j++){
   	   	 for(k=c;k<c+w;k++){
   	   	 	    if(arr[j][k]==0)
   	   	 	    arr[j][k]=1;
   	   	 	    else
   	   	 	    arr[j][k]=0;
			   }
		  }
	}
		for(i=1;i<=n;i++)
		 for(j=1;j<=m;j++)
		  if(arr[i][j]==0)
		    cnt++;
	printf("%d",cnt);
		 

}
