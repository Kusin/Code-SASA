#include<cstdio>
int w,h,p,q,t;main(){scanf("%d%d%d%d%d",&w,&h,&p,&q,&t);printf("%d %d",(p+=t)/w%2?w-p%w:p%w,(q+=t)/h%2?h-q%h:q%h);}
