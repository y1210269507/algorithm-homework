/*
 * @Author: your name
 * @Date: 2021-10-15 16:00:02
 * @LastEditTime: 2021-10-17 18:37:14
 * @LastEditors: Please set LastEditors
 * @Description: 多次比较考虑哈希
 * @FilePath: \code\algorithm\BST Hash\H5\Crazy Search.cpp
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 16000000;
int hashx[N];
int q[150];

int main()
{
    int times;
    cin >> times;
    while (times--)
    {
        int n, nc;
        cin >> n >> nc;
        string s;
        cin >> s;
        int l = s.length();
        memset(hashx, 0, sizeof(N));
        memset(q, 0, sizeof(q));
        int count = 0;
        for (int i = 0; i < l; i++)
        {
            if (!q[s[i]])
            {
                q[s[i]] = count++;
            }
        }
        int t = 0;
        for (int i = 0; i <= l - n; i++)
        {
            int a = 0;
            for (int j = i; j < i + n; j++)
            {
                a = a * nc + q[s[j]];
            }
            if (!hashx[a])
            {
                t++;
                hashx[a] = 1;
            }
        }
        cout << t << endl;
    }

    system("pause");
    return 0;
}