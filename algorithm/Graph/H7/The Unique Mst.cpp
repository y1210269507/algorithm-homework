/*
 * @Author: your name
 * @Date: 2021-10-28 14:50:31
 * @LastEditTime: 2021-10-28 16:44:26
 * @LastEditors: Please set LastEditors
 * @Description: 判断最小生成树是否唯一
 * 使用prim算法，prim算法其实和dijkstra类似，只不过在prim中把相连的点看作是一个
 * 点即可；
 * 而判断是否唯一的条件就是，当找到最短边的点时，如果该点与图点中多个点的距离都等于
 * 最短边权值时，这就会产生多个最小树
 * 例如：
 * 图点中包含点1,2,3；目前得到最短边的点是6，最短边权值是4
 * 现在1-6距离为4，2-6距离为4；这种情况就会产生多个最小树
 * @FilePath: \code\algorithm\Graph\H7\The Unique Mst.cpp
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
    int sum = 0;
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
        int x = 0;
        for (int j = 1; j <= n; j++)
        {
            if (visit[j] && graph[k][j] == min)
            {
                x++;
            }
        }
        if (x > 1)
        {
            cout << "Not Unique!" << endl;
            return;
        }
        sum += min;
        visit[k] = 1;
        for (int j = 1; j <= n; j++)
        {
            if (!visit[j] && dis[j] > graph[k][j])
            {
                dis[j] = graph[k][j];
            }
        }
    }
    cout << sum << endl;
}
int main()
{
    int times;
    cin >> times;
    while (times--)
    {
        int n, m;
        cin >> n >> m;
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
            dis[i] = graph[1][i];
        }
        dijkstra(n);
    }
    system("pause");
}