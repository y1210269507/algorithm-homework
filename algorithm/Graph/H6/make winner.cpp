/*
 * @Author: your name
 * @Date: 2021-10-22 16:17:04
 * @LastEditTime: 2021-10-22 16:50:37
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\algorithm\Graph\H6\make winner.cpp
 */
#include <iostream>
#include <vector>
using namespace std;
int find(vector<string> players, string p)
{
    for (int i = 0; i < players.size(); i++)
    {
        if (players[i] == p)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    vector<string> players;
    vector<int> degree;
    int n;
    while (cin >> n && n != 0)
    {
        string p1, p2;
        for (int i = 0; i < n; i++)
        {
            cin >> p1 >> p2;
            if (find(players, p1) == -1)
            {
                players.push_back(p1);
                degree.push_back(0);
            }
            if (find(players, p2) == -1)
            {
                players.push_back(p2);
                degree.push_back(0);
            }
            degree[find(players, p2)]++;
        }
        int count = 0;
        for (int i = 0; i < degree.size(); i++)
        {
            if (degree[i] == 0)
            {
                count++;
            }
        }
        if (count == 1)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    system("pause");
}