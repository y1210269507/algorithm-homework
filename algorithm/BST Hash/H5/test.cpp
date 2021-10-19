/*
 * @Author: your name
 * @Date: 2021-10-15 16:29:16
 * @LastEditTime: 2021-10-18 18:18:06
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\algorithm\BST Hash\H5\Long Long Message.cpp
 */
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int N = 1000002;
int sa[N];  //sa数组
int rk[N];  //排位数组
int rk2[N]; //排位数组的替代
int ht[N];  //高度数组
int k = 0;  //倍增指针
int n = 0;  //字符串长度

bool cmp(int i, int j) //倍增比较
{
    if (rk[i] != rk[j])
    {
        return rk[i] < rk[j]; //前一半
    }
    else
    {
        int ri = (i + k < n ? rk[i + k] : -1);
        int rj = (j + k < n ? rk[j + k] : -1);
        return ri < rj;
    }
}
void getsa(const string &s) //sa数组
{
    for (int i = 0; i < n; i++) //初始化
    {
        sa[i] = i;
        rk[i] = s[i];
    }
    for (k = 1; k < n; k *= 2) //倍增
    {
        sort(sa, sa + n, cmp);
        rk2[sa[0]] = 0;
        for (int i = 1; i < n; i++)
        {
            //按照排序来重置rk值
            rk2[sa[i]] = rk2[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
        }
        for (int i = 0; i < n; i++)
        {
            rk[i] = rk2[i];
        }
    }
}

void getht(const string &s) //ht数组
{
    int h = 0;
    ht[0] = 0;
    for (int i = 0; i < n; i++)
    {
        if (rk[i] == 0)
        {
            continue;
        }
        int j = sa[rk[i] - 1]; //前一个排位的起始
        if (h > 0)
        {
            h--;
        }
        for (; i + h < n && j + h < n; h++)
        {
            if (s[i + h] != s[j + h])
            {
                break;
            }
        }
        ht[rk[i]] = h;
    }
}

int main()
{
    string s1, s2, s;
    cin >> s1 >> s2;
    int l1 = s1.length();
    int l2 = s2.length();
    int len = 0;
    s = s1 + "~" + s2;
    n = s.length();
    getsa(s);
    getht(s);
    int maxl = 0;

    for (int i = 1; i < n; i++)
    {
        if (ht[i] > maxl)
        {
            int a = sa[i - 1];
            int b = sa[i];
            if (a >= 0 && a < l1 && b > l1)
            {
                if (ht[i] > maxl)
                    maxl = ht[i];
            }
            else if (b >= 0 && b < l1 && a > l1)
            {
                if (ht[i] > maxl)
                    maxl = ht[i];
            }
        }
    }
    cout << maxl << endl;
    system("pause");
}
