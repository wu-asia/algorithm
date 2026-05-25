#include<iostream>
#include<cstring>

using namespace std;

int n, m, x, y;
const int N = 30;
int dx[] = {1, 2, 2, 1, -2, -1, -1, -2};
int dy[] = {2, 1, -1, -2, 1, 2, -2, -1};
int f[N][N], st[N][N];
int main()
{
	cin >> n >> m >> x >> y;
	n++, m++, x++, y++;
	memset(f, 0, sizeof f);
	memset(st, 0, sizeof st);
	st[x][y] = -1;
	for(int k = 0; k < 8; k++)
	{
		int a = x + dx[k], b = y + dy[k];
		if(a >= 1 && a <= n && b >= 1 && b <= m)
		{
			st[a][b] = -1;
		}
	}
	f[0][1] = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(st[i][j] == -1) continue;
			f[i][j] = f[i - 1][j] + f[i][j - 1];
		}
	}
	cout << f[n][m] << endl;
	return 0;
}