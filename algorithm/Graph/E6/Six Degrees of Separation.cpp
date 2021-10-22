/*
 * @Author: your name
 * @Date: 2021-10-20 17:11:09
 * @LastEditTime: 2021-10-20 19:32:13
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\algorithm\Graph\E6\test.cpp
 */
#include <iostream>
#include <limits.h> //引入int的无限大
using namespace std;
const int N = 101;
int num[N][N];

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    num[i][j] = 0;
                }
                else
                    num[i][j] = 0x3f3f3f3f;
            }
        }
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            num[a][b] = 1;
            num[b][a] = 1;
        }
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (num[i][j] > num[i][k] + num[k][j])
                    {
                        num[i][j] = num[i][k] + num[k][j];
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (num[i][j] > 7)
                {
                    flag = false;
                }
            }
        }
        if (!flag)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
    system("pause");
    return 0;
}
