//最值问题时会出现非法值类如-INF和INF
//而方案数则没有
#include<iostream>
using namespace std;

const int MOD = 1e6 + 7;
const int N = 110;

int n, m;
int a[N];
int f[N][N];
//f[i][j]表示的是从[1, i]中选出的种类等于j的方案数
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	f[0][0] = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= m; j++)
		{
			for(int k = 0; k <= a[i]; k++)
				if(j >= k)
					f[i][j] = (f[i][j] + f[i - 1][j - k]) % MOD;
		}
	}
	cout << f[n][m] << endl;
	return 0;
}