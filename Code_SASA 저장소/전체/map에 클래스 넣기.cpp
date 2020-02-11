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
    bool operator<(const Human& rhs) const    //�̰� �ٽ�!
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
    std::map<Human, int> m;    //map ����
 
    Human hArr[] = { Human(30, 180), Human(30, 170), Human(30, 160),
                     Human(22, 110), Human(22, 100), Human(42, 168),
                     Human(51, 170) };        //map�� key ���̵� Ŭ���� �迭
 
    int num = 0;                            //map�� value�� �� �ƹ���.
    for (Human human : hArr)
    {
        m.insert(make_pair(human, num));    //Ŭ������ map�� Ű ������ �� ���׿�?
        num++;
    }
 
    if (m.find(Human(30, 160)) != m.end())    //map�� Ű�� �˻��� �ߵǳ׿�?
    {
        cout << "map�� Human(30, 160)�� �ּ�." << endl;
    }
    else
    {
        cout << "map�� Human(30, 160)�� ����." << endl;
    }
    return 0;
}

