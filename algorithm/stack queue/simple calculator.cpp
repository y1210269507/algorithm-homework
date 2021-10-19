/*
 * @Author: your name
 * @Date: 2021-09-20 16:56:43
 * @LastEditTime: 2021-09-20 17:46:27
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\simple calculator.cpp
 */
#include <iostream>
#include <stack>
#include <iomanip>
using namespace std;

double operation(double a, double b, char op)
{
    if (op == '+')
    {
        return (double)a + b;
    }
    else if (op == '-')
    {
        return (double)a - b;
    }
    else if (op == '*')
    {
        return (double)a * b;
    }
    else
    {
        return (double)a / b;
    }
}

int main()
{
    int num;
    while (cin >> num)
    {
        stack<double> n;
        stack<char> o;
        char op = getchar();
        if (num == 0 && op == '\n')
        {
            break;
        }
        n.push(num);
        while (cin >> op >> num)
        {
            if (op == '+')
            {
                n.push(num);
                o.push(op);
            }
            else if (op == '-')
            {
                n.push(num);
                o.push(op);
            }
            else if (op == '*')
            {
                double sum = operation(n.top(), num, op);
                n.pop();
                n.push(sum);
            }
            else
            {
                double sum = operation(n.top(), num, op);
                n.pop();
                n.push(sum);
            }
            if (getchar() == '\n')
            {
                while (!o.empty())
                {

                    char opt = o.top();

                    o.pop();
                    double temp1 = n.top();

                    n.pop();
                    double temp2 = n.top();

                    n.pop();
                    n.push(operation(temp2, temp1, opt));
                }
                cout << fixed << setprecision(2) << n.top() << endl;
                break;
            }
        }
    }

    system("pause");
}