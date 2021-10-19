/*
 * @Author: your name
 * @Date: 2021-09-29 20:52:41
 * @LastEditTime: 2021-10-18 18:41:11
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \code\algorithm\Convex Closure, Heap\H4\The kth great number.cpp
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    int num;
    int k;
    cin >> num >> k;
    char opt;
    int n;
    for (int i = 0; i < num; i++)
    {
        cin >> opt;
        if (opt == 'I')
        {
            cin >> n;
            v.push_back(n);
        }
        else
        {
            sort(v.begin(), v.end(), greater<int>());
            cout << v[k - 1] << endl;
        }
    }
    system("pause");
}