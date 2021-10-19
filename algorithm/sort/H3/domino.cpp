/*
 * @Author: your name
 * @Date: 2021-09-27 19:43:20
 * @LastEditTime: 2021-09-27 20:40:30
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\algorithm\sort\H3\domino.cpp
 */
#include <iostream>
#include <algorithm>
using namespace std;

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
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        long long sum = 0;
        sum += n;
        if (n <= k)
        {
            cout << n << endl;
            continue;
        }
        int *num = new int[n - 1];
        for (int i = 0; i < n - 1; i++)
        {
            cin >> num[i];
        }
        quicksort(num,0,n-2);
        for (int i = 0; i < n - k; i++)
        {
            sum += num[i];
        }
        cout << sum << endl;

        delete[] num;
    }
    system("pause");
}