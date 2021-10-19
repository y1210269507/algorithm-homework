/*
 * @Author: your name
 * @Date: 2021-10-14 09:08:13
 * @LastEditTime: 2021-10-14 20:50:55
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\algorithm\BST Hash\H5\Simpsons¡¯ Hidden Talents.cpp
 */
#include <bits/stdc++.h>
using namespace std;

void get_next(const string &s, int next[])
{
    int l = s.length();
    int i = 0;
    int j = -1;
    next[0] = -1;
    while (i < l)
    {
        if (j == -1 || s[i] == s[j])
        {
            next[++i] = ++j;
        }
        else
        {
            j = next[j];
        }
    }
}
int main()
{
    string s1, s2;
    while (cin >> s1 >> s2)
    {
        int l1 = s1.length();
        int l2 = s2.length();
        string s = s1 + s2;
        int l3 = s.length();
        cout << s[l3] << endl;
        int *next = new int[l3 + 1];
        get_next(s, next);
        while (next[l3] > l1 || next[l3] > l2)
        {
            l3 = next[l3];
        }
        if (l3 == -1 || next[l3] == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            s1 = s1.substr(0, next[l3]);
            cout << s1 << " " << next[l3] << endl;
        }

        delete[] next;
    }

    system("pause");
}