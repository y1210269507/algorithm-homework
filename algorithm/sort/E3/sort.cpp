/*
 * @Author: your name
 * @Date: 2021-09-26 20:03:39
 * @LastEditTime: 2021-09-26 21:28:00
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\algorithm\sort\E3\sort.cpp
 */
#include <iostream>
#include <stack>
using namespace std;

const int N = 1002;
int num[N];
int getIndex(int num[], int begin, int end)
{
    int temp = num[begin];
    while (begin < end)
    {
        while (begin < end && temp < num[end])
        {
            end--;
        }
        num[begin] = num[end];
        while (begin < end && temp > num[begin])
        {
            begin++;
        }
    }
    num[begin] = temp;
    return begin;
}
void quicksort(int num[], int begin, int end)
{
    if (begin < end)
    {
        int index = getIndex(num, begin, end);
        quicksort(num, begin, index - 1);
        quicksort(num, index + 1, end);
    }
}

int main()
{
    string s;
    while (cin >> s)
    {
        stack<char> n;
        int count = 0;
        s += "5";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '5')
            {
                int t = 0;
                int quan = 1;
                while (!n.empty())
                {
                    t += quan * (n.top() - '0');
                    quan *= 10;
                    n.pop();
                }
                if (s[i - 1] != '5')
                {
                    num[count] = t;
                    count++;
                }
            }
            else
            {
                n.push(s[i]);
            }
        }
        quicksort(num, 0, count - 1);
        for (int i = 0; i < count; i++)
        {
            cout << num[i] << " ";
        }
        cout << endl;
    }

    system("pause");
}