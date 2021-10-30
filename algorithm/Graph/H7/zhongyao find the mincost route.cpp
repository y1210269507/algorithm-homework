/*
 * @Author: your name
 * @Date: 2021-10-28 18:45:26
 * @LastEditTime: 2021-10-28 19:43:07
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\algorithm\Graph\H7\find the mincost route.cpp
 */
#include <iostream>
using namespace std;
const int MAX = 0x3f3f3f3f;
const int N = 102;
const int M = 1002;
int graph[N][N];
int dis[N][N];

void init(int n, int m)
{
    for (int i = 1; i <= n; i++)
    {
        graph[i][i] = 0;
        for (int j = 1; j < i; j++)
        {
            graph[i][j] = MAX;
            graph[j][i] = MAX;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        if (w < graph[x][y])
        {
            graph[x][y] = w;
            graph[y][x] = w;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dis[i][j] = graph[i][j];
        }
    }
}

int MIN(int a, int b)
{
    return a < b ? a : b;
}
void floyd(int n)
{
    int anser = MAX;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i != j && i != k && j != k)
                    anser = MIN(anser, dis[i][j] + graph[j][k] + graph[k][i]);

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = MIN(dis[i][j], dis[i][k] + dis[k][j]);
    }
    if (anser == MAX)
    {
        cout << "It's impossible." << endl;
    }
    else
    {
        cout << anser << endl;
    }
}
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        init(n, m);
        floyd(n);
    }
}