#include<iostream>
#include<algorithm>

using namespace std;
const int N = 110;
const int M = 2e4 + 10;
int s, n, m;
//玩家人数s
//城堡数量n
//拥有的士兵数量m
int a[N][N];
int f[N][M];
//f[i][j]表示从第i组中选出
int main()
{
	cin >> s >> n >> m;
	for(int i = 1; i <= s; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			int t;
			cin >> t;
			a[j][i] = t * 2 + 1;
		}
	}
	for(int i = 1; i <= n; i++)
		sort(a[i] + 1, a[i] + s + 1);
	// for(int j = 1; j <= n; j++)
	// {
	// 	for(int i = 1; i <= s; i++)
	// 		cout << a[j][i] << " ";
	// 	cout << endl;
	// }
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			f[i][j] = f[i - 1][j];
			for(int k = 1; k <= s && j >= a[i][k]; k++)
				f[i][j] = max(f[i][j], f[i - 1][j - a[i][k]] + i * k);
		}
	}
	cout << f[n][m] << endl;
	return 0;
}