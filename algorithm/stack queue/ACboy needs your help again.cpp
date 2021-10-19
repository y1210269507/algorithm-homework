/*
 * @Author: your name
 * @Date: 2021-09-18 21:58:15
 * @LastEditTime: 2021-09-23 16:31:50
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\ACboy needs your help again.cpp
 */
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    int num;
    cin >> num; //总次数
    while (num--)
    {
        int n;
        cin >> n; //指令次数
        string o; //输入命令
        cin >> o;
        queue<int> q;
        stack<int> s;
        while (n--)
        {
            string a;
            cin >> a;
            if (a == "IN" && o == "FIFO")
            {
                int temp;
                cin >> temp;
                q.push(temp);
            }
            else if (a == "IN" && o == "FILO")
            {

                int temp;
                cin >> temp;
                s.push(temp);
            }
            else if (a == "OUT" && o == "FIFO")
            {
                if (q.size() != 0)
                    cout << q.front() << endl;
                else
                    cout << "None" << endl;
                q.pop();
            }
            else
            {
                if (s.size() != 0)
                    cout << s.top() << endl;
                else
                    cout << "None" << endl;
                s.pop();
            }
        }
    }
    system("pause");
}