/*
 * @Author: your name
 * @Date: 2021-10-28 14:03:10
 * @LastEditTime: 2021-10-28 14:07:45
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\algorithm\Graph\H7\Constructing Roads.cpp
 */
#include <iostream>
#include <deque>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 101;
int visit[N];
int p[N];
class Edge
{
public:
    int b, e; // b是起始节点，e是终止节点
    int w;    // w是权值
    Edge(int b, int e, int w) : b(b), e(e), w(w){};
    bool operator<(Edge t)
    {
        return this->w < t.w;
    }
};
void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
    }
}

int find(int x)
{
    while (p[x] != x)
    {
        x = p[x];
    }

    return p[x];
}

bool merge(int x, int y)
{
    int t1 = find(x);
    int t2 = find(y);
    if (t1 == t2)
    {
        return false;
    }
    else
    {
        p[t2] = t1;
        return true;
    }
}
int main()
{
    int n, m;
    while (cin >> n)
    {
        init(n);
        deque<Edge> v;
        int num_edge = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int w;
                cin >> w;
                if (j >= i + 1)
                {
                    Edge ne(i, j, w);
                    v.push_back(ne);
                }
            }
        }
        cin >> m;
        int x, y;
        while (m--)
        {
            cin >> x >> y;
            int t1 = find(x - 1);
            int t2 = find(y - 1);
            if (t1 != t2)
            {
                p[t2] = t1;
            }
        }
        sort(v.begin(), v.end());
        int sum = 0;
        int num = v.size();
        for (int i = 0; i < num; i++)
        {
            Edge temp = v.front();
            if (merge(temp.b, temp.e))
            {
                sum += temp.w;
                num_edge++;
            }
            if (num_edge == n - 1)
            {
                break;
            }
            v.pop_front();
        }
        cout << sum << endl;
    }

    system("pause");
}