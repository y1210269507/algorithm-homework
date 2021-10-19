/*
 * @Author: your name
 * @Date: 2021-09-20 16:30:04
 * @LastEditTime: 2021-09-20 16:50:22
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\Scaena Felix.cpp
 */
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int num;
    cin >> num;
    while (num--)
    {
        stack<char> p;
        string s;
        cin >> s;
        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                p.push(s[i]);
            }
            else
            {
                if (!p.empty() && p.top() == '(')
                {
                    p.pop();
                    count++;
                }
                else
                {
                    p.push(s[i]);
                }
            }
        }
        cout << count << endl;
    }

    system("pause");
}