#include<iostream>
#include<cstring>

using namespace std;
const int N = 1e3 + 10;

int n, m;
int a[N];
int f[N][N];
//f[i][j]表示的是从[1, i]中挑选出价值恰好为j的菜品的方案数
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	//memset(f, -0x3f, sizeof f);
	f[0][0] = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= m; j++)
		{
			f[i][j] = f[i - 1][j];
			if(j >= a[i])
				f[i][j] += f[i - 1][j - a[i]];
		}
	}

	cout << f[n][m] << endl;
	return 0;
}