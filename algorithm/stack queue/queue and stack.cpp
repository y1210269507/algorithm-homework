/*
 * @Author: your name
 * @Date: 2021-09-20 17:47:33
 * @LastEditTime: 2021-09-20 18:12:56
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\queue and stack.cpp
 */
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    int num;
    cin >> num;
    while (num--)
    {
        int num2;
        cin >> num2;
        stack<int> s;
        queue<int> q;
        string opt;
        int opn;
        while (num2--)
        {
            cin >> opt;
            if (opt == "push")
            {
                cin >> opn;
                s.push(opn);
                q.push(opn);
            }
            else
            {
                if (s.empty() || q.empty())
                {
                    cout << "error" << endl;
                    cout << "error" << endl;
                }
                else
                {
                    s.pop();
                    q.pop();
                }
            }
        }
        while (!q.empty())
        {
            cout << q.front();
            q.pop();
            if (!q.empty())
            {
                cout << " ";
            }
            else
            {
                cout << endl;
            }
        }
        stack<int> s1;
        while (!s.empty())
        {
            s1.push(s.top());
            s.pop();
        }
        while (!s1.empty())
        {
            cout << s1.top();
            s1.pop();
            if (!s1.empty())
            {
                cout << " ";
            }
            else
            {
                cout << endl;
            }
        }
    }

    system("pause");
}
