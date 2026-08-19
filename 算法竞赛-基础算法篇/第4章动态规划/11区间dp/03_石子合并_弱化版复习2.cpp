#include<iostream>
#include<cstring>

using namespace std;

const int N = 310;
int a[N];
int f[N][N];
int sum[N];
int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum[i] = a[i] + sum[i - 1];
	}

	memset(f, 0x3f, sizeof f);
	for(int i = 1; i <= n; i++) f[i][i] = 0;
	for(int len = 1; len <= n; len ++)
	{
		for(int i = 1; i + len - 1 <= n; i++)
		{
			int j = i + len - 1;
			int d = sum[j] - sum[i - 1];
			for(int k = i; k < j; k++)
			{
				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + d);
			}
		}
	}
	cout << f[1][n] << endl;
	return 0;
}