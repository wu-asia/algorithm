#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];

void bubble_sort()
{
	for(int i = 1; i < n; i++)
	{
		int flag = false;
		for(int j = 1; j <= n - i; j++)
		{
			if(a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				flag = true;
			}
		}
		if(!flag) break;
	}
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	bubble_sort();
	for(int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}