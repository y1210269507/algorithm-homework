/*
 * @Author: your name
 * @Date: 2021-09-29 14:52:57
 * @LastEditTime: 2021-09-29 15:09:59
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\algorithm\Convex Closure, Heap\E4\Fence Repair.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a,int b){
    return a > b;
}
int main()
{
    int num;
    cin >> num;
    vector<int> v;
    if (num < 1 || num > 20000)
    {
        return 0;
    }
    int sum = 0;
    for (int i = 0; i < num; i++)
    {
        int temp;
        cin >> temp;
        if (temp < 1 || temp > 50000)
        {
            return 0;
        }
        sum += temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), cmp);
    int count = sum;
    for (int i = 0; i < num - 2; i++)
    {
        sum -= v[i];
        count += sum;
    }
    cout << count << endl;
    return 0;
}