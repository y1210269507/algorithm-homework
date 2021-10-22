/*
 * @Author: your name
 * @Date: 2021-10-22 17:58:47
 * @LastEditTime: 2021-10-22 18:23:41
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \code\algorithm\Graph\H6\test.cpp
 */
#include <stdio.h>
#include <vector>
#include <queue>
const int maxn = 20000 + 10;
using namespace std;
int in[maxn];
vector<int> gra[maxn];
int sum[maxn];

int tou(int n)
{
    int u;
    queue<int> q;
    // 1.找度数为0的点，放入队列
    for (int j = 1; j <= n; j++)
    {
        if (in[j] == 0)
        {
            u = j;
            sum[u] = 888;
            in[j]--; //同时记得对度数为0的点标记，保证不会被重复遍历
            q.push(j);
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (size_t j = 0; j < gra[u].size(); j++)
        {
            int to = gra[u][j];
            in[to]--;
            if (in[to] == 0)
            {
                q.push(to);
                in[to]--;
                //让当前点所指向的点（相邻点）的工资等于自己+1
                sum[to] = sum[u] + 1;
            }
        }
    }
    int s = 0;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] != -1)
            return -1;
        s += sum[i];
    }
    return s;
}

void init(int n)
{
    for (int i = 0; i <= n; i++)
    {
        gra[i].clear();
        in[i] = 0;
    }
}
int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        init(n);
        for (int i = 0; i < m; i++)
        {
            int u, t;
            scanf("%d %d", &u, &t);
            gra[t].push_back(u);
            in[u]++;
        }
        int s = tou(n);
        printf("%d\n", s);
    }
}
