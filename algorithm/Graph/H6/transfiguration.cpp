/*
 * @Author: your name
 * @Date: 2021-10-22 19:21:00
 * @LastEditTime: 2021-10-22 20:08:40
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \code\algorithm\Graph\H6\transfiguration.cpp
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char str[10000];
int flag, cot, vis[10000];
struct node
{
    char s, e;
} q[20000];
void dfs(int x)
{
    if (q[x].e == 'm')
    {
        flag = 1;
        return;
    }
    for (int i = 0; i < cot; i++)
    {
        if (q[x].e == q[i].s && !vis[i])
        {
            vis[i] = 1;
            dfs(i);
        }
    }
}
int main()
{
    int i, len;
    cot = 0;
    while (scanf("%s", str) != EOF)
    {
        if (strcmp(str, "0") != 0)
        {
            len = strlen(str);
            q[cot].s = str[0];
            q[cot++].e = str[len - 1];
        }
        else
        {
            flag = 0;
            memset(vis, 0, sizeof(vis));
            for (i = 0; i < cot; i++)
            {
                if (q[i].s == 'b')
                {
                    vis[i] = 1;
                    dfs(i);
                }
            }
            if (flag)
                printf("Yes.\n");
            else
                printf("No.\n");
            cot = 0;
        }
    }
    return 0;
}