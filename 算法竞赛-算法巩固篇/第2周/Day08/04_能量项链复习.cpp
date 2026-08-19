#include<iostream>

using namespace std;

int n;
const int N = 210;
int a[N];
int f[N][N];


int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i + n] = a[i];
	}

	for(int len = 3; len <= n + 1; len++)
	{
		for(int i = 1; i + len - 1 <= n + n; i++)
		{
			int j = i + len - 1;
			for(int k = i + 1; k < j; k++)
			{
				f[i][j] = max(f[i][j], f[i][k] + f[k][j] + a[i] * a[k] * a[j]);
			}
		}
	}

	int ret = 0;
	for(int i = 1; i <= n; i++)
	{
		ret = max(ret, f[i][i + n]);
	}
	cout << ret << endl;
	return 0;
}