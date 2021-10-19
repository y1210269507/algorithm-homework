/*
 * @Author: your name
 * @Date: 2021-09-27 18:45:14
 * @LastEditTime: 2021-09-27 19:32:30
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\algorithm\sort\H3\abs_sort.cpp
 */
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 102;
int num[N];
void sortnum(int num[], int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (abs(num[j]) < abs(num[j + 1]))
            {
                int temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        int count = 0;
        int p;
        while (n--)
        {
            cin >> p;
            num[count] = p;
            count++;
        }
        sortnum(num, count);
        cout << num[0] << " ";
        for (int i = 1; i < count; i++)
        {
            if (abs(num[i]) == abs(num[i - 1]))
            {
                continue;
            }
            cout << num[i] << " ";
        }
        cout << endl;
    }

    system("pause");
}