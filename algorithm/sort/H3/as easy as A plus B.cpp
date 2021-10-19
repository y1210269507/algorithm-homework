/*
 * @Author: your name
 * @Date: 2021-09-27 19:36:00
 * @LastEditTime: 2021-09-27 19:40:18
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\algorithm\sort\H3\as easy as A plus B.cpp
 */
#include <iostream>
#include <algorithm>
using namespace std;

void sortnum(int num[], int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (num[j] > num[j + 1])
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
    cin>>n;
    while (n--)
    {
        int p;
        cin>>p;
        int * num = new int[p];
        for (int i = 0; i < p; i++)
        {
            cin>>num[i];
        }
        sortnum(num, p);
        cout << num[0] << " ";
        for (int i = 1; i < p; i++)
        {
            if (num[i] == num[i - 1])
            {
                continue;
            }
            cout << num[i] << " ";
        }
        cout << endl;
        delete [] num;
    }

    system("pause");
}