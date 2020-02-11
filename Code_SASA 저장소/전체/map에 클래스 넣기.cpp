#include<iostream>
#include<map>        //map
#include<utility>    //make_pair
using namespace std;
class Human
{
private:
    int age;
    int height;
public:
    Human(int _age, int _height) : age(_age), height(_height){}
    bool operator<(const Human& rhs) const    //이게 핵심!
    {
        if (age != rhs.age)
        {
            return age < rhs.age;
        }
 
        return height < rhs.height;
    }
};
 
int main(void)
{
    std::map<Human, int> m;    //map 선언
 
    Human hArr[] = { Human(30, 180), Human(30, 170), Human(30, 160),
                     Human(22, 110), Human(22, 100), Human(42, 168),
                     Human(51, 170) };        //map의 key 값이될 클래스 배열
 
    int num = 0;                            //map의 value가 될 아무값.
    for (Human human : hArr)
    {
        m.insert(make_pair(human, num));    //클래스가 map의 키 값으로 잘 들어가네요?
        num++;
    }
 
    if (m.find(Human(30, 160)) != m.end())    //map의 키값 검색이 잘되네요?
    {
        cout << "map에 Human(30, 160)이 있소." << endl;
    }
    else
    {
        cout << "map에 Human(30, 160)은 없소." << endl;
    }
    return 0;
}

