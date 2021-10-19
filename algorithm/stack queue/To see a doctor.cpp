/*
 * @Author: your name
 * @Date: 2021-09-18 22:18:07
 * @LastEditTime: 2021-09-18 22:45:47
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\To see a doctor.cpp
 */
#include<iostream>
#include<map>
#include<queue>
using namespace std;

class person
{
private:
    
public:
    person(int id,int you);
    ~person();
    int id;
    int you;
};

person::person(int id,int you)
{
    this->id = id;
    this->you = you;
}

person::~person()
{
}

bool operator < (const person &x,const person &y)//���� "<" �������������ȼ�
{
	if(x.you==y.you)//��������ͬʱ��С�������� 
	  return x.id>y.id;
	else
	  return x.you<y.you;//������ͬ�ǴӴ�С���� 
}
int main(){
    int num;
    while (cin>>num)
    {
        int count = 1;//���˱��
        string o;//����
        int numofd;
        priority_queue<person> pm[4];
        while(num--){
            cin>>o;
            if(o=="IN"){
                int you;//ҽ����ţ����ȼ�
                cin>>numofd>>you;
                person p(count,you);
                pm[numofd].push(p);
                count++;

            }
            else{
                cin>>numofd;
                if( !pm[numofd].empty()){
                    person temp = pm[numofd].top();
                    pm[numofd].pop();
                    cout<<temp.id<<endl;
                }
                else{
                    cout<<"EMPTY"<<endl;
                }
            }
        }
    }
    system("pause");
}