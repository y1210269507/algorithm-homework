/*
 * @Author: your name
 * @Date: 2021-10-28 18:00:27
 * @LastEditTime: 2021-10-28 18:44:32
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\algorithm\Graph\H7\Building a Space Station.cpp
 */
#include <iostream>
#include <deque>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;
const int N = 101;
int visit[N];
int p[N];
class Point
{
public:
    double x, y, z, r;
    int count;
    Point(int count, double x, double y, double z, double r) : count(count), x(x), y(y), z(z), r(r){};
};
class Edge
{
public:
    Point b, e; // b是起始节点，e是终止节点
    double w;   // w是权值
    Edge(Point b, Point e) : b(b), e(e)
    {
        w = sqrt(pow(e.x - b.x, 2) + pow(e.y - b.y, 2) + pow(e.z - b.z, 2));
        if (w <= e.r + b.r)
        {
            w = 0;
        }
        else
        {
            w = w - (e.r + b.r);
        }
    }
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
    while (cin >> n && n != 0)
    {
        init(n);
        deque<Edge> v;
        vector<Point> mp;
        int num_edge = 0;
        int c = 0;
        for (int i = 0; i < n; i++)
        {

            double x, y, z, r;
            cin >> x >> y >> z >> r;
            Point l(c, x, y, z, r);
            mp.push_back(l);
            c++;
        }
        for (int i = 0; i < c - 1; i++)
        {
            for (int j = i + 1; j < c; j++)
            {
                Edge e(mp[i], mp[j]);
                v.push_back(e);
            }
        }
        sort(v.begin(), v.end());
        double sum = 0;
        int num = v.size();
        for (int i = 0; i < num; i++)
        {
            Edge temp = v.front();
            Point p1 = temp.b;
            Point p2 = temp.e;
            if (merge(p1.count, p2.count))
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
        cout << fixed << setprecision(3) << sum << endl;
    }
}