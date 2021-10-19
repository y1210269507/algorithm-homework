/*
 * @Author: your name
 * @Date: 2021-09-29 19:57:15
 * @LastEditTime: 2021-09-29 20:36:37
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\algorithm\Convex Closure, Heap\E4\Entropy.cpp
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    priority_queue<int, vector<int>, greater<int>> p;
    while (cin >> s && s != "END")
    {
        int count = 1;
        int l = 0;
        sort(s.begin(), s.end());
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] != s[i - 1])
            {
                p.push(count);
                count = 1;
            }
            else
            {
                count++;
            }
        }
        p.push(count);
        while (p.size() > 1)
        {
            int a = p.top();
            p.pop();
            int b = p.top();
            p.pop();
            p.push(a + b);
            l += a + b;
        }
        p.pop();
        double res = (double)s.length() * 8 / l;
        cout << s.length() * 8 << " " << l << " ";
        cout << fixed << setprecision(1) << res << endl;
    }

    system("pause");
}