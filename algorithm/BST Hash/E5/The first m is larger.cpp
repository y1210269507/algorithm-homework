/*
 * @Author: your name
 * @Date: 2021-10-13 20:41:04
 * @LastEditTime: 2021-10-13 20:59:25
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\algorithm\BST Hash\E5\The first m is larger.cpp
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 4498510;
int num[3002];
int pnum[N];

bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int t, n;
    while (cin >> t >> n)
    {
        for (int i = 0; i < t; i++)
        {
            cin >> num[i];
        }
        int count = 0;
        for (int i = 0; i < t - 1; i++)
        {
            for (int j = i + 1; j < t; j++)
            {
                pnum[count++] = num[i] + num[j];
            }
        }
        sort(pnum, pnum + count, cmp);
        for (int i = 0; i < n; i++)
        {
            cout << pnum[i] << " ";
        }
        cout << endl;
    }

    system("pause");
}