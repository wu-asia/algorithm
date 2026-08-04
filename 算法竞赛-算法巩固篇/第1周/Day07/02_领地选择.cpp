#include<iostream>

using namespace std;

typedef long long LL;
const int N = 1e3 + 10;

int n, m, c;

LL a[N][N], f[N][N];
int main()
{
	cin >> n >> m >> c;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			f[i][j] = f[i - 1][j] + f[i][j - 1] + a[i][j] - f[i - 1][j - 1];
		}
	}
	//x1 = 1, y1 = 1, x2 = c, y2 = c;
	LL ret = f[c][c] - f[0][c] - f[c][0] + f[0][0];
	int x = 1, y = 1;
	for(int x1 = 1; x1 <= n; x1++)
	{
		for(int y1 = 1; y1 <= m; y1++)
		{
			int x2 = x1 + c - 1, y2 = y1 + c - 1;
			if(x2 > n || y2 > m) continue;
			LL cmp = f[x2][y2] - f[x1 - 1][y2] - f[x2][y1 - 1] + f[x1 - 1][y1 - 1];
			if(ret < cmp)
				x = x1, y = y1, ret = cmp;
		}
	}
	cout << x << " " << y << endl;
	return 0;
}