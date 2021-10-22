#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int n, m;
int map[501][501], d[501], v[501];
int main()
{
    int x, y;
    int flag;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        memset(v, 0, sizeof(v));
        memset(d, 0, sizeof(d));
        memset(map, 0, sizeof(map));
        while (m--)
        {
            scanf("%d%d", &x, &y);
            // if (!map[x][y])
            // {
            map[x][y] = 1;
            d[y]++;
            //}
        }
        flag = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (v[j] == 0 && d[j] == 0)
                {
                    for (int k = 1; k <= n; k++)
                        if (map[j][k])
                            d[k]--;
                    v[j] = 1;
                    if (flag == 0)
                    {
                        printf("%d", j);
                        flag = 1;
                    }
                    else
                        printf(" %d", j);
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}