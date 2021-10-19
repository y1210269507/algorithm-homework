/*
 * @Author: your name
 * @Date: 2021-09-27 21:07:48
 * @LastEditTime: 2021-09-27 22:33:32
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\algorithm\sort\H3\test.cpp
 */
#include <iostream>
#include <vector>
using namespace std;

class student
{
public:
    string num;
    string name;
    int score;
    student(string num, string name, int score, int w);
    ~student();
    int w;
    operator>=(const student &s);
    operator<=(const student &s);
};

student::student(string num, string name, int score, int w)
{
    this->num = num;
    this->name = name;
    this->score = score;
    this->w = w;
}

student::~student()
{
}
student::operator>=(const student &s)
{
    if (w == 1)
    {
        return this->num >= s.num;
    }
    else if (w == 2)
    {
        if (this->name == s.name)
        {
            return this->num > s.num;
        }
        
        return this->name > s.name;
    }
    else
    {
        if (this->score == s.score)
        {
            return this->num > s.num;
        }
        
        return this->score > s.score;
    }
}
student::operator<=(const student &s)
{
    if (w == 1)
    {
        return this->num <= s.num;
    }
    else if (w == 2)
    {
        if (this->name == s.name)
        {
            return this->num < s.num;
        }
        
        return this->name < s.name;
    }
    else
    {
        if (this->score == s.score)
        {
            return this->num < s.num;
        }
        
        return this->score < s.score;
    }
}
void quicksort(vector<student> &num, int begin, int end)
{
    if (begin >= end)
    {
        return;
    }
    student temp = num[begin];
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
    vector<student> ss;
    student s1("000007", "James", 85, 3);
    student s2("000010", "Amy", 90, 3);
    student s3("000001", "Zoe", 60, 3);
    student s4("000002", "James", 90, 3);
    ss.push_back(s1);
    ss.push_back(s2);
    ss.push_back(s3);
    ss.push_back(s4);
    quicksort(ss, 0, 3);
    for (int i = 0; i < 4; i++)
    {
        cout << ss[i].num << " " << ss[i].name << " " << ss[i].score << endl;
    }
    system("pause");
}