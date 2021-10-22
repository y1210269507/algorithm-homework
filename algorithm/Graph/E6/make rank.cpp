/*
 * @Author: your name
 * @Date: 2021-10-20 19:39:28
 * @LastEditTime: 2021-10-20 21:06:47
 * @LastEditors: Please set LastEditors
 * @Description: 制定排位，输入n个点和m个关系，关系中前者比后者大，
 * 按照顺序输出出来（相同位置时谁的编号小输出谁）
 * @FilePath: \code\algorithm\Graph\E6\make rank.cpp
 */
#include <iostream>
#include <cstring>
using namespace std;
const int N = 501;
int graph[N][N];
int degree[N];
int v[N];

void topsort(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (degree[j] == 0 && v[j] == 0)
            {
                v[j] = 1;
                if (i != n)
                {
                    cout << j << " ";
                }
                else
                {
                    cout << j;
                }
                for (int k = 1; k <= n; k++)
                {
                    if (graph[j][k])
                    {
                        degree[k]--;
                    }
                }
                break;
            }
        }
    }
    cout << endl;
}
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        memset(degree, 0, sizeof(degree));
        memset(graph, 0, sizeof(graph));
        memset(v, 0, sizeof(v));
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            if (!graph[a][b])
            {
                graph[a][b] = 1;
                degree[b]++;
            }
        }
        topsort(n);
    }

    system("pause");
    return 0;
}