/*
 * @Author: your name
 * @Date: 2021-09-20 18:26:07
 * @LastEditTime: 2021-09-20 18:34:25
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\stack.cpp
 */
#include <iostream>
using namespace std;

int f(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 2;
    }
    else if (n == 3)
    {
        return 5;
    }
    else
    {
        int temp = 0;
        for (int i = 0; i <= n - 1; i++)
        {
            temp += f(i) * f(n - 1 - i);
        }
        return temp;
    }
}

int main()
{
    int n;
    cin >> n;
    cout << f(n) << endl;
    system("pause");
}