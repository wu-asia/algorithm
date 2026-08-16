#include<iostream>

using namespace std;

const int N = 1e5 + 10;
int n;
int a[N];
//f[i]表示长度为i的上升子序列末尾的最小值
//使用的是贪心，
//若想要上升子序列的长度尽可能长，需要末尾的元素的值尽可能小
int f[N], len;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
	{
		//len为零时需要将第一个放入f数组中
		//当a[i]大于f最后一个元素时，可以增加长度
		//f数组是一个单调递增的数组
		if(len == 0 || a[i] > f[len])
			f[++len] = a[i];
		//若不是上述情况，使用的是二分算找到
		else
		{
			int left = 1, right = len;
			while(left < right)
			{
				int mid = (left + right) / 2;
				if(a[i] <= f[mid]) right = mid;
				else left = mid + 1;
			}
			f[left] = a[i];
		}
	}
	cout << len << endl;
	return 0;
}