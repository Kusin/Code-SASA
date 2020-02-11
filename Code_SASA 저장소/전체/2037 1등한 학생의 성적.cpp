#include<iostream> //by KU 2020
#include<string>
using namespace std;
int n,mi,ans[3],cnt[3];
typedef struct Student{
	string str1;
	int num[4];
}S;
int main(){
	scanf("%d",&n);
	S stu[110];
	for(int i=1;i<=n;i++){
		cin>>stu[i].str1>>stu[i].num[1]>>stu[i].num[2]>>stu[i].num[3];
		if(stu[i].num[1]>stu[mi].num[1])
			mi=i;
	}
	for(int i=1;i<=2;i++){
		for(int j=1;j<=n;j++){
			if(stu[j].num[i+1]>stu[mi].num[i+1])
				ans[i]++;
			else if(stu[j].num[i+1]==stu[mi].num[i+1])
				cnt[i]++;
		}
	}
	cout<<stu[mi].str1;
	for(int i=1;i<=2;i++){
		ans[i]++;
		if(cnt[i]==1)
			printf(" %d",ans[i]);
		else
			printf(" %d(%d)",ans[i],cnt[i]);
	}
}
