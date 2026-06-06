#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 110;
int n, m;
int f[N][N];
//未优化前的数组f[k][i][j]表示从[1, k]这些点中，得出从i到ji的最短路径
//1.不选择k
//f[k][i][j] = f[k - 1][i][j];
//2.选择k
//i -> ... k -> j
//从i到k的最小距离加上k到j的最短距离
//f[k][i][j] = f[k - 1][i][k] + f[k - 1][k][j];


int main()
{
	cin >> n >> m;
	memset(f, 0x3f, sizeof f);
	for(int i = 1; i <= n; i++)
		f[i][i] = 0;
	for(int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		f[u][v] = f[v][u] = min(f[u][v], w);
	}

	for(int k = 1; k <= n; k++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
			cout << f[i][j] << " ";
		cout << endl;
	}
	return 0;
}