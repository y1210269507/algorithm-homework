/*
 * @Author: your name
 * @Date: 2021-10-14 22:12:11
 * @LastEditTime: 2021-10-14 22:42:09
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\algorithm\BST Hash\H5\Magical Forest.cpp
 */
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int x, y, w;
    Node(int x, int y, int w = 0) : x(x), y(y), w(w){};
};

int main()
{
    int time;
    cin >> time;
    for (int i = 1; i <= time; i++)
    {
        cout << "Case #1:" << endl;
        int xl, yl;
        vector<Node> v;
        cin >> xl >> yl;
        int num;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            int x, y, w;
            cin >> x >> y >> w;
            Node temp(x, y, w);
            v.push_back(temp);
        }
        cin >> num;
        while (num--)
        {
            int x, y, w;
            cin >> x >> y >> w;
            if (x == 3)
            {
                int j = 0;
                for (j = 0; j < v.size(); j++)
                {
                    if (v[j].x == y && v[j].y == w)
                    {
                        cout << v[j].w << endl;
                        break;
                    }
                }
                if (j == v.size())
                {
                    cout << 0 << endl;
                }
            }
            else if (x == 1)
            {
                int j = 0;
                for (j = 0; j < v.size(); j++)
                {
                    if (v[j].x == y || v[j].x == w)
                    {
                        int a = v[j].x == y ? w : y;
                        v[j].x = a;
                    }
                }
            }
            else if (x == 2)
            {
                int j = 0;
                for (j = 0; j < v.size(); j++)
                {
                    if (v[j].y == y || v[j].y == w)
                    {
                        int a = v[j].y == y ? w : y;
                        v[j].y = a;
                    }
                }
            }
        }
    }

    system("pause");
    return 0;
}
