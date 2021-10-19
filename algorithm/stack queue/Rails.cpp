/*
 * @Author: your name
 * @Date: 2021-09-18 20:14:07
 * @LastEditTime: 2021-09-18 21:55:37
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\Rails.cpp
 */
#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

#define CLR(x, y) (memset(x, y, sizeof(x)))
#define MAXN (1000 + 5)
int a[MAXN];

int main()
{
    int n;
    while (scanf("%d", &n) == 1 && n)
    {
        CLR(a, 0);
        while (scanf("%d", &a[1]) == 1 && a[1])
        {
            for (int i = 2; i <= n; i++)
                scanf("%d", &a[i]);
            stack<int> s;
            int A = 1, B = 1;
            bool flag = true;
            while (B <= n)
            {
                if (A == a[B])
                {
                    A++;
                    B++;
                }
                else if (!s.empty() && s.top() == a[B])
                {
                    s.pop();
                    B++;
                }
                else if (A <= n)
                {
                    s.push(A);
                    A++;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                printf("Yes\n");
            else
                printf("No\n");
        }
        printf("\n");
    }

    //fclose(stdout);
    //fclose(stdin);
    return 0;
}
