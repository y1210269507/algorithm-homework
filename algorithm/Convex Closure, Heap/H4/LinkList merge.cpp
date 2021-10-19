/*
 * @Author: your name
 * @Date: 2021-09-30 08:58:15
 * @LastEditTime: 2021-10-18 18:46:58
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \code\algorithm\Convex Closure, Heap\H4\LinkList merge.cpp
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin >> num;
    while (num--)
    {
        list<int> p1;
        list<int> p2;
        int n1, n2;
        cin >> n1 >> n2;
        int temp;
        for (int i = 0; i < n1; i++)
        {
            cin >> temp;
            p1.push_back(temp);
        }
        for (int i = 0; i < n2; i++)
        {
            cin >> temp;
            p2.push_back(temp);
        }
        p1.sort();
        p2.sort();
        list<int> p3;
        while (!p1.empty() && !p2.empty())
        {
            if (p1.front() <= p2.front())
            {
                p3.push_back(p1.front());
                p1.pop_front();
            }
            else
            {
                p3.push_back(p2.front());
                p2.pop_front();
            }
        }
        while (!p1.empty())
        {
            p3.push_back(p1.front());
            p1.pop_front();
        }
        while (!p2.empty())
        {
            p3.push_back(p2.front());
            p2.pop_front();
        }
        for (auto i = p3.begin(); i != p3.end(); i++)
        {
            cout << *i << " ";
        }
        cout << endl;
    }

    system("pause");
}