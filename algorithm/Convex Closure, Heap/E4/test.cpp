/*
 * @Author: your name
 * @Date: 2021-09-29 17:12:23
 * @LastEditTime: 2021-09-29 20:14:50
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \code\algorithm\Convex Closure, Heap\E4\test.cpp
 */
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    priority_queue<int,vector<int>,greater<int>> heap;
    
    while(getline(cin,s) && s != "END"){
        int cnt = 1,len = 0;
        sort(s.begin(),s.end());
        for(int i = 1;i < s.size();i ++){
            if(s[i] != s[i - 1]){
               heap.push(cnt);
               cnt = 1;
            }
            else cnt ++;
        }
        
        heap.push(cnt);
        while (heap.size() > 1){
            int a = heap.top();heap.pop();
            int b = heap.top();heap.pop();
            heap.push(a + b);
            len += (a + b);
        }
        heap.pop();
        
        double res = (double)s.size() * 8 / len;
        cout << s.size() * 8 << " " << len << " ";
        printf("%.1lf\n",res);
    }
    return 0;
}
