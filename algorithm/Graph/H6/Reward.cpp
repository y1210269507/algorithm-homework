/*
 * @Author: your name
 * @Date: 2021-10-22 17:58:47
 * @LastEditTime: 2021-10-22 19:06:38
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\algorithm\Graph\H6\test.cpp
 */
/*
 * @Author: your name
 * @Date: 2021-10-22 16:56:10
 * @LastEditTime: 2021-10-22 17:56:43
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\algorithm\Graph\H6\Reward.cpp
 */
#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;
const int N = 10001;
vector<int> G[N];
int visit[N];
int salary[N];
int degree[N];
bool flag = false;
int temp = 888;
void make_salary(int n)
{
    stack<int> s;
    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (!degree[i])
            {
                degree[i]--;
                flag = true;
                salary[i] = temp;
                s.push(i);
            }
        }
        temp++;
        while (!s.empty())
        {
            for (int i = 0; i < G[s.top()].size(); i++)
            {
                degree[G[s.top()][i]]--;
            }
            s.pop();
        }
    }
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        memset(salary, 0, sizeof(salary));
        memset(degree, 0, sizeof(degree));
        memset(G, 0, sizeof(G));
        temp = 888;
        flag = false;
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            G[b].push_back(a);
            degree[a]++;
        }
        make_salary(n);

        if (flag)
        {
            int sum = 0;
            for (int i = 1; i <= n; i++)
            {
                sum += salary[i];
            }
            cout << sum << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    system("pause");
}