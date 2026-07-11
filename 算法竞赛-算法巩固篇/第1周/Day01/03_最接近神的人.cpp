#include<iostream>
#include<algorithm>

using namespace std;
const int N = 5e5 + 10;
int a[N];
int n;
int bubble_sort()
{
	int ret = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			if(a[i] > a[j])
			{
				swap(a[i], a[j]);
				ret++;
			}
		}
	}
	return ret;
}
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int ret = bubble_sort();
	cout << ret << endl;
	return 0;
}