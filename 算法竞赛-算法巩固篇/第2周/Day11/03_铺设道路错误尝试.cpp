#include<iostream>

using namespace std;

const int N = 1e5 + 10;
int d[N], a[N];
int n;

int calc(int left, int right)
{
	int ret = a[1];
	int flag = 1;
	for(int i = left + 1; i <= right - 1; i++)
	{
		if(ret > a[i])
		{
			flag = i;
			ret = a[i];
		}	
	}
	return flag;
}
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> d[i];
		f[i] = d[i] - d[i - 1];
	}
	int l = 0, r = n + 1;
	while(1)
	{
		for(int i = l; i <= r; i++)
		{

		}
	}

	return 0;
}