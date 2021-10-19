/*
 * @Author: your name
 * @Date: 2021-09-26 21:29:53
 * @LastEditTime: 2021-09-26 21:56:39
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\algorithm\sort\E3\Who's in the Middle.cpp
 */
#include <iostream>
#include<algorithm>
using namespace std;

const int N = 10002;
int num[N]={0};

void quicksort(int array[], int left, int right)
{
    if(left < right)
	{
		int pivot = array[left];
		int low = left, high = right;
		while(low < high)
		{
			while(array[high] >= pivot && low < high)
				high--;
			array[low] = array[high];
			
			while(array[low] <= pivot && low < high)
				low++;
			array[high] = array[low];
		}
		array[low] = pivot;
		
		quicksort(array, left, low - 1);
		quicksort(array, low + 1, right);
	}

}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    quicksort(num,0,n-1);
    
    cout << num[n / 2]<<endl;

    system("pause");
}