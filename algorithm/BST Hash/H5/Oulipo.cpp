/*
 * @Author: your name
 * @Date: 2021-10-14 21:27:33
 * @LastEditTime: 2021-10-14 21:48:21
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\algorithm\BST Hash\H5\Oulipo.cpp
 */
#include <bits/stdc++.h>
using namespace std;

int nex[20001];
void get_next(const string &s)
{
    int l = s.length();
    int begin = -1;
    int end = 0;
    nex[0] = -1;
    while (end < l)
    {
        if (begin == -1 || s[begin] == s[end])
        {
            nex[++end] = ++begin;
        }
        else
        {
            begin = nex[begin];
        }
    }
}

int kmp(const string &s1, const string &s2)
{
    int l1 = s1.length();
    int l2 = s2.length();
    int a = 0, b = 0, count = 0;
    while (a < l1 && b < l2)
    {
        if (s1[a] == s2[b] || b == -1)
        {
            ++a;
            ++b;
        }
        else
        {
            b = nex[b];
        }
        if (b == l2)
        {
            ++count;
            b = nex[b];
        }
    }
    return count;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        get_next(s1);
        cout << kmp(s2, s1) << endl;
    }

    system("pause");
}