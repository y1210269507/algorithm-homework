/*
 * @Author: your name
 * @Date: 2021-10-28 14:50:31
 * @LastEditTime: 2021-10-28 16:44:26
 * @LastEditors: Please set LastEditors
 * @Description: �ж���С�������Ƿ�Ψһ
 * ʹ��prim�㷨��prim�㷨��ʵ��dijkstra���ƣ�ֻ������prim�а������ĵ㿴����һ��
 * �㼴�ɣ�
 * ���ж��Ƿ�Ψһ���������ǣ����ҵ���̱ߵĵ�ʱ������õ���ͼ���ж����ľ��붼����
 * ��̱�Ȩֵʱ����ͻ���������С��
 * ���磺
 * ͼ���а�����1,2,3��Ŀǰ�õ���̱ߵĵ���6����̱�Ȩֵ��4
 * ����1-6����Ϊ4��2-6����Ϊ4����������ͻ���������С��
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