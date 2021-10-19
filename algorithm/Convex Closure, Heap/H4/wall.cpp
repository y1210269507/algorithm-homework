/*
 * @Author: your name
 * @Date: 2021-09-29 21:38:30
 * @LastEditTime: 2021-10-18 18:44:38
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \code\algorithm\Convex Closure, Heap\H4\wall.cpp
 */
#include <iostream>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <cstring>
using namespace std;

const double pi = 3.1415926;
class Point
{
public:
    int x, y;
    Point() {} //一定要加
    Point(int xx, int yy) : x(xx), y(yy) {}
    ~Point() {}
};

Point *vex = new Point[1000];
Point *sta = new Point[1000];
int ccw(const Point &a, const Point &b, const Point &c) //判断是不是逆时针的
{
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

bool findfirst(const Point &p1, const Point &p2) //按照y值来寻找最小点
{
    if (p1.y == p2.y)
    {
        return p1.x < p2.x;
    }
    return p1.y < p2.y;
}
double dis(const Point &p1, const Point &p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}
bool sort_pa(const Point &p1, const Point &p2) //按照极角排序
{
    int t = ccw(vex[0], p1, p2);
    if (t > 0 || (t == 0 && dis(vex[0], p1) - dis(vex[0], p2) <= 0))
    {
        return true;
    }
    return false;
}

int main()
{
    int num, max_d;

    cin >> num >> max_d;
    int xx, yy;
    for (int i = 0; i < num; i++)
    {
        cin >> xx >> yy;
        vex[i].x = xx;
        vex[i].y = yy;
    }
    sort(vex, vex + num, findfirst);
    memset(sta, 0, sizeof(sta));
    sta[0] = vex[0];
    sort(vex + 1, vex + num, sort_pa);
    sta[1] = vex[1];
    int top = 1; //充当栈顶指针
    for (int i = 2; i < num; i++)
    {
        while (i >= 1 && ccw(sta[top - 1], sta[top], vex[i]) < 0)
        {
            top--;
        }
        sta[++top] = vex[i];
    }
    double sum = 0;
    sum += dis(sta[0], sta[top]);
    for (int i = 0; i < top; i++)
    {
        sum += dis(sta[i], sta[i + 1]);
    }
    sum += 2 * pi * max_d;
    cout << round(sum) << endl;

    delete[] vex;
    delete[] sta;
    system("pause");
}