#include<iostream>
#include<cstring>

using namespace std;
const int N = 310;
int a[N];
int sum[N];
int f[N][N];
int n;
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	memset(f, 0x3f, sizeof f);
	for(int i = 0; i <= n; i++)
		f[i][i] = 0;
	for(int len = 2; len <= n; len++)
	{
		for(int i = 1; i + len - 1 <= n; i++)
		{
			int j = i + len - 1;
			int t = sum[j] - sum[i - 1];
			for(int k = i; k < j; k++)
			{
				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + t);
			}
		}
	}
	cout << f[1][n] << endl;
	return 0;
}