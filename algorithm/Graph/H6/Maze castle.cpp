/*
 * @Author: your name
 * @Date: 2021-10-22 20:10:22
 * @LastEditTime: 2021-10-22 20:16:44
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\algorithm\Graph\H6\Maze castle.cpp
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;
#define maxn 10000 + 1000

int n, m;
vector<int> G[maxn];
stack<int> S;
int pre[maxn], lowlink[maxn], sccno[maxn], dfs_clock, scc_cnt;

void dfs(int u)
{
    pre[u] = lowlink[u] = ++dfs_clock;
    S.push(u);
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if (!pre[v])
        {
            dfs(v);
            lowlink[u] = min(lowlink[u], lowlink[v]);
        }
        else if (!sccno[v])
        {
            lowlink[u] = min(lowlink[u], pre[v]);
        }
    }
    if (lowlink[u] == pre[u])
    {
        scc_cnt++;
        for (;;)
        {
            int x = S.top();
            S.pop();
            sccno[x] = scc_cnt;
            if (x == u)
                break;
        }
    }
}
void find_scc()
{
    for (int i = 1; i <= n; i++)
        if (!pre[i])
            dfs(i);
}
int check()
{
    int out[maxn] = {0};
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < G[i].size(); j++)
        {
            if (sccno[i] != sccno[G[i][j]])
                out[sccno[i]]++;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= scc_cnt; i++)
        if (out[i] == 0)
            cnt++;
    if (cnt > 1)
        return 0;
    else if (cnt == 0)
        return n;
    else
        for (int i = 1; i <= scc_cnt; i++)
            if (out[i] == 0)
            {
                int ans = 0;
                for (int j = 1; j <= n; j++)
                    if (sccno[j] == i)
                        ans++;
                return ans;
            }
}

int main()
{
    //	freopen("input.in","r",stdin);
    int x, y;
    while (cin >> n >> m && n != 0 && m != 0)
    {
        dfs_clock = scc_cnt = 0;
        while (m--)
        {
            cin >> x >> y;
            G[x].push_back(y);
        }
        find_scc();
        if (scc_cnt == 1)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}