/*
 * @Author: your name
 * @Date: 2021-10-30 11:05:41
 * @LastEditTime: 2021-10-30 11:40:16
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\algorithm\Graph\H7\One person's journey.cpp
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1002;
const int MAX = 0x3f3f3f3f;
int dis[N];
int graph[N][N];
int visit[N];
set<int> se;
int maxx = 0;
int cmp(int a, int b)
{
    return a > b ? a : b;
}
void init(int t, int s, int d)
{
    memset(visit, 0, sizeof(visit));
    for (int i = 0; i < N; i++)
    {
        graph[i][i] = 0;
        for (int j = 0; j < i; j++)
        {
            graph[i][j] = MAX;
            graph[j][i] = MAX;
        }
    }
    int x, y, w;
    maxx = 0;
    for (int i = 0; i < t; i++)
    {
        cin >> x >> y >> w;
        maxx = cmp(maxx, cmp(x, y));
        graph[x][y] = w;
        graph[y][x] = w;
    }
    for (int i = 0; i <= maxx; i++)
    {
        dis[i] = graph[0][i];
    }
    int p;
    for (int i = 0; i < s; i++)
    {
        cin >> p;
        dis[p] = 0;
    }
    for (int i = 0; i < d; i++)
    {
        cin >> p;
        se.insert(p);
    }
}
void disj()
{
    int min = MAX;
    int k = 0;
    visit[k] = 1;
    for (int i = 0; i < maxx; i++)
    {
        min = MAX;
        k = 0;
        for (int j = 1; j <= maxx; j++)
        {
            if (!visit[j] && min > dis[j])
            {
                min = dis[j];
                k = j;
            }
        }
        visit[k] = 1;
        for (int j = 1; j <= maxx; j++)
        {
            if (!visit[j] && dis[j] > dis[k] + graph[k][j])
            {
                dis[j] = dis[k] + graph[k][j];
            }
        }
    }
}
int main()
{
    int t, s, d;
    cin >> t >> s >> d;
    init(t, s, d);
    disj();
    int min = MAX;
    // for (int i = 0; i <= maxx; i++)
    // {
    //     cout << dis[i] << endl;
    // }
    for (auto it = se.begin(); it != se.end(); it++)
    {
        if (min > dis[*it])
        {
            min = dis[*it];
        }
    }
    cout << min << endl;
    system("pause");
    return 0;
}
