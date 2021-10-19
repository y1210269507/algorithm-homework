/*
 * @Author: your name
 * @Date: 2021-10-13 21:05:17
 * @LastEditTime: 2021-10-13 21:11:26
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\algorithm\BST Hash\E5\The kth great number.cpp
 */
#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int num;
    cin >> num;
    char o;
    int n;
    vector<int> v;
    for (int i = 0; i < num; i++)
    {
        cin >> o >> n;
        if (o == 'I')
        {
            v.push_back(n);
        }
        else
        {
            sort(v.begin(), v.end(), cmp);
            cout << v[n - 1] << endl;
        }
    }

    system("pause");
}