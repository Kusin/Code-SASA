#include<iostream>
#include<map>
#include<vector>
#include<sstream> //sstream (문자열 파싱) 
#include<string> //string의 모든 것, stoi, atoi 
#include<algorithm> //reverse
using namespace std;
typedef struct{
    string str1;
    string str2;
}DS;
map<string,int> d;
vector<DS> eq;
int n,flag,x;
string a,b,p,q;
bool is_digit(const string& str) {
    bool flag=true;
    for(int i=0;i<str.size();i++){
        if(str[i]>='0'&&str[i]<='9')
            continue;
        else{
            flag=false;
            break;
        }
    }
    return flag;
}
void check(){
    for(auto g : eq){
        if(g.str1 == g.str2) continue;
        if(is_digit(g.str1)&&is_digit(g.str2)){
            if(g.str1 != g.str2){
                flag=1;
                break;
            } 
        }
        else if(is_digit(g.str1)&&!is_digit(g.str2)){
            if(d.count(g.str2)>0){
                if(d[g.str2] != stoi(g.str1)){
                    flag=1;
                    break;
                }
            }
            else{
                d[g.str2]=stoi(g.str1);
            }
        }
        else if(is_digit(g.str2)&&!is_digit(g.str1)){
            if(d.count(g.str1)>0){
                if(d[g.str1] != stoi(g.str2)){
                    flag=1;
                    break;
                }
            }
            else{
                d[g.str1]=stoi(g.str2);
            }
        }
        else{
            if(d.count(g.str1)>0 && d.count(g.str2)>0){
                if(d[g.str1] != d[g.str2]){
                    flag=1;
                    break;
                }
            }
            else if(d.count(g.str1)>0){
                d[g.str2]=d[g.str1];
            }
            else if(d.count(g.str2)>0){
                d[g.str1]=d[g.str2];
            }
        }
    }
}
int main(){
    scanf("%d",&n);
    getchar();
    getline(cin,a);
    getline(cin,b);
    stringstream sts1(a);
    stringstream sts2(b);
    while((sts1>>p)&&(sts2>>q)){
        eq.push_back((DS){p,q});
    }
    check();
	reverse(eq.begin(),eq.end());
	x++;
	check(); 
    if(flag) cout<<"NO";
    else cout<<"YES";
}
