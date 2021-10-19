/*
 * @Author: your name
 * @Date: 2021-09-20 15:56:16
 * @LastEditTime: 2021-09-20 16:28:27
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\Windows Message Queue.cpp
 */
#include<iostream>
#include<queue>
using namespace std;

class Message{
    public:
    string m_name;
    int m_num;
    int m_you;
    int m_count;
    Message(string name, int num, int you, int count){
        m_name = name;
        m_num = num;
        m_you = you;
        m_count = count;
    }
};
bool operator < (const Message & m1, const Message &m2){
    if(m1.m_you == m2.m_you){
        return m1.m_count>m2.m_count;
    }
    else{
        return m1.m_you>m2.m_you;
    }
}


int main(){
    string order;
    priority_queue<Message> pq;
    int count = 1;
    while (cin>>order)
    {
        if(order=="GET"){
            if(pq.empty()){
                cout<<"EMPTY QUEUE!"<<endl;
            }
            else{
                cout<<pq.top().m_name<<" "<<pq.top().m_num<<endl;
                pq.pop();
            }
        }
        else{
            int num,you;
            string name;
            cin>>name>>num>>you;
            Message temp(name,num,you,count);
            pq.push(temp);
            count++;
        }
    }
    
    system("pause");
}