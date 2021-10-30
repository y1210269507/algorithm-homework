/*
 * @Author: your name
 * @Date: 2021-10-28 20:55:42
 * @LastEditTime: 2021-10-28 20:55:42
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\algorithm\Graph\H7\XYZZY.cpp
 */
#include <bits/stdc++.h>
using namespace std;
const int minn = -0x3f3f3f3f;
int MAP[111][111], dis[111], vis[111], num[111];
int n, k, x, energy;
void Init()
{
    for (int i = 1; i <= n; i++)
    {
        dis[i] = minn;
        vis[i] = 0;
        num[i] = 0;
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                MAP[i][j] = 0;
            else
                MAP[i][j] = minn;
        }
    }
}
int SPFA(int s)
{
    dis[s] = 100;
    queue<int> que;
    que.push(s);
    num[s] = 1;
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        vis[u] = 0;
        if (num[u] == n + 2) //���ӻᳬʱ����
            continue;
        if (num[u] == n + 1) //ע�����Ｔʹ������Ҳ����ֱ��return1 ����Ϊ�п��ܲ�����ͨͼ��
            dis[u] = 100000;
        if (dis[n] > 0) //�����յ����return 1
            return 1;
        for (int v = 1; v <= n; v++)
        {
            if (dis[v] < dis[u] + MAP[u][v] && dis[u] + MAP[u][v] > 0) //�·������ʽ�ı䷽�򼴿ɣ�ע������ò�һ��Ҫ��֤Ѫ������0��ʣ�µľ��ǳ��������
            {
                dis[v] = dis[u] + MAP[u][v];
                if (vis[v])
                    continue;
                vis[v] = 1;
                que.push(v);
                num[v]++;
            }
        }
    }
    return 0;
}
int main()
{
    while (cin >> n && n != -1)
    {
        Init();
        for (int i = 1; i <= n; i++) //�����뽨ͼ
        {
            cin >> energy >> k;
            for (int j = 1; j <= k; j++)
            {
                cin >> x;
                MAP[i][x] = energy;
            }
        }
        int x = SPFA(1);
        if (x)
            cout << "winnable" << endl;
        else
            cout << "hopeless" << endl;
    }
    return 0;
}