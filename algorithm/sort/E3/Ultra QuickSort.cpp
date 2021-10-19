/*
 * @Author: your name
 * @Date: 2021-09-26 22:05:24
 * @LastEditTime: 2021-09-26 23:28:46
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\algorithm\sort\E3\Ultra QuickSort.cpp
 */
#include <iostream>
using namespace std;

long long count;

void merge_array(int num[], int begin, int middle, int end)
{
    int o = begin, p = middle + 1;
    int l = end - begin + 1;
    int num2[l] = {0};
    int i = 0;
    for (; o <= middle && p <= end; i++)
    {
        if (num[o] <= num[p])
        {
            num2[i] = num[o];
            o++;
        }
        else
        {
            num2[i] = num[p];
            count += p - begin - i;
            p++;
        }
    }
    while (o <= middle)
    {
        num2[i] = num[o];
        i++;
        o++;
    }
    while (p <= end)
    {
        num2[i] = num[p];
        i++;
        p++;
    }
    for (int i = 0; i < end - begin + 1; i++)
    {
        num[begin + i] = num2[i];
    }
}
void merge_sort(int num[], int begin, int end)
{
    if (begin < end)
    {
        int middle = begin + (end - begin) / 2;
        merge_sort(num, begin, middle);
        merge_sort(num, middle + 1, end);
        merge_array(num, begin, middle, end);
    }
}

int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        count = 0;
        int *num = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> num[i];
        }
        merge_sort(num, 0, n - 1);
        cout << count << endl;
        delete[] num;
    }

    system("pause");
}