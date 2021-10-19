/*
 * @Author: your name
 * @Date: 2021-09-27 21:07:48
 * @LastEditTime: 2021-09-27 22:39:08
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
    bool operator>=(const student &s);
    bool operator<=(const student &s);
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
bool student:: operator>=(const student &s)
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
bool student:: operator<=(const student &s)
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
    int n, t;
    int count = 1;
    while (cin >> n >> t && n != 0)
    {
        vector<student> ss;
        for (int i = 0; i < n; i++)
        {
            string num, name;
            int score;
            cin >> num >> name >> score;
            student s1(num, name, score, t);
            ss.push_back(s1);
        }
        quicksort(ss, 0, n-1);
        cout << "Case " << count << ":" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << ss[i].num << " " << ss[i].name << " " << ss[i].score << endl;
        }
        count++;
    }

    system("pause");
}