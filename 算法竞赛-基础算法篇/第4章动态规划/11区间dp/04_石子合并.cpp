#include<iostream>
#include<cstring>

using namespace std;

const int N = 210;
int n;
int sum[N];
int f[N][N], g[N][N];

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> sum[i];
		sum[n + i] = sum[i];
	}
	int m = 2 * n;
	for(int i = 1; i <= m; i++)
	{
		sum[i] += sum[i - 1];
	}

	memset(f, 0x3f, sizeof f);
	memset(g, -0x3f, sizeof g);

	for(int i = 1; i <= m; i++)
	{
		f[i][i] = g[i][i] = 0;
	}

	for(int len = 1; len <= n; len++)
	{
		for(int i = 1; i + len - 1 <= m; i++)
		{
			int j = len + i - 1;
			int t = sum[j] - sum[i - 1];
			for(int k = i; k < j; k++)
			{
				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + t);
				g[i][j] = max(g[i][j], g[i][k] + g[k + 1][j] + t);
			}
		}
	}

	int ret1 = 0x3f3f3f3f, ret2 = -0x3f3f3f3f;
	for(int i = 1; i <= n; i++)
	{
		ret1 = min(ret1, f[i][i + n - 1]);
		ret2 = max(ret2, g[i][i + n - 1]);
	}
	cout << ret1 << endl << ret2 << endl;
	return 0;
}