/*
 * @Author: your name
 * @Date: 2021-10-27 20:28:36
 * @LastEditTime: 2021-10-28 09:25:57
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\algorithm\Graph\E7\Agri Net.cpp
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
    int b, e; // b����ʼ�ڵ㣬e����ֹ�ڵ�
    int w;    // w��Ȩֵ
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
    int n;
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