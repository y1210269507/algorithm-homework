/*
 * @Author: your name
 * @Date: 2021-10-28 09:34:33
 * @LastEditTime: 2021-10-28 09:34:34
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\algorithm\Graph\E7\test.cpp
 */
/*
 * @Author: your name
 * @Date: 2021-10-27 23:29:37
 * @LastEditTime: 2021-10-27 23:31:07
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\algorithm\Graph\E7\Til the Cows Come Home.cpp
 */
#include <bits/stdc++.h>
using namespace std;

const int Max = 0x3fffffff;
int map[1005][1005];
int dis[1005];
void dijkstra(int n)
{
    int visit[1001] = {0};
    int min, i, j, k;
    visit[1] = 1;
    for (i = 1; i < n; ++i)
    {
        min = Max;
        k = 1;
        for (j = 1; j <= n; ++j)
        {
            if (!visit[j] && min > dis[j])
            {
                min = dis[j];
                k = j;
            }
        }
        visit[k] = 1;
        for (j = 1; j <= n; ++j)
        {
            if (!visit[j] && dis[j] > dis[k] + map[k][j])
                dis[j] = dis[k] + map[k][j];
        }
    }
    cout << dis[n] << endl;
}

int main()
{
    int t, n, i, j, from, to, cost;
    while (cin >> t >> n)
    {
        for (i = 1; i <= n; ++i)
        {
            map[i][i] = 0;
            for (j = 1; j < i; ++j)
                map[i][j] = map[j][i] = Max;
        }
        for (i = 1; i <= t; ++i)
        {
            scanf("%d%d%d", &from, &to, &cost);
            if (cost < map[from][to]) //可能有多条路，只记录最短的
                map[from][to] = map[to][from] = cost;
        }
        for (i = 1; i <= n; ++i)
            dis[i] = map[1][i];
        dijkstra(n);
    }

    system("pause");
    return 0;
}
