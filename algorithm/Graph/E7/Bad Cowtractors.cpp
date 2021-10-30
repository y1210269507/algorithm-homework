/*
 * @Author: your name
 * @Date: 2021-10-27 22:11:20
 * @LastEditTime: 2021-10-27 23:27:57
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\algorithm\Graph\E7\Bad Cowtractors.cpp
 */
#include <iostream>
#include <list>
#include <set>
using namespace std;

class Edge
{
public:
    int b, e; // b是起始节点，e是终止节点
    int w;    // w是权值
    Edge(int b, int e, int w) : b(b), e(e), w(w){};
    Edge(){};
};

int a, b, c;
int n, m;
const int N = 1001;
const int M = 20001;
list<Edge> v;
set<int> s;

bool cmp(const Edge &e1, const Edge &e2)
{
    return e1.w > e2.w;
}
void init()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {

        cin >> a >> b >> c;
        Edge ne(a, b, c);
        v.push_back(ne);
    }
}

void Prim(int &sum, int &edge_num, Edge temp)
{
    while (edge_num != n - 1)
    {
        for (auto it = v.begin(); it != v.end();)
        {
            temp = *it;
            if (s.find(temp.b) != s.end() && s.find(temp.e) != s.end())
            {
                it = v.erase(it);
                continue;
            }
            else if (s.find(temp.b) == s.end() && s.find(temp.e) == s.end())
            {
                it++;
                continue;
            }
            else
            {
                s.find(temp.b) != s.end() ? s.insert(temp.e) : s.insert(temp.b);
                sum += temp.w;
                v.erase(it);
                break;
            }
        }
        edge_num++;
    }
    cout << sum << endl;
}
int main()
{
    init();
    v.sort(cmp);
    int sum = 0;
    Edge temp = v.front();
    v.pop_front();
    s.insert(temp.b);
    s.insert(temp.e);
    int edge_num = 1;
    sum += temp.w;
    Prim(sum, edge_num, temp);
    system("pause");
    return 0;
}
