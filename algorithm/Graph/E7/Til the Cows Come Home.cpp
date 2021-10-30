/*
 * @Author: your name
 * @Date: 2021-10-27 23:29:37
 * @LastEditTime: 2021-10-28 11:27:26
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\algorithm\Graph\E7\Til the Cows Come Home.cpp
 */
#include <iostream>
using namespace std;
const int MAX = 0x3f3f3f3f;
const int N = 1002;
int graph[N][N];
int dis[N];
int visit[N];
void dijkstra(int n)
{
    int min = MAX;
    int k = 1;
    visit[k] = 1;
    for (int i = 1; i < n; i++)
    {
        min = MAX;
        k = 1;
        for (int j = 1; j <= n; j++)
        {

            if (!visit[j] && min > dis[j])
            {
                min = dis[j];
                k = j;
            }
        }
        visit[k] = 1;
        for (int j = 1; j <= n; j++)
        {
            if (!visit[j] && dis[j] > dis[k] + graph[k][j])
            {
                dis[j] = dis[k] + graph[k][j];
            }
        }
    }
    cout << dis[n] << endl;
}
int main()
{
    int t, n;
    cin >> t >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (i == j)
            {
                graph[i][j] = 0;
            }
            else
            {
                graph[i][j] = MAX;
                graph[j][i] = MAX;
            }
        }
    }
    int x, y, w;
    for (int i = 0; i < t; i++)
    {
        cin >> x >> y >> w;
        if (w < graph[x][y])
        {
            graph[x][y] = w;
            graph[y][x] = w;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = graph[1][i];
    }
    dijkstra(n);

    system("pause");
    return 0;
}
