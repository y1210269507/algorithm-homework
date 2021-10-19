/*
 * @Author: your name
 * @Date: 2021-09-27 20:58:19
 * @LastEditTime: 2021-09-27 21:22:06
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\algorithm\sort\H3\Queue.cpp
 */
#include <iostream>
using namespace std;

void quicksort(int num[], int begin, int end)
{
    if (begin >= end)
    {
        return;
    }
    int temp = num[begin];
    int left = begin;
    int right = end;
    while (left < right)
    {
        while (left < right && num[right] >= temp)
        {
            right--;
        }
        if (left < right)
        {
            num[left] = num[right];
        }
        while (left < right && num[left] <= temp)
        {
            left++;
        }
        if (left < right)
        {
            num[right] = num[left];
        }
    }
    num[left] = temp;
    quicksort(num, begin, left - 1);
    quicksort(num, left + 1, end);
}
int main()
{
    int n;
    cin >> n;
    int *num = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    quicksort(num, 0, n - 1);
    
    int sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum <= num[i])
        {
            count++;
            sum += num[i];
        }
    }
    cout<<count<<endl;
    delete[] num;
    system("pause");
}