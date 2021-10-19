/*
 * @Author: your name
 * @Date: 2021-09-23 19:49:04
 * @LastEditTime: 2021-09-23 21:46:33
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\Test\test.cpp
 */
#include <iostream>
using namespace std;
int isAsciiDigit(int x)
{
    int test1 = (0x55 << 8) | (0x55);
    test1 = (test1 << 16) | (test1);
    x = (x & test1) + ((x >> 1) & test1);
    test1 = (0x33 << 8) | (0x33);
    test1 = (test1 << 16) | (test1);
    x = (x & test1) + ((x >> 2) & test1);
    test1 = (0x0f << 8) | (0x0f);
    test1 = (test1 << 16) | (test1);
    x = (x & test1) + ((x >> 4) & test1);
    test1 = (0xff << 16) | (0xff);
    x = (x & test1) + ((x >> 8) & test1);
    test1 = (0xff << 8) | (0xff);
    x = (x & test1) + ((x >> 16) & test1);
    return x;
}
int main()
{
}